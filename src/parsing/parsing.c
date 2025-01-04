/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:36:00 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/04 05:13:24 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_args(int ac, char **av, char **envp)
{
	char **touch_cmd;

	if (open(av[1], O_RDONLY) == -1)
		return (perror(av[1]), false);
	touch_cmd = malloc(sizeof(char **) * 3);
	if (!touch_cmd)
		return (perror("touch command"), false);
	touch_cmd[0] = find_path("touch", envp);
	touch_cmd[1] = av[ac - 1];
	touch_cmd[2] = NULL;
	if (open(av[ac - 1], O_WRONLY) == -1)
	{
		execve(find_path("touch", envp), touch_cmd, envp);
	}
	free_array(touch_cmd, 1);
	return (true);
}
static void    free_array(char **array)
{
    int    i;

    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

char    *find_path(char *cmd, char **envp)
{
    char    **paths;
    char    *tmp_path;
    char    *path;
    int        i;

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
    return (free_array(paths), NULL);
}
