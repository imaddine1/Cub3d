/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:16:40 by iharile           #+#    #+#             */
/*   Updated: 2022/11/01 14:57:12 by iharile          ###   ########.fr       */
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
	char	**div;
	int		j;
	char	*trim;

	if (!check_comma(s, ','))
		return (free_return(NULL, s, NULL, 0));
	div = ft_split(s, ',');
	j = -1;
	while (++j < 3)
	{
		trim = ft_strtrim(div[j], " ");
		if (my_atoi(trim) != -1)
		{
			if (c == 'F')
				map->f[j] = my_atoi(trim);
			else
				map->c[j] = my_atoi(trim);
		}
		else
			return (free_return(div, s, trim, 0));
		free (trim);
	}
	return (free_return(div, s, NULL, 1));
}

int	check_each_object(char *s, t_info *map)
{
	char	*cpy_bf_sp;
	char	*cpy_af_sp;
	int		len;

	cpy_bf_sp = copy_before_space(s);
	cpy_af_sp = copy_after_space(s);
	if (!cpy_bf_sp || !cpy_af_sp)
		return (0);
	len = (int)ft_strlen(cpy_bf_sp);
	if (!ft_strncmp(cpy_bf_sp, "NO", len))
		map->no = fd_texture(cpy_af_sp, cpy_bf_sp, map);
	else if (!ft_strncmp(cpy_bf_sp, "SO", len))
		map->so = fd_texture(cpy_af_sp, cpy_bf_sp, map);
	else if (!ft_strncmp(cpy_bf_sp, "WE", len))
		map->we = fd_texture(cpy_af_sp, cpy_bf_sp, map);
	else if (!ft_strncmp(cpy_bf_sp, "EA", len))
		map->ea = fd_texture(cpy_af_sp, cpy_bf_sp, map);
	else if (!ft_strncmp(cpy_bf_sp, "F", len)
		&& !norm_floor_ceilling(cpy_af_sp, map, 'F', cpy_bf_sp))
		return (0);
	else if (!ft_strncmp(cpy_bf_sp, "C", len)
		&& !norm_floor_ceilling(cpy_af_sp, map, 'C', cpy_bf_sp))
		return (0);
	free(cpy_bf_sp);
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
			"\033[0;31mYou put something wierd in objects section!!\033[0m");
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
				"\033[0;31m May have duplicated or object left\033[0m");
	if (!divide_lines[i])
		free_and_msg(divide_lines, NULL, NULL, "\033[0;31mland not found\033[0m");
	if (!(divide_lines[i][0] == '1' || divide_lines[i][0] == ' '))
		free_and_msg(divide_lines, NULL, NULL,
			"\033[0;31mYou have more than required objects!\033[0m");
	ft_free (divide_lines);
}
