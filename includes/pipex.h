/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:44:46 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/06 14:51:46 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

char	*find_path(char *cmd, char **envp);
void	free_array(char **array);
void	format(void);
pid_t	handle_parent_process(char **envp, int ac, char **av, int *fd);
pid_t	handle_child_process(char **envp, char **av, int *fd);

#endif
