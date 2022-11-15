/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:46:28 by iharile           #+#    #+#             */
/*   Updated: 2022/10/06 15:41:41 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	norm_walls(char **divide_lines, int i, int j, char *main_str)
{
	int	k;

	k = ft_strlen(divide_lines[i]) - 1;
	if (((divide_lines[i][j] != '1' && divide_lines[i][j] != ' ') ||
			(divide_lines[i][k] != '1' && divide_lines[i][k] != ' ')) &&
					(i > 0 && divide_lines[i + 1] != '\0'))
		free_and_msg(divide_lines, NULL, main_str,
			"\033[0;31myour land is incorrect:check the walls\033[0;m");
}

void	norm_land_numbers(char *main_str, int j)
{
	if (j == 0)
		free_and_msg(NULL, NULL, main_str,
			"\033[0;31mAt least one of directionds: W,S,E or N\033[0;31m");
}

int	norm_floor_ceilling(char *s, t_info *map, char c, char **double_str)
{
	if (!floor_ceilling(s, map, c))
	{
		ft_free(double_str);
		return (0);
	}
	return (1);
}
