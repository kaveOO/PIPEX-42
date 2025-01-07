/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:23:35 by albillie          #+#    #+#             */
/*   Updated: 2025/01/07 14:34:03 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	handle_here_doc(char *limiter, int ac)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (ac < 6)
		format_bonus();
	if (pipe(fd) == -1)
		error("pipe");
	reader = fork();
	if (reader == -1)
		error("fork");
	if (reader == 0)
	{
		close(fd[0]);
		while (true)
		{
			line = get_next_line(0);
			if (strncmp(line, limiter, ft_strlen(limiter) == 0))
			{
				free(line);
				get_next_line(-1);
				exit(EXIT_SUCCESS);
			}
			ft_putstr_fd(line, fd[1]);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		exit(EXIT_SUCCESS);
	}
}

void	exec(char **envp, t_pipex *pipex)
{
	int	i = 0;

	(void) envp;
	while (i < pipex->cmd_count)
	{
		pipex->pid[i] = fork();
		if (pipex->pid[i] < 0)
			perror("fork");
		if (pipex->pid[i] == 0)
		{
			ft_printf("in a command child\n");
			exit(1);
		}
		ft_printf_fd(2, "%d\n", pipex->pid[i]);
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		infile;
	int		outfile;

	(void) envp;
	ac -= 1;
	pipex = init_pipex_struct();
	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			outfile = open(av[ac], O_WRONLY | O_CREAT | O_APPEND);
			handle_here_doc(av);
		}
	}
	else
	{
		free(pipex);
		format_bonus();
	}
	unlink("temp");
}


