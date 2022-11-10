/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:47:17 by zouazahr          #+#    #+#             */
/*   Updated: 2022/11/10 14:41:30 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	check_line(t_image *img, float x_end, float y_end)
{
	double	pixelx;
	double	pixely;
	double	deltax;
	double	deltay;
	int		pixels;

	deltax = (x_end - img->player->posx);
	deltay = (y_end - img->player->posy);
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = img->player->posx;
	pixely = img->player->posy;
	while (pixels)
	{
		if (wallcheck(pixelx, pixely, img) == 1)
			return (1);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	return (0);
}

void	move_front(t_image *ply)
{
	double	posx;
	double	posy;
	double	coordx;
	double	coordy;

	posx = cos(ply->player->rotation) * 18;
	posy = sin(ply->player->rotation) * 18;
	coordy = (ply->player->posy + posy);
	coordx = (ply->player->posx + posx);
	if (!wallcheck(coordx, coordy, ply) && !check_line(ply,
			ply->player->posx + 40 * cos(ply->player->rotation),
			ply->player->posy + 40 * sin(ply->player->rotation)) && ply->map
		[(int)(ply->player->posy / WALL_DIM)][(int)(coordx / 64)] == '0')
	{
		ply->player->posx += posx;
		ply->player->posy += posy;
	}
}

void	move_back(t_image *ply)
{
	double	posx;
	double	posy;
	double	coordx;
	double	coordy;

	posx = cos(ply->player->rotation) * 18;
	posy = sin(ply->player->rotation) * 18;
	coordy = (ply->player->posy - posy);
	coordx = (ply->player->posx - posx);
	if (!wallcheck(coordx, coordy, ply) && !check_line(ply,
			ply->player->posx - 40 * cos(ply->player->rotation),
			ply->player->posy - 40 * sin(ply->player->rotation)) && ply->map
		[(int)(ply->player->posy / WALL_DIM)][(int)(coordx / 64)] == '0')
	{
		ply->player->posx -= posx;
		ply->player->posy -= posy;
	}
}

void	move_right(t_image *ply)
{
	double	posx;
	double	posy;
	double	coordx;
	double	coordy;
	double	rotation;

	rotation = ply->player->rotation + (3 * M_PI) / 2;
	if (rotation < 0)
		rotation += (2 * M_PI);
	posx = cos(rotation) * 18;
	posy = sin(rotation) * 18;
	coordy = (ply->player->posy - posy);
	coordx = (ply->player->posx - posx);
	if (!wallcheck(coordx, coordy, ply) && !check_line(ply,
			ply->player->posx - 25 * cos(rotation), ply->player->posy - 25
			* sin(rotation)) && ply->map[(int)(coordy / 64)]
			[(int)(ply->player->posx / WALL_DIM)] == '0')
	{
		ply->player->posx -= posx;
		ply->player->posy -= posy;
	}
}

void	move_left(t_image *ply)
{
	double	posx;
	double	posy;
	double	coordx;
	double	coordy;
	double	rotation;

	rotation = ply->player->rotation + (3 * M_PI) / 2;
	if (rotation < 0)
		rotation += (2 * M_PI);
	posx = cos(rotation) * 18;
	posy = sin(rotation) * 18;
	coordy = (ply->player->posy + posy);
	coordx = (ply->player->posx + posx);
	if (!wallcheck(coordx, coordy, ply) && !check_line(ply,
			ply->player->posx + 25 * cos(rotation), ply->player->posy + 25
			* sin(rotation)) && ply->map[(int)(coordy / 64)]
		[(int)(ply->player->posx / WALL_DIM)] == '0')
	{
		ply->player->posx += posx;
		ply->player->posy += posy;
	}
}
