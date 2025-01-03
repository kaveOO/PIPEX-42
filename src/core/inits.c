/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:40:59 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/03 03:20:22 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "albillie.h"

t_args	*init_args_list(int ac, char **av) // ? Function to init args linked list
{
	t_args	*args;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (i == 1)
		{
			args = args_lst_new(av[i]);
		}
		else
		{
			args_add_back(&args, args_lst_new(av[i]));
		}
		i++;
	}
	return (args);
}
