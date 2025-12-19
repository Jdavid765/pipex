/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:56:32 by david             #+#    #+#             */
/*   Updated: 2025/12/20 00:18:17 by david            ###   ########.fr       */
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
			{
				*path = ft_strdup(env[i]);
				if (*path == NULL)
					return ;
			}
				
		if (*path != NULL)
			break;
		i++;
	}
}

void	exec(char **env, char *pathname, char **cmd)
{
	if (execve(pathname, cmd, env) == -1)
	{
		perror("execve :");
		exit(1);
	}
	
}

void	check_access(char **av, char **env, char *path)
{
	char	**cmd;
	char	**search_access;
	int		i;
	char	*tmp;

	search_access = NULL;
	i = 0;
	cmd = ft_split(av[2], ' ');
	if (cmd == NULL)
	{
		perror("commandes :");
		exit(1);
	}
	search_access = ft_split(path, ':');
	if (search_access == NULL)
	{
		perror("search_access :");
		exit(1);
	}
	while (search_access[i])
	{
		tmp = search_access[i];
		search_access[i] = ft_strjoin(search_access[i], "/");
		free(tmp);
		tmp = search_access[i];
		search_access[i] = ft_strjoin(search_access[i], cmd[0]);
		free(tmp);
		if (access(search_access[i], F_OK | X_OK) == 0)
			exec(env, search_access[i], cmd);
		i++;
	}
}
