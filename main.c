/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:32:55 by david             #+#    #+#             */
/*   Updated: 2025/12/21 20:03:42 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_one(char **av, char **env, int *pipefd)
{
	int		infile;
	char	*path;

	path = NULL;
	close(pipefd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
	{
		perror("Fd :");
		exit(1);
	}
	dup2(infile, 0);
	dup2(pipefd[1], 1);
	close(infile);
	close(pipefd[1]);
	search_path(env, &path);
	if (path == NULL)
	{
		perror("PATH :");
		exit(1);
	}
	check_access(av, env, path, 2);
}

static void	child_two(char **av, char **env, int *pipefd)
{
	int		outfile;
	char	*path;

	path = NULL;
	close(pipefd[1]);
	outfile = open(av[4], O_WRONLY | O_CREAT);
	if (outfile == -1)
	{
		perror("Fd :");
		exit(1);
	}
	dup2(pipefd[0], 0);
	dup2(outfile, 1);
	close(pipefd[0]);
	close(outfile);
	search_path(env, &path);
	if (path == NULL)
	{
		perror("PATH :");
		exit(1);
	}
	check_access(av, env, path, 3);
}

int	main(int ac, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];

	if (ac != 5)
	{
		ft_printf("Use: ./pipex infile cmd1 cmd2 outfile\n");
		return (1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("Pipe :");
		exit(1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork :");
		exit(1);
	}
	if (pid1 == 0)
		child_one(av, env, pipefd);
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork :");
		exit(1);
	}
	if (pid2 == 0)
		child_two(av, env, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
