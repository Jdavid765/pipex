/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:33:04 by david             #+#    #+#             */
/*   Updated: 2025/12/16 23:30:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

void	search_path(char **env, char **path);
void	check_access(char **av, char **env, char *path, int cmd_index);
void	exec(char **env, char *pathname, char **cmd);

#endif