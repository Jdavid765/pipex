/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:32:55 by david             #+#    #+#             */
/*   Updated: 2026/01/19 17:36:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(char **av, char **env, int *pipefd)
{
	int		fd;
	char	*path;

	path = NULL;
	close(pipefd[0]);
	fd = open(av[1], O_RDONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Fd :");
		close(fd);
		exit(1);
	}
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(fd);
	close(pipefd[1]);
	search_path(env, &path);
	if (path == NULL)
	{
		ft_printf("Error path not found\n");
		exit(1);
	}
	check_access(av, env, path, 2);
}

void	child_two(char **av, char **env, int *pipefd)
{
	int		fd;
	char	*path;

	path = NULL;
	close(pipefd[1]);
	fd = open(av[4], O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Fd :");
		close(fd);
		exit(1);
	}
	dup2(pipefd[0], 0);
	dup2(fd, 1);
	close(pipefd[0]);
	close(fd);
	search_path(env, &path);
	if (path == NULL)
	{
		ft_printf("Error path not found\n");
		exit(1);
	}
	check_access(av, env, path, 3);
}

void	pipex(char **av, char **env, int *pipefd)
{
	pid_t	pid1;
	pid_t	pid2;

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
}

int	main(int ac, char **av, char **env)
{
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
	pipex(av, env, pipefd);
	return (0);
}
