/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:33:10 by albillie          #+#    #+#             */
/*   Updated: 2025/01/06 23:39:26 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	format_bonus(void)
{
	ft_printf("Format -> ./pipex <here_doc> <LIMITER> <cmd1> <cmd2> <outfile>\n");
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
