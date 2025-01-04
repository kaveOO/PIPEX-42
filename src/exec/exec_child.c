/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 04:44:15 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/04 16:59:47 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void exec_infile(int fd)
{
	if (dup2(fd, STDIN_FILENO) < 0)
		exit(1);
	close(fd);
}

static void exec_outfile(int fd)
{
	if (dup2(fd, STDOUT_FILENO) < 0)
		exit(1);
	close(fd);
}

static void exec_command(char *cmd, char **envp)
{
	char **args;
	char *path;

	args = ft_split(cmd, ' ');
	path = find_path(args[0], envp);
	if (!path)
	{
		write(2, "Command not found: ", 18);
		write(2, args[0], ft_strlen(args[0]));
		write(2, "\n", 1);
		gls_free_tbl(args);
		exit(1);
	}
	execve(path, args, envp);
	free(path);
	gls_free_tbl(args);
	exit(1);
}

void handle_child_process(int fd_in, int fd_out, char *cmd, char **envp)
{
	if (fd_in != STDIN_FILENO)
		exec_infile(fd_in);
	if (fd_out != STDOUT_FILENO)
		exec_outfile(fd_out);
	exec_command(cmd, envp);
}

void handle_here_doc(char *limiter)
{
	int fd[2];
	char *line;

	if (pipe(fd) == -1)
		perror("pipe"), exit(1);
	while ((line = get_next_line(0)))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			close(fd[1]);
			exit(0);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
	close(fd[1]);
}
