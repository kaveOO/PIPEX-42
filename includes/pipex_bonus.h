/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:33:40 by albillie          #+#    #+#             */
/*   Updated: 2025/01/06 19:11:36 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_pipex
{
	char		*infile;
	char		*outfile;
	int			cmd_count;
	pid_t		pid[];
}				t_pipex;

void	format_bonus(void);
void	handle_here_doc(char **av, t_pipex *pipex);
t_pipex	*init_pipex_struct();

#endif
