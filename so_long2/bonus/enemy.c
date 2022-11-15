/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:01:23 by iharile           #+#    #+#             */
/*   Updated: 2022/03/22 17:21:10 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_enemy(t_img *c, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(c->mlx, path, &c->w, &c->h);
	mlx_put_image_to_window(c->mlx, c->mlx_win, img, c->x_enemy, c->y_enemy);
	c->img_enemy = img;
}

int	move_isvalid_enemy(t_img *c, char **str, char ch)
{
	int	x;
	int	y;

	x = c->x_enemy / 50;
	y = c->y_enemy / 50;
	if (ch == 'w')
		if (str[y - 1][x] == '0' || str[y - 1][x] == 'F'
			|| str[y - 1][x] == 'P')
			return (1);
	if (ch == 's')
		if (str[y + 1][x] == '0' || str[y + 1][x] == 'F'
			|| str[y + 1][x] == 'P')
			return (1);
	return (0);
}

void	move_up_enemy(t_img *c)
{
	if (move_isvalid_enemy(c, c->str, 'w'))
	{
		c->check_move = 0;
		mlx_destroy_image(c->mlx, c->img_enemy);
		update_enemy (c, "./assets/green.xpm");
		c->y_enemy -= 50;
		update_enemy (c, "./assets/enemy.xpm");
	}
	else
		c->check_move = 1;
}

void	move_down_enemy(t_img *c)
{
	if (move_isvalid_enemy(c, c->str, 's'))
	{
		c->check_move = 1;
		mlx_destroy_image(c->mlx, c->img_enemy);
		update_enemy (c, "./assets/green.xpm");
		c->y_enemy += 50;
		update_enemy (c, "./assets/enemy.xpm");
	}
	else
		c->check_move = 0;
}

int	next_frame(t_img *c)
{
	if (c->init_enemy == 10000)
	{
		if (c->check_move == 0)
			move_up_enemy(c);
		if (c->check_move == 1)
			move_down_enemy(c);
		c->init_enemy = 0;
	}
	else
		c->init_enemy++;
	if (c->str[c->y_enemy / 50][c->x_enemy / 50] == 'P')
		exit(1);
	return (0);
}
