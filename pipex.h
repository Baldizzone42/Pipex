/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:36:59 by jormoral          #+#    #+#             */
/*   Updated: 2024/09/11 10:55:18 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <aio.h>

char	*search_path(char *str, char **env, int len);
char	**clean_path(char *path, int start);
char	*check_access_path(char **path, char *cmd);
void	child_process1(int fd[2], char **argv, char **env);
void	child_process2(int fd[2], char **argv, char **env);
void	execute_cmd(char *argv, char **env, char *found_cmd);
void	free_split(char **split);
void	ft_exit_error(char *str);
#endif