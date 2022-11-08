/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:31:24 by zouazahr          #+#    #+#             */
/*   Updated: 2022/11/08 15:34:10 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	draw_line(t_image *img, double beginX, double beginY, double angle)
{
	double	pixelx;
	double	pixely;

	img->player->stepx = cos(angle);
	img->player->stepy = sin(angle);
	pixelx = beginX;
	pixely = beginY;
	while (1)
	{
		if (wallcheck(pixelx, pixely, img))
		{
			set_walls(img, pixelx, pixely, angle);
			img->player->where = (int)round(img->player->where
					* (2000.0 / WALL_DIM)) % 2000;
			break ;
		}
		pixelx += img->player->stepx;
		pixely += img->player->stepy;
	}
	return (1);
}

void	turnto3d(t_image *img, int j)
{
	int		i;
	double	dist_projectpane;
	int		y1;

	dist_projectpane = (WIN_W / 2.0) / tan(HALF_WALL * (M_PI / 180));
	img->player->proj_w = (WALL_DIM / img->player->wall_distance)
		* dist_projectpane;
	img->player->wallbegin = (WIN_H / 2) - (img->player->proj_w / 2);
	i = ceiling_floor(img, j, 0, 0);
	y1 = 0;
	while (i < WIN_H && i < img->player->wallbegin
		+ img->player->proj_w && y1 < i)
	{
		if (img->player->wall_direct == 'N')
			pixel_fill_n(img, i, j, y1++);
		else if (img->player->wall_direct == 'E')
			pixel_fill_e(img, i, j, y1++);
		else if (img->player->wall_direct == 'S')
			pixel_fill_s(img, i, j, y1++);
		else
			pixel_fill_w(img, i, j, y1++);
		i++;
	}
	i = ceiling_floor(img, j, i, 1);
}

void	ft_init_img(t_image *ply)
{
	int		x;
	double	angle;

	x = 0;
	ply->image->img = mlx_new_image(ply->mlx, WIN_W, WIN_H);
	ply->image->addr = mlx_get_data_addr(ply->image->img, &ply->image->bpp,
			&ply->image->length, &ply->image->endian);
	angle = (ply->player->rotation - (M_PI / 6));
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	if (angle < 0)
		angle += (2 * M_PI);
	while (x < WIN_W)
	{
		draw_line(ply, ply->player->posx, ply->player->posy, angle);
		turnto3d(ply, x);
		angle += (60.0 * (M_PI / 180) / WIN_W);
		if (angle > (2 * M_PI))
			angle -= (2 * M_PI);
		if (angle < 0)
			angle += (2 * M_PI);
		x++;
	}
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image->img, 0, 0);
}

void	ft_getpos_player(t_info *map, t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (map->land[i])
	{
		j = 0;
		while (map->land[i][j])
		{
			if (map->land[i][j] == map->direction)
			{
				map->land[i][j] = '0';
				img->player->posx = j * WALL_DIM;
				img->player->posy = i * WALL_DIM;
				check_rotation(map, img->player);
			}
			j++;
		}
		i++;
	}
}

void	execute(t_image *map)
{
	map->image = malloc(sizeof(t_data));
	map->player = malloc(sizeof(t_player));
	init_walls(map);
	ft_getpos_player(map->info, map);
	map->win = mlx_new_window(map->mlx, WIN_W, WIN_H, "Cub3d");
	map->map = ft_strdupc(map->info->land);
	ft_init_img(map);
	mlx_hook(map->win, 17, 0, exit_s, NULL);
	mlx_hook(map->win, 2, 0, ft_test, map);
	mlx_loop(map->mlx);
}
