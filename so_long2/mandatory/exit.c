/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:53:39 by iharile           #+#    #+#             */
/*   Updated: 2022/03/23 16:36:35 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	counter_2d(char **str, char ch)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ch)
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	move_exit(t_img *c, char ch)
{
	int	x;
	int	y;

	x = c->x_player / 50;
	y = c->y_player / 50;
	if (ch == 'w')
		if (c->str[y - 1][x] == 'E' && counter_2d(c->str, 'C') == 0)
			exit(1);
	if (ch == 's')
		if (c->str[y + 1][x] == 'E' && counter_2d(c->str, 'C') == 0)
			exit(1);
	if (ch == 'd')
		if (c->str[y][x + 1] == 'E' && counter_2d(c->str, 'C') == 0)
			exit(1);
	if (ch == 'a')
		if (c->str[y][x - 1] == 'E' && counter_2d(c->str, 'C') == 0)
			exit(1);
}
