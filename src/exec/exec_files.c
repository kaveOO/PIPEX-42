/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 04:44:42 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/04 07:08:56 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_infile(char *file)
{
	if (access(file, F_OK))
	{
		write(2, "infile: No such file\n", 21);
		return (0);
	}
	if (access(file, R_OK))
	{
		write(2, "infile: Permission denied\n", 25);
		return (0);
	}
	return (1);
}

static int	open_infile(char *file)
{
	int	fd;

	if (!check_infile(file))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("infile");
	return (fd);
}

static int	open_outfile(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("outfile");
		return (-1);
	}
	return (fd);
}

int	setup_files(char *infile, char *outfile)
{
	int	fd;

	fd = open_infile(infile);
	if (fd < 0)
		return (0);
	if (dup2(fd, STDIN_FILENO) < 0)
		return (0);
	close(fd);
	fd = open_outfile(outfile);
	if (fd < 0)
		return (0);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (0);
	close(fd);
	return (1);
}
