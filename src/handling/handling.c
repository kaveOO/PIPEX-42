/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 03:57:05 by albillie          #+#    #+#             */
/*   Updated: 2025/01/03 22:57:51 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	exit_handler(t_args *args)
{
	if (args)
		free_args_list(args);
}

bool	write_error(char *error, ...)
{
	va_list	args;
	va_start(args, error);
	ft_printf_fd(2, error, va_arg(args, char *));
	va_end (args);
	return (false);
}

void	free_args_list(t_args *args)
{
	t_args	*temp;

	while (args)
	{
		temp = args;
		args = args->next;
		free(temp);
	}
} */
