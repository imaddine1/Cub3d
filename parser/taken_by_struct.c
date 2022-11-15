/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_by_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:30:48 by iharile           #+#    #+#             */
/*   Updated: 2022/11/09 12:44:04 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	take_info_by_struct(char *s, t_info *map)
{
	take_objects(s, map);
	take_direction(s, map);
	take_land(s, map);
}

void	take_direction(char *s, t_info *map)
{
	char	**divide_lines;
	int		i;
	int		j;

	divide_lines = ft_split(s, '\n');
	(void)map;
	i = 7;
	while (divide_lines[i])
	{
		j = 0;
		while (divide_lines[i][j])
		{
			if (divide_lines[i][j] == 'N' || divide_lines[i][j] == 'S'
				|| divide_lines[i][j] == 'E' || divide_lines[i][j] == 'W')
			{
				map->direction = divide_lines[i][j];
				ft_free(divide_lines);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	take_land(char *s, t_info *map)
{
	char	**divide_lines;
	int		i;
	int		j;

	i = 5;
	divide_lines = ft_split(s, '\n');
	while (divide_lines[++i])
	{
		j = 0;
		while (divide_lines[i][j] && divide_lines[i][j] == ' ')
			j++;
		if (divide_lines[i][j] == '1')
			break ;
	}
	map->land = matrixdup(&divide_lines[i]);
	ft_free(divide_lines);
}

char	**matrixdup(char **s)
{
	int		i;
	int		size;
	char	**copy;

	size = ft_splen(s);
	copy = malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (s[i])
	{
		copy[i] = ft_strdup(s[i]);
		i++;
	}
	copy[i] = 0;
	return (copy);
}

void	take_objects(char *s, t_info *map)
{
	int		i;
	char	**divide_lines;

	divide_lines = ft_split(s, '\n');
	i = 0;
	while (i < index_end_objects(divide_lines))
	{
		if (!check_each_object(divide_lines[i], map))
		{
			ft_free(divide_lines);
			free_struct(map);
			msg_exit("\033[0;31mfloor or ceilling is incorrect!!\033[0;m");
		}
		i++;
	}
	map->hexfloor = hex(map->f);
	map->hexceilling = hex(map->c);
	ft_free (divide_lines);
}
