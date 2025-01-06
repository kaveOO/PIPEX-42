/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:01:16 by albillie          #+#    #+#             */
/*   Updated: 2025/01/06 15:06:48 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	format(void)
{
	ft_printf("Format -> ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	exit(1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
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
	free_array(paths);
	return (0);
}
