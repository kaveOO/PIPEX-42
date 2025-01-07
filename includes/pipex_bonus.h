/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:33:40 by albillie          #+#    #+#             */
/*   Updated: 2025/01/07 14:24:58 by albillie         ###   ########.fr       */
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
	int			infile;
	int			outfile;
	int			cmd_count;
	pid_t		pid[];
}				t_pipex;

void	format_bonus(void);
int		handle_here_doc(char *limiter);
t_pipex	*init_pipex_struct();
void	error(char *error);

#endif
