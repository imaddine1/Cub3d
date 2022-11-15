/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:16:40 by iharile           #+#    #+#             */
/*   Updated: 2022/10/06 15:39:34 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	check_comma(char *s, int c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	floor_ceilling(char *s, t_info *map, char c)
{
	char	**divide_half_line;
	int		j;

	if (!check_comma(s, ','))
		return (0);
	divide_half_line = ft_split(s, ',');
	if (ft_splen(divide_half_line) != 3)
		free_and_msg(divide_half_line, NULL, NULL,
			"\033[0;31mYour floor or ceilling have incorrect RGB color 1\033[0m");
	j = -1;
	while (++j < 3)
	{
		if (my_atoi(divide_half_line[j]) != -1)
		{
			if (c == 'F')
				map->f[j] = my_atoi(divide_half_line[j]);
			else
				map->c[j] = my_atoi(divide_half_line[j]);
		}
		else
			free_and_msg(divide_half_line, NULL, NULL,
				"\033[0;31mfloor or ceilling  have incorrect RGB color\033[0m");
	}
	ft_free (divide_half_line);
	return (1);
}

int	check_each_object(char *s, t_info *map)
{
	char	**divide_one_line;
	int		len;

	divide_one_line = ft_split(s, ' ');
	if (!divide_one_line[0] || !divide_one_line[1])
		return (0);
	len = (int)ft_strlen(divide_one_line[0]);
	if (!ft_strncmp(divide_one_line[0], "NO", len))
		map->no = ft_strdup(divide_one_line[1]);
	else if (!ft_strncmp(divide_one_line[0], "SO", len))
		map->so = ft_strdup(divide_one_line[1]);
	else if (!ft_strncmp(divide_one_line[0], "WE", len))
		map->we = ft_strdup(divide_one_line[1]);
	else if (!ft_strncmp(divide_one_line[0], "EA", len))
		map->ea = ft_strdup(divide_one_line[1]);
	else if (!ft_strncmp(divide_one_line[0], "F", len)
		&& !norm_floor_ceilling(divide_one_line[1], map, 'F', divide_one_line))
		return (0);
	else if (!ft_strncmp(divide_one_line[0], "C", len)
		&& !norm_floor_ceilling(divide_one_line[1], map, 'C', divide_one_line))
		return (0);
	ft_free(divide_one_line);
	return (1);
}

void	each_object(char **divide_lines, char *s, char *arr_object)
{
	char	**divide_one_line;
	int		j;

	divide_one_line = ft_split(s, ' ');
	j = ft_strlen(divide_one_line[0]);
	if (!ft_strncmp(divide_one_line[0], "NO", j))
		arr_object[0] += 1;
	else if (!ft_strncmp(divide_one_line[0], "SO", j))
		arr_object[1] += 1;
	else if (!ft_strncmp(divide_one_line[0], "WE", j))
		arr_object[2] += 1;
	else if (!ft_strncmp(divide_one_line[0], "EA", j))
		arr_object[3] += 1;
	else if (!ft_strncmp(divide_one_line[0], "F", j))
		arr_object[4] += 1;
	else if (!ft_strncmp(divide_one_line[0], "C", j))
		arr_object[5] += 1;
	else
		free_and_msg(divide_lines, divide_one_line, NULL,
			"\033[0;31m Make sure you have all required objects!!\033[0m");
	ft_free(divide_one_line);
}

void	check_objects(char *s)
{
	char	arr_object[6];
	char	**divide_lines;
	int		i;

	divide_lines = ft_split(s, '\n');
	if (!*divide_lines)
		free_and_msg(NULL, divide_lines, NULL,
			"\033[0;34mEmpty file?? check is the correct file \033[0m");
	i = -1;
	while (++i < 6)
		arr_object[i] = 0;
	i = -1;
	while (++i < 6 && divide_lines[i])
		each_object(divide_lines, divide_lines[i], arr_object);
	i = -1;
	while (++i < 6)
		if (!arr_object[i] || arr_object[i] > 1)
			free_and_msg(divide_lines, NULL, NULL,
				"\033[0;31m May have duplicated or none objects\033[0m");
	if (!divide_lines[i])
		free_and_msg(divide_lines, NULL, NULL, "\033[0;31mland not found\033[0m");
	if (!(divide_lines[i][0] == '1' || divide_lines[i][0] == ' '))
		free_and_msg(divide_lines, NULL, NULL,
			"\033[0;31mYou have more than required objects!\033[0m");
	ft_free (divide_lines);
}
