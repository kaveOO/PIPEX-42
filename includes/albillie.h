/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   albillie.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:44:46 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/03 04:08:10 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_args // ? Linked list that contains all the arguments
{
	char			*arg;
	struct s_args	*next;
}					t_args;

t_args	*init_args_list(int ac, char **av);
t_args	*args_lst_new(char *arg);
void	args_add_back(t_args **args, t_args *arg);
void	print_args_list(t_args *args);
void	free_args_list(t_args *args);
void	exit_handler(t_args *args);

#endif
