/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   land_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:03 by iharile           #+#    #+#             */
/*   Updated: 2022/11/01 09:26:24 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	land_newlines(char *s, char *main_str)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n' && (s[i + 1] == ' '))
		{
			while (s[i] && (s[i + 1] == ' '))
				i++;
			if (s[i + 1] == '\n')
				free_and_msg(NULL, NULL, main_str,
					"\033[0;31myour land is incorrect:continous lines\033[0;m");
		}
		else if (s[i] == '\n' && s[i + 1] == '\n')
			free_and_msg(NULL, NULL, main_str,
				"\033[0;31myour land is incorrect:continous lines\033[0;m");
	}
}

void	land_surrounded_walls(char *s, char *main_str)
{
	char	**divide_lines;
	int		i;
	int		j;
	int		k;

	divide_lines = ft_split(s, '\n');
	i = -1;
	while (divide_lines[++i])
	{
		j = 0;
		while (divide_lines[i][j] && (divide_lines[i][j] == ' '))
			j++;
		if (divide_lines[i][j] == '\0')
			free_and_msg(divide_lines, NULL, main_str,
				"\033[0;31mland is incorrect:check the spaces in line\033[0;m");
		k = j - 1;
		while (divide_lines[i][++k] && (i == 0 ||
			i == ft_splen(divide_lines) - 1))
			if (divide_lines[i][k] != '1' && divide_lines[i][k] != ' ')
				free_and_msg(divide_lines, NULL, main_str,
					"\033[0;31mland is incorrect:check the walls\033[0;m");
		norm_walls(divide_lines, i, 0, main_str);
	}
	ft_free(divide_lines);
}

char	land_numbers(char *s, char *main_str)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	j = 0;
	c = 0;
	while (s[++i])
	{
		if (s[i] == '0' || s[i] == '1' || s[i] == '\n' || s[i] == ' ')
			continue ;
		if (s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
		{
			c = s[i];
			j++;
			if (j >= 2)
				free_and_msg(NULL, NULL, main_str,
					"\033[0;31mcheck postions of your player\033[0;31m");
		}
		else
			free_and_msg(NULL, NULL, main_str,
				"\033[0;31myou put something not allowed\033[0;m");
	}
	norm_land_numbers(main_str, j);
	return (c);
}
/*
int	check_hole(char **s, int row, int col)
{
	if ((row > 0 && col < (int)ft_strlen(s[row - 1]))
		&& !(s[row - 1][col] == ' ' || s[row - 1][col] == '1'))
	{
		return (0);
	}
	if ((row < ft_splen(s) - 1 && col < (int)ft_strlen(s[row + 1]))
		&& !(s[row + 1][col] == ' ' || s[row + 1][col] == '1'))
	{
		return (0);
	}
	if (col > 0 && !(s[row][col - 1] == ' ' || s[row][col - 1] == '1'))
		return (0);
	if (col < (int)ft_strlen(s[row]) - 1 && !(s[row][col + 1] == ' '
		|| s[row][col + 1] == '1'))
		return (0);
	return (1);
}*/

/*void	land_holes(char *s, char *main_str)
{
	int		i;
	int		j;
	int		len;
	char	**divide_lines;

	divide_lines = ft_split(s, '\n');
	i = -1;
	while (divide_lines[++i])
	{
		j = 0;
		len = (int)ft_strlen(divide_lines[i]) - 1;
		while (len >= 0 && divide_lines[i][len] == ' ')
			len --;
		while (j <= len)
		{	
			if (divide_lines[i][j] == ' ')
				if (!check_hole(divide_lines, i, j))
					free_and_msg(NULL, NULL, main_str,
						"\033[0;31mUse your spaces carefully !! \033[0m");
			j++;
		}
	}
	ft_free(divide_lines);
}*/
