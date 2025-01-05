/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 05:27:37 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/05 23:22:56 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void exec(char **envp, char *av)
{
	char	*path;
	char	*temp;
	char	**command;
	int		i;

	i = 0;
	command = ft_split(av, ' ');
	if (ft_strchr(command[0], '/'))
	{
		if (access(command[0], F_OK) < 0)
			ft_printf_fd(2, "Command not found : %s\n", command[0]), exit(1);
		else if (access(command[0], X_OK) < 0)
			ft_printf_fd(2, "Permission denied : %s\n", command[0]), exit(1);
		execve(command[0], command, envp);
		exit(0);
	}
	path = find_path(command[0], envp);
	temp = command[0];
	if (!path)
	{
		ft_printf_fd(2, "command not found : %s\n", temp);
		while (command[i])
			free(command[i++]);
		free(command);
		exit(1);
	}
	execve(path, command, envp);
}

pid_t handle_child_process(char **envp, char **av, int *fd)
{
	int	infile;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror("fork");
	if (pid == 0)
	{
		infile = open(av[1], O_RDONLY);
		if (infile < 0)
			perror(av[1]), exit(1);
		dup2(fd[1], STDOUT_FILENO);
		dup2(infile, STDIN_FILENO);
		close(fd[0]);
		exec(envp, av[2]);
	}
	close(fd[1]);
	return (pid);
}

pid_t	handle_parent_process(char **envp, int ac, char **av, int *fd)
{
	int	outfile;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror("fork");
	if (pid == 0)
	{
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (outfile < 0)
			perror(av[ac - 1]), exit(1);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[1]);
		exec(envp, av[3]);
	}
	close(fd[0]);
	return (pid);
}

int main(int ac, char **av, char **envp)
{
	int fd[2];
	pid_t pid[2];

	if (ac < 5)
		format();
	if (pipe(fd) == -1)
		perror("pipe");
	pid[0] = handle_child_process(envp, av, fd);
	pid[1] = handle_parent_process(envp, ac, av, fd);
	for (int i = 0; i < 2; i++)
		waitpid(pid[i], NULL, 0);

//	waitpid(pid, NULL, 0);
//	waitpid(pid1, NULL, 0);
}
