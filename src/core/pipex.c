/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 05:27:37 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/05 19:54:02 by albillie         ###   ########.fr       */
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
	temp = command[0];
	path = find_path(command[0], envp);
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

void handle_child_process(char **envp, char **av, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		perror(av[1]), exit(1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	exec(envp, av[2]);
}

void	handle_parent_process(char **envp, int ac, char **av, int *fd)
{
	int	outfile;

	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
		perror(av[ac - 1]), exit(1);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	exec(envp, av[3]);
}

int main(int ac, char **av, char **envp)
{
	int fd[2];
	pid_t pid;

	if (ac < 5)
		format();
	pipe(fd);
	if (fd < 0)
		perror("pipe");
	pid = fork();
	if (pid < 0)
		perror("fork");
	if (pid == 0)
		handle_child_process(envp, av, fd);
	waitpid(pid, NULL, 0);
	handle_parent_process(envp, ac, av, fd);
}
