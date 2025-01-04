/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:24:05 by albillie          #+#    #+#             */
/*   Updated: 2025/01/04 04:37:41 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ? **envp est un pointeur sur la liste des variables d'environnement pour aller chercher les commandes.
int	main(int ac, char **av, char **envp)
{
	check_args(ac, av, envp);
}
