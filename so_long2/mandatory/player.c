/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:37:07 by iharile           #+#    #+#             */
/*   Updated: 2022/03/22 17:19:03 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *str)
{
	int	lengh;

	lengh = ft_strlen(str);
	write(2, str, lengh);
	exit(1);
}

void	move_up(t_img *c)
{
	if (move_isvalid(c, c->str, 'w'))
	{
		ft_print(c->nbr_move++);
		mlx_destroy_image(c->mlx, c->img);
		update (c, "./assets/green.xpm");
		c->str[c->y_player / 50][c->x_player / 50] = '0';
		c->y_player -= 50;
		c->y = c->y_player;
		c->x = c->x_player;
		c->str[c->y_player / 50][c->x_player / 50] = 'P';
		update (c, "./assets/sprit.xpm");
	}
	else
		move_exit(c, 'w');
}

void	move_down(t_img *c)
{
	if (move_isvalid(c, c->str, 's'))
	{
		ft_print(c->nbr_move++);
		mlx_destroy_image(c->mlx, c->img);
		update (c, "./assets/green.xpm");
		c->str[c->y_player / 50][c->x_player / 50] = '0';
		c->y_player += 50;
		c->y = c->y_player;
		c->x = c->x_player;
		c->str[c->y_player / 50][c->x_player / 50] = 'P';
		update (c, "./assets/sprit.xpm");
	}
	else
		move_exit(c, 's');
}

void	move_right(t_img *c)
{
	if (move_isvalid(c, c->str, 'd'))
	{
		ft_print(c->nbr_move++);
		mlx_destroy_image(c->mlx, c->img);
		update (c, "./assets/green.xpm");
		c->str[c->y_player / 50][c->x_player / 50] = '0';
		c->x_player += 50;
		c->y = c->y_player;
		c->x = c->x_player;
		c->str[c->y_player / 50][c->x_player / 50] = 'P';
		update (c, "./assets/sprit.xpm");
	}
	else
		move_exit(c, 'd');
}

void	move_left(t_img *c)
{
	if (move_isvalid(c, c->str, 'a'))
	{
		ft_print(c->nbr_move++);
		mlx_destroy_image(c->mlx, c->img);
		update (c, "./assets/green.xpm");
		c->str[c->y_player / 50][c->x_player / 50] = '0';
		c->x_player -= 50;
		c->y = c->y_player;
		c->x = c->x_player;
		c->str[c->y_player / 50][c->x_player / 50] = 'P';
		update (c, "./assets/sprit.xpm");
	}
	else
		move_exit(c, 'a');
}
