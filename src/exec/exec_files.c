/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 04:44:42 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/04 20:23:23 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	setup_files(char *infile, char *outfile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		perror(infile);
		return (false);
	}
	if (!dup2(fd, STDIN_FILENO))
		return (false);
	close(fd);
	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(outfile);
		return (false);
	}
	if (!dup2(fd, STDOUT_FILENO))
		return (false);
	close(fd);
	return (true);
}
