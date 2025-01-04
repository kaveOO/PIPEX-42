/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 05:27:37 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/04 20:32:15 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	status;
	int	i;

	i = 0;
	// if (ft_strncmp(av[1], "here_doc", 8))
	// {
	// 	// ! Execute here_doc right here.
	// }

	if (ac < 5)
		format(), exit(1);
	if (!setup_files(av[1], av[ac - 1]))
		exit(1);
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
