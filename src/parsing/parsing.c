/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:36:00 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/03 10:44:37 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* bool	check_args(t_args *args, char **envp)
{
	if (open(args->arg, O_RDONLY) == -1)
		return (perror(args->arg), false);
	if (open(get_args_last(args), O_WRONLY) == -1)
	{
		const char *filename = "/usr/bin/ls";
		char *const argv[] = {"/usr/bin/ls", "-a", "|" "/usr/bin/touch", "" "|"};

		execve(filename, argv, envp	);
	}
	return true;
} */
