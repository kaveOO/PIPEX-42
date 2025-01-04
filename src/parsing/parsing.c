/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:36:00 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/04 03:36:58 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_args(int ac, char **av, char **envp)
{
	char	*outfile[] = {find_path("touch", envp), av[ac - 1], NULL};

	if (open(av[1], O_RDONLY) == -1)
		return (perror(av[1]), false);
	ft_printf("%s\n", av[ac - 1]);
	if (open(av[ac - 1], O_WRONLY) == -1)
		execve(find_path("touch", envp), outfile, envp);
	return (true);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*tmp_path;
	char	*path;
	int		i;

	i = 0;
	while (strncmp(envp[i], "PATH", 4))
		envp++;
	paths = ft_split(envp[i] + 5, ':');
	while (paths[i])
	{
		tmp_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp_path, cmd);
		free(tmp_path);
		if (access(path, F_OK) == 0)
		{
			free_array(paths, i);
			return (path);
		}
		free(path);
		i++;
	}
	free_array(paths, i);
	return (0);
}
