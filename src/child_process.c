/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:23:08 by jormoral          #+#    #+#             */
/*   Updated: 2024/09/11 10:57:37 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process1(int fd[2], char **argv, char **env)
{
	int	inputfd;

	close(fd[0]);
	inputfd = open(argv[1], O_RDONLY);
	if (inputfd < 0)
	{
		perror("wrong opening");
		exit(1);
	}
	if (dup2(inputfd, STDIN_FILENO) == -1)
	{
		perror("Wrong dup2 procces input child");
		exit(1);
	}
	close(inputfd);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("Wrong dup2 procces output child");
		exit(1);
	}
	close (fd[1]);
	execute_cmd (argv[2], env, NULL);
}

void	child_process2(int fd[2], char **argv, char **env)
{
	int	outfd2;

	close(fd[1]);
	outfd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfd2 < 0)
	{
		perror("Wrong outfd2");
		exit(1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("Wrong dup2 input");
		exit(1);
	}
	close(fd[0]);
	if (dup2(outfd2, STDOUT_FILENO) == -1)
	{
		perror("Wrong output child2");
		exit(1);
	}
	close(outfd2);
	execute_cmd(argv[3], env, NULL);
}
