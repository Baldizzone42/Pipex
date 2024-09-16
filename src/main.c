/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:03:49 by jormoral          #+#    #+#             */
/*   Updated: 2024/09/11 13:50:24 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execute_cmd(char *argv, char **env, char *found_cmd)
{
	char	*found_way;
	char	**ready_path;
	char	**cmd;

	found_way = search_path("PATH=", env, 4);
	ready_path = clean_path(found_way, 5);
	cmd = ft_split(argv, ' ');
	found_cmd = check_access_path(ready_path, cmd[0]);
	if (!found_cmd)
	{
		free(found_cmd);
		free_split(ready_path);
		found_way = search_path("PWD=", env, 3);
		ready_path = clean_path(found_way, 4);
		found_cmd = check_access_path(ready_path, cmd[0]);
		if (!found_cmd)
		{
			free_split(ready_path);
			free_split(cmd);
			free(found_cmd);
		}
	}
	if (found_cmd)
		execve(found_cmd, cmd, env);
	ft_exit_error(argv);
}

void	ft_exit_error(char *str)
{
	write(2, "Command not found:  ", 19);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(127);
}

int	main(int argc, char *argv[], char **env)
{
	int	fd[2];
	int	pid;

	if (argc != 5)
	{
		write(1, "the argument number must be 5", 29);
		exit(1);
	}
	if (pipe(fd) == -1)
	{
		perror("Pipe error");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		exit(1);
	}
	if (pid == 0)
		child_process1(fd, argv, env);
	else
		child_process2(fd, argv, env);
	wait(NULL);
	return (0);
}
