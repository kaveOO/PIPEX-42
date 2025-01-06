/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:23:35 by albillie          #+#    #+#             */
/*   Updated: 2025/01/06 20:45:33 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_here_doc(char **av, t_pipex *pipex)
{
	char	*line;
	int		temp;

	temp = open("temp", O_RDWR | O_CREAT);
	if (temp < 0)
		perror("temp");
	pipex->infile = "temp";
	while (true)
	{
		line = get_next_line(0);
		if (!line)
			return ;
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			get_next_line(-1);
			return ;
		}
		ft_printf_fd(temp, line);
		free(line);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		fd[2];

	if (pipe(fd) == -1)
		perror("pipe");
	ac -= 1;
	pipex = init_pipex_struct();
	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			handle_here_doc(av, pipex);
			pipex->cmd_count = ac - 3;
		}
	}
	free(pipex);
	format_bonus();
}

t_pipex	*init_pipex_struct()
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->cmd_count = 0;
	pipex->infile = NULL;
	pipex->outfile = NULL;
	return (pipex);
}
