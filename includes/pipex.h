/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:44:46 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/05 17:29:51 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

void	check_args(int ac, char **av);
char	*find_path(char *cmd, char **envp);
bool	setup_files(char *infile, char *outfile);
int		execute_pipeline(char **cmds, int cmd_count, char **envp);
void	free_array(char **array);
void	gls_free_tbl(char **tbl);
void 	handle_child_process(char **envp, char **av, int *fd);
void	format();
int		open_outfile(char *file);
void 	handle_here_doc(char *limiter);

#endif
