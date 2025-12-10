/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:32:55 by david             #+#    #+#             */
/*   Updated: 2025/12/10 21:17:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char *av[], char *env[])
{
	pid_t	pid;

	if (ac > 1)
	{
		pid = fork();
		if (pid == -1)
			perror("fork :");
		if (pid == 0)
		{
			if (execve(av[1], av + 1, env) == -1)
				perror("fork : ");
		}
		else
			ft_printf("Je suis ton pere\n");
	}
    return (0);
}