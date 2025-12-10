/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:32:55 by david             #+#    #+#             */
/*   Updated: 2025/12/10 23:58:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
	// pid_t	pid;
	// int		status;

	// if (ac > 1)
	// {
	// 	pid = fork();
	// 	if (pid == -1)
	// 		perror("fork :");
	// 	if (pid == 0)
	// 	{
	// 		if (execve(av[1], av + 1, env) == -1)
	// 			perror("fork : ");
	// 		return(1);
	// 	}
	// 	else
	// 		wait(&status);
	// }
	// ft_printf("je suis le pere %d\n", getpid());

	char *path = NULL;
	if (ac == 1)
	{
		search_path(env, &path);
		if(path == NULL)
			perror("PATH :");
		else
			ft_printf("%s\n", path);
	}
	else
		ft_printf("%s", av[1]);
    return (0);
}