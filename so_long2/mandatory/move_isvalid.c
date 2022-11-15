/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_isvalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:23:37 by iharile           #+#    #+#             */
/*   Updated: 2022/03/29 11:02:29 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	counter_constraint(char *str, char ch)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == ch)
			c++;
		i++;
	}
	return (c);
}

int	closegame(t_img *c)
{
	mlx_destroy_window(c->mlx, c->mlx_win);
	exit(0);
}

void	update(t_img *c, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(c->mlx, path, &c->w, &c->h);
	mlx_put_image_to_window(c->mlx, c->mlx_win, img, c->x_player, c->y_player);
	c->img = img;
}

int	move_isvalid(t_img *c, char **str, char ch)
{
	int	x;
	int	y;

	x = c->x_player / 50;
	y = c->y_player / 50;
	if (ch == 'w')
		if (str[y - 1][x] == '0' || str[y - 1][x] == 'C'
			|| str[y - 1][x] == 'P')
			return (1);
	if (ch == 's')
		if (str[y + 1][x] == '0' || str[y + 1][x] == 'C'
			|| str[y + 1][x] == 'P')
			return (1);
	if (ch == 'd')
		if (str[y][x + 1] == '0' || str[y][x + 1] == 'C'
			|| str[y][x + 1] == 'P')
			return (1);
	if (ch == 'a')
		if (str[y][x - 1] == '0' || str[y][x - 1] == 'C'
			|| str[y][x - 1] == 'P')
			return (1);
	return (0);
}

int	map_invalid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '1' || s[i] == '0' || s[i] == 'P' || s[i] == 'C'
			|| s[i] == 'E' || s[i] == '\n')
		i++;
		else
			return (0);
	}
	return (1);
}
