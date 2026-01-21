/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:56:32 by david             #+#    #+#             */
/*   Updated: 2026/01/21 13:11:07 by david            ###   ########.fr       */
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
		{
			if (ft_strncmp(env[i], "PATH=", 5) == 0)
			{
				*path = ft_strdup(env[i] + 5);
				if (*path == NULL)
					return ;
			}
		}
		if (*path != NULL)
			break ;
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

void	loop(char **search_access, char **env, char **cmd)
{
	char	*tmp;
	int		i;

	i = 0;
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

void	search_in_path(char *path, char **cmd, char **env)
{
	char	**search_access;

	search_access = ft_split(path, ':');
	if (search_access == NULL)
	{
		free_split(cmd);
		perror("search_access :");
		exit(1);
	}
	loop(search_access, env, cmd);
	free_split(search_access);
}

void	check_access(char **av, char **env, char *path, int cmd_index)
{
	char	**cmd;

	cmd = ft_split(av[cmd_index], ' ');
	if (cmd == NULL)
	{
		perror("commandes :");
		exit(1);
	}
	if (ft_strchr(cmd[0], '/') != NULL)
		check_acesso(cmd, env);
	else if (path != NULL)
		search_in_path(path, cmd, env);
	ft_printf("pipex: command not found: %s\n", cmd[0]);
	free_split(cmd);
	exit(1);
}
