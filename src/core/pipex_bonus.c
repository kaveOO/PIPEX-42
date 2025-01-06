/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:23:35 by albillie          #+#    #+#             */
/*   Updated: 2025/01/06 02:21:41 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_here_doc(int *fd, char **av)
{
	char	*line;

	if (pipe(fd) == -1)
		perror("pipe");
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
		free(line);
	}
}

int main(int ac, char **av, char **envp)
{
	int	fd[2];

	(void) envp;
	ac -= 1;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 5)
			format_bonus();
		handle_here_doc(fd, av);
	}
	else
	{


	}
}
