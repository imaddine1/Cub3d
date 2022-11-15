/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:46:28 by iharile           #+#    #+#             */
/*   Updated: 2022/11/09 12:51:45 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	norm_walls(char **divide_lines, int i, int j, char *main_str)
{
	int		k;
	char	*trim;

	trim = ft_strtrim(divide_lines[i], " ");
	k = ft_strlen(trim) - 1;
	if (((trim[j] != '1' && trim[j] != ' ')
			|| (trim[k] != '1' && trim[k] != ' '))
		&& (i > 0 && divide_lines[i + 1] != '\0' && k > 0))
	{
		free (trim);
		free_and_msg(divide_lines, NULL, main_str,
			"\033[0;31myour land is incorrect:check the walls\033[0;m");
	}
	free(trim);
}

void	norm_land_numbers(char *main_str, int j)
{
	if (j == 0)
		free_and_msg(NULL, NULL, main_str,
			"\033[0;31mAt least one of directionds: W,S,E or N\033[0m");
}

int	norm_floor_ceilling(char *af_sp, t_info *map, char c, char *bf_sp)
{
	char	*s;

	s = ft_strtrim(af_sp, " ");
	free (af_sp);
	if (!floor_ceilling(s, map, c))
	{
		free (bf_sp);
		return (0);
	}
	return (1);
}
