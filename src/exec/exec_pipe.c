/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 04:45:15 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/04 16:11:35 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	create_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) < 0)
	{
		perror("pipe");
		return (0);
	}
	return (1);
}

static int	handle_last_cmd(char *cmd, char **envp, int fd_in)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
		handle_child_process(fd_in, STDOUT_FILENO, cmd, envp);
	return (pid);
}

static int	handle_pipe_cmd(char *cmd, char **envp, int fd_in, int pipe_fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
		handle_child_process(fd_in, pipe_fd[1], cmd, envp);
	return (pid);
}

int	execute_pipeline(char **cmds, int cmd_count, char **envp)
{
	int	i;
	int	pipe_fd[2];
	int	fd_in;
	int	pid;

	fd_in = STDIN_FILENO;
	i = -1;
	while (++i < cmd_count - 1)
	{
		if (!create_pipe(pipe_fd))
			return (1);
		pid = handle_pipe_cmd(cmds[i], envp, fd_in, pipe_fd);
		if (pid < 0)
			return (1);
		if (fd_in != STDIN_FILENO)
			close(fd_in);
		close(pipe_fd[1]);
		fd_in = pipe_fd[0];
	}
	pid = handle_last_cmd(cmds[i], envp, fd_in);
	if (pid < 0)
		return (1);
	return (0);
}
