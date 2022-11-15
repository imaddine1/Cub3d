/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:44:56 by iharile           #+#    #+#             */
/*   Updated: 2022/10/06 15:55:36 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// if file is empty is invalid

#include "../inc/header.h"

void	land_zero_invalid_place(char *s, char *main_str)
{
	char	**divide_lines;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	divide_lines = ft_split(s, '\n');
	while (divide_lines[i])
	{
		len = (int)ft_strlen(divide_lines[i]);
		j = i + 1;
		while (len < (int)ft_strlen(divide_lines[j]))
		{
			if (divide_lines[j][len] == '0')
			{
				free (main_str);
				ft_free(divide_lines);
				msg_exit("\033[0;31m Put your zeros in correct place\033[0m");
			}
			len++;
		}
		i++;
	}
	ft_free(divide_lines);
}

void	land_content(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n' && (str[i + 1] == '1' || str[i + 1] == '0'
				|| str[i + 1] == ' '))
		{
			i++;
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i] == '1' || str[i] == '0')
			{
				land_surrounded_walls(&str[i], str);
				land_zero_invalid_place(&str[i], str);
				land_numbers(&str[i], str);
				land_newlines(&str[i], str);
				land_holes(&str[i], str);
				return ;
			}
		}
	}
	free_and_msg(NULL, NULL, str, "\033[0;31mland is not found!!\033[0;m");
}

t_info	*check_map(char *s, t_info *map)
{
	long	i;
	int		fd;
	char	*str;

	fd = open (s, O_RDONLY);
	i = sizeof_file(s);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	read(fd, str, i);
	str[i] = 0;
	close(fd);
	check_objects(str);
	land_content(str);
	map = malloc(sizeof(t_info));
	if (!map)
		return (0);
	map->no = NULL;
	map->so = NULL;
	map->ea = NULL;
	map->we = NULL;
	map->land = NULL;
	take_info_by_struct(str, map);
	free (str);
	return (map);
}
