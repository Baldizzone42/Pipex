/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:54:41 by jormoral          #+#    #+#             */
/*   Updated: 2024/09/14 12:55:57 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_split(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}

char	*check_access_path(char **path, char *cmd)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (!cmd)
			return (NULL);
		path[i] = ft_strjoin(path[i], cmd);
		if (access (path[i], X_OK) == 0)
			break ;
		free(path[i]);
		path[i] = NULL;
		i++;
	}
	if (path[i] == NULL)
		return (NULL);
	return (path[i]);
}

char	**clean_path(char *path, int start)
{
	char	**clean;
	int		i;

	i = 0;
	if (!path)
		return (ft_split(" ", ' '));
	clean = ft_split(&path[start], ':');
	if (!clean)
		return (NULL);
	while (clean[i])
	{
		clean[i] = ft_strjoin(clean[i], "/");
		i++;
	}
	return (clean);
}

char	*search_path(char *str, char **env, int len)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(str, env[i], len) == 0)
			break ;
		i++;
	}
	return (env[i]);
}
