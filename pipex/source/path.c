/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:48:00 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/09 19:23:44 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_evnp(char **evnp)
{
	int	i;

	i = 0;
	while (evnp[i])
	{
		if (ft_strncmp(evnp[i], "PATH=", 5) == 0)
		{
			return ((evnp[i] + 5));
		}
		i++;
	}
	return (NULL);
}

char	*make_path(char *dir, char *cmd )
{
	char	*path;

	path = malloc(ft_strlen(dir) + ft_strlen(cmd) + 2);
	if (!path)
	{
		perror("Path allocation faild");
		return (free(path), NULL);
	}
	ft_strcpy(path, dir);
	ft_strcat(path, "/");
	ft_strcat(path, cmd);
	return (path);
}

char	**get_path(char **evnp)
{
	char	*evnp_path;
	char	**path;

	evnp_path = path_evnp(evnp);
	if (!evnp_path)
	{
		perror("PATH not found");
		free(evnp);
		return (NULL);
	}
	path = ft_split(evnp_path, ':');
	if (!path)
	{
		perror("Split don't work as expect");
		free_matrix(path);
		return (NULL);
	}
	return (path);
}

char	*get_comand_path(char *cmd, char **path)
{
	char	*full_path;
	int		i;

	i = 0;
	while (path && path[i])
	{
		full_path = make_path(path[i], cmd);
		if (!full_path)
		{
			free (full_path);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free_matrix(path);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_matrix(path);
	perror("Command not found");
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**path;
	char	*full_path;

	path = get_path(envp);
	if (!path)
	{
		free_matrix (path);
		return (NULL);
	}
	full_path = get_comand_path(cmd, path);
	if (!full_path)
	{
		free (full_path);
		return (NULL);
	}
	return (full_path);
}
