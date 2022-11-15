/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_surrounded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:47:35 by iharile           #+#    #+#             */
/*   Updated: 2022/10/19 16:14:29 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	check(char **split, char *main_str, int j, int i)
{
	if (j <= (int)ft_strlen(split[i - 1]) - 1
		&& j <= (int)ft_strlen(split[i + 1]) - 1)
	{
		ft_free(split);
		return ;
	}
	else
	{
		ft_free (split);
		free (main_str);
		msg_exit("\033[0;31merror:check positon of your player\033[0m");
	}
}

void	player_surrounded(char *str, char *main_str, char c)
{
	char	**split;
	int		i;
	int		j;
	int		x;

	i = -1;
	x = 0;
	split = ft_split(str, '\n');
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (split[i][j] == c)
			{
				x = 1;
				break ;
			}
		}
		if (x == 1)
			break ;
	}
	check(split, main_str, j, i);
}
