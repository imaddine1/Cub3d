/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:47:26 by zouazahr          #+#    #+#             */
/*   Updated: 2022/11/08 11:17:29 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	check_ray(t_image *img, int pixelX, int pixelY)
{
	int	x;
	int	y;

	x = (int)round(pixelX) / 64;
	y = (int)round(pixelY) / 64;
	if (img->map[y][x] == '1' || img->map[(int)
		(pixelY - (int)round(img->player->stepy))
			/ (int)WALL_DIM][x] == '1' || img->map[y]
			[(pixelX - (int)round(img->player->stepx)) / (int)WALL_DIM] == '1')
		return (1);
	return (0);
}

double	calculate_walldistance(t_player *ply, double angle)
{
	double	distance;
	double	ca;

	distance = sqrt(((ply->posx - ply->wallx)
				* (ply->posx - ply->wallx))
			+ ((ply->posy - ply->wally) * (ply->posy - ply->wally)));
	ca = ply->rotation - angle;
	if (ca > (2 * M_PI))
		ca -= (2 * M_PI);
	if (ca < 0)
		ca += (2 * M_PI);
	return (distance * cos(ca));
}

void	checkwall_n(t_info *img, t_player *ply, int i)
{
	if (((int)(ply->wally + 1) % 64) == 0
		&& img->land[(int)(ply->wally / WALL_DIM) + 1] != '\0'
				&& img->land[(int)(ply->wally / WALL_DIM) + 1]
				[(int)(ply->wallx / WALL_DIM)] == '0')
	{
		ply->wall_direct = 'N';
		ply->where = ply->wallx;
	}
	else
	{
		ply->where = ply->wally;
		if (i == 0)
			ply->wall_direct = 'E';
		else
			ply->wall_direct = 'W';
	}
}

void	checkwall_s(t_info *img, t_player *ply, int i)
{
	if (((int)(ply->wally) % 64) == 0
		&& (img->land[(int)(ply->wally / WALL_DIM) - 1] != '\0'
		&& img->land[(int)(ply->wally / WALL_DIM) - 1]
				[(int)(ply->wallx / WALL_DIM)] == '0'))
	{
		ply->wall_direct = 'S';
		ply->where = ply->wallx;
	}
	else
	{
		ply->where = ply->wally;
		if (i == 0)
			ply->wall_direct = 'E';
		else
			ply->wall_direct = 'W';
	}
}

void	set_walls(t_image *img, double pixelX, double pixelY, double angle)
{
	img->player->wally = pixelY;
	img->player->wallx = pixelX;
	img->player->wall_distance = calculate_walldistance(img->player, angle);
	if (img->player->posy > img->player->wally)
	{
		if (img->player->posx <= img->player->wallx)
			checkwall_n(img->info, img->player, 0);
		else if (img->player->posx > img->player->wallx)
			checkwall_n(img->info, img->player, 1);
	}
	else
	{
		if (img->player->posx < img->player->wallx)
			checkwall_s(img->info, img->player, 0);
		else if (img->player->posx >= img->player->wallx)
			checkwall_s(img->info, img->player, 1);
	}
}
