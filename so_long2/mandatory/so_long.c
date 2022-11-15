/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:24:35 by iharile           #+#    #+#             */
/*   Updated: 2022/10/07 17:57:02 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_image(t_img *c, char **s)
{
	c->str = s;
	c->mlx = mlx_init();
	c->row = count_line(s);
	c->col = ft_strlen(*s);
	c->mlx_win = mlx_new_window(c->mlx, c->col * 50, c->row * 50, "So_long!");
	c->x = 0;
	c->y = 0;
	c->i = -1;
	c->y_player = 0;
	c->x_player = 0;
	c->nbr_move = 1;
}

void	initialize(char *path, t_img **c)
{
	void	*img;

	img = mlx_xpm_file_to_image((*c)->mlx, path, &(*c)->h, &(*c)->w);
	if (ft_strcmp(path, "./assets/sprit.xpm") == 0)
	{
		(*c)->x_player = (*c)->x;
		(*c)->y_player = (*c)->y;
		(*c)->img = img;
	}
	mlx_put_image_to_window((*c)->mlx, (*c)->mlx_win, img, (*c)->x, (*c)->y);
}

int	key_hook(int keycode, t_img *c)
{
	if (keycode == 53)
	{
		mlx_destroy_window(c->mlx, c->mlx_win);
		exit(0);
	}
	else if (keycode == 13)
		move_up(c);
	else if (keycode == 1)
		move_down(c);
	else if (keycode == 0)
		move_left(c);
	else if (keycode == 2)
		move_right(c);
	return (0);
}

void	create_window(t_img *c, char ch)
{
	if (ch != '1')
		initialize("./assets/green.xpm", &c);
	if (ch == '1')
		initialize("./assets/ground.xpm", &c);
	else if (ch == 'E')
		initialize("./assets/exit.xpm", &c);
	else if (ch == 'C')
		initialize("./assets/coin.xpm", &c);
	else if (ch == 'P')
		initialize("./assets/sprit.xpm", &c);
}

void	so_long(char **str)
{
	t_img	c;

	initialize_image(&c, str);
	while (str[++c.i])
	{
		c.j = 0;
		c.x = 0;
		while (str[c.i][c.j])
		{
			create_window(&c, str[c.i][c.j]);
			c.x += 50;
			c.j++;
		}
		c.y += 50;
	}
	mlx_key_hook(c.mlx_win, key_hook, &c);
	mlx_hook(c.mlx_win, 17, 0L, closegame, &c);
	mlx_loop(c.mlx);
}
// exit == 53
// w == 13
// a == 0
// d == 2
// s == 1