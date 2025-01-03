/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:46:49 by kaveo             #+#    #+#             */
/*   Updated: 2025/01/03 11:05:56 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**fill_parsing_array(int ac, char **av)
{
	char	***array;
	int	i;

	array = malloc(sizeof(char ***) * ac);
	if (!array)
		return (perror("array"), NULL);
	i = 1;
	while (i < ac)
	{
		/* code */
	}



}

// tbl = {
// 	[1] = {
// 		[1] = "tts"
// 		[2] = "tts2"
// 	}
// 	[2] = {
// 		[1] = "tts"
// 		[2] = "tts2"
// 	}
// 	[3] = {
// 		[1] = "tts"
// 		[2] = "tts2"
// 	}
// 	[4] = {
// 		[1] = "tts"
// 		[2] = "tts2"
// 	}
// 	[5] = {
// 		[1] = "tts"
// 		[2] = "tts2"
// 	}
// }
