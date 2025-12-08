/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:32:55 by david             #+#    #+#             */
/*   Updated: 2025/12/09 00:52:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(void)
{
    int fd;
	int fd_cpy;
	char buffer[40];

    fd = open("infile", O_RDONLY);
    if (fd == -1)
		return (-1);
	int nb_bytes = read(fd, buffer, 30);
	buffer[nb_bytes] = '\0';
	ft_printf("fd = %d, %s", fd, buffer);
	fd_cpy = dup(fd);
	nb_bytes = read(fd_cpy, buffer, 30);
	buffer[nb_bytes] = '\0';
	ft_printf("fd = %d, %s", fd_cpy ,buffer);
	close (fd);
	close (fd_cpy);
    return (0);
}