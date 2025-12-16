/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:32:55 by david             #+#    #+#             */
/*   Updated: 2025/12/14 15:19:47 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
	pid_t	pid;
	int		pipefd[2];
	int		infile;
	char	*path;
	
	path = NULL;
	if (ac > 1)
	{
		if (pipe(pipefd) == -1)
		{
			perror("Pipe :");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork :");
			exit(1);
		}
		else if (pid == 0)
		{
			infile = open(av[1], O_RDONLY);
			if (infile == -1)
			{
				perror("Fd :");
				exit(1);
			}
			dup2(infile, 0);
			search_path(env, &path);
			if(path == NULL)
				perror("PATH :");
			exec(av, env, path);
		}
		else
			wait(NULL);
			
	}
    return(0);
}
