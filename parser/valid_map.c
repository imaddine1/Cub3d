/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:44:56 by iharile           #+#    #+#             */
/*   Updated: 2022/11/09 11:13:05 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// if file is empty is invalid

#include "../inc/header.h"

void	init_struct(t_info *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->land = NULL;
}

void	cond_of_zero(char **divide_lines, char *main_str, char c)
{
	if (c == '0')
	{
		free (main_str);
		ft_free(divide_lines);
		msg_exit("\033[0;31mPut your zeros in correct place\033[0m");
	}
}

void	land_zero_invalid_place(char *s, char *main_str)
{
	char	**divide_lines;
	int		i;
	int		j;
	int		len;

	j = 0;
	divide_lines = ft_split(s, '\n');
	i = 0;
	while (divide_lines[i])
	{
		len = (int)ft_strlen(divide_lines[i]);
		j = i + 1;
		if (len < (int)ft_strlen(divide_lines[j]))
			while (len < (int)ft_strlen(divide_lines[j]))
				cond_of_zero(divide_lines, main_str, divide_lines[j][len++]);
		else if (len > (int)ft_strlen(divide_lines[j]))
			while (len >= (int)ft_strlen(divide_lines[j]))
				cond_of_zero(divide_lines, main_str, divide_lines[i][len--]);
		i++;
	}
	ft_free(divide_lines);
}

void	land_content(char *str)
{
	int		i;
	int		j;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n' && (str[i + 1] == '1' || str[i + 1] == '0'
				|| str[i + 1] == ' '))
		{
			j = ++i;
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i] == '1')
			{
				all_things_of_land(&str[j], str);
				return ;
			}
			else
				i--;
		}
	}
	free_and_msg(NULL, NULL, str, "\033[0;31mland is not found!!\033[0;m");
}

t_info	*check_map(char *s, t_info *map)
{
	long	i;
	int		fd;
	char	*str;
	char	*trim;

	fd = open (s, O_RDONLY);
	i = sizeof_file(s);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	read(fd, str, i);
	str[i] = 0;
	close(fd);
	trim = ft_strtrim(str, "\n ");
	free(str);
	check_objects(trim, -1);
	land_content(trim);
	map = malloc(sizeof(t_info));
	if (!map)
		return (0);
	init_struct(map);
	take_info_by_struct(trim, map);
	free (trim);
	return (map);
}
