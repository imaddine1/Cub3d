/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:49:36 by iharile           #+#    #+#             */
/*   Updated: 2022/11/01 13:35:53 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*fd_texture(char *str, char *bf, t_info *map)
{
	char	*rev;
	int		fd;

	rev = ft_strrchr(str, '.');
	if (ft_strncmp(rev, ".xpm", 4))
	{
		free (bf);
		free_struct(map);
		free_and_msg(0, 0, str,
			"\033[0;31merorr:extension of textures\033[0m");
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free (bf);
		free_struct(map);
		free_and_msg(0, 0, str,
			"\033[0;31merror:texture not found!\033[0m");
	}
	close(fd);
	return (str);
}
