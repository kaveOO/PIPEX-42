/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 05:27:37 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/04 07:12:12 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int    main(int ac, char **av, char **envp)
{
    int    status;
    int    i;

	check_args(ac, av);
    if (!setup_files(av[1], av[ac - 1]))
        return (1);
    if (execute_pipeline(av + 2, ac - 3, envp))
        return (1);
    i = 0;
    while (i < ac - 3)
    {
        wait(&status);
        i++;
    }
    return (0);
}
