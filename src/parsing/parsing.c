/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:36:00 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/03 04:09:06 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/albillie.h"

// ? **envp est un pointeur sur la liste des variables d'environnement pour aller chercher les commandes.
int	main(int ac, char **av, char **envp)
{
	(void) envp;
	t_args	*args;

	args = init_args_list(ac, av);
	print_args_list(args);
	exit_handler(args);
}


