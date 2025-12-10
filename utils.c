/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:56:32 by david             #+#    #+#             */
/*   Updated: 2025/12/10 23:58:30 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	search_path(char **env, char **path)
{
    int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P')
			if(ft_strncmp(env[i], "PATH=", 5) == 0)
				*path = env[i];
		if (*path != NULL)
			break;
		i++;
	}
}
