/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:46:49 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/03 03:25:06 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "albillie.h"

t_args	*args_lst_new(char *arg)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->arg = arg;
	args->next = NULL;
	return (args);
}

void	args_add_back(t_args **args, t_args *arg)
{
	t_args	*ptr;

	if (!args)
		return ;
	ptr = (*args);
	if (!ptr)
		(*args) = arg;
	else
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = arg;
	}
}

void	print_args_list(t_args *args)
{
	while (args)
	{
		ft_printf("%s\n", args->arg);
		args = args->next;
	}
}
