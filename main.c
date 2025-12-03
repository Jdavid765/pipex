/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:32:55 by david             #+#    #+#             */
/*   Updated: 2025/12/03 16:39:17 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	char *cpy = av[0];
	printf("%s\t", cpy);
	if (ac == 1)
	{
		int	id = fork();

		if (id == 0)
		{
			printf("The process child\n");
		}
		else
		{
			printf("The process main\n");
		}
	}
	else
		printf("\n");
	return (0);
}