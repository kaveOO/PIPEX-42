/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:36:00 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/04 15:17:39 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac, char **av)
{
	(void)av;
	if (ac <= 4)
		format();
	// if (open(av[1], O_RDONLY) == -1)
	// 	(perror(av[1]), exit(1));
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*tmp_path;
	char	*path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		tmp_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp_path, cmd);
		free(tmp_path);
		if (!access(path, F_OK | X_OK))
			return (free_array(paths), path);
		free(path);
		i++;
	}
	return (0);
}
