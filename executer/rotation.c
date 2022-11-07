/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:53:00 by zouazahr          #+#    #+#             */
/*   Updated: 2022/11/07 16:45:23 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	rotate_left(t_player *player)
{
	player->rotation += (-1) * (10 * M_PI / 180);
	if (player->rotation > (2 * M_PI))
		player->rotation -= (2 * M_PI);
	if (player->rotation < 0)
		player->rotation += (2 * M_PI);
}

void	rotate_right(t_player *player)
{
	player->rotation += (1) * (10 * M_PI / 180);
	if (player->rotation > (2 * M_PI))
		player->rotation -= (2 * M_PI);
	if (player->rotation < 0)
		player->rotation += (2 * M_PI);
}

void	check_rotation(t_info *map, t_player *player)
{
	if (map->direction == 'N')
		player->rotation = M_PI / 2;
	else if (map->direction == 'S')
		player->rotation = (3 * M_PI) / 2;
	else if (map->direction == 'W')
		player->rotation = M_PI;
	else
		player->rotation = M_PI * 2;
}

int	wallcheck(double x, double y, t_image *img)
{
	int	floorx;
	int	floory;

	if (x < 0 || x > WIN_W || y < 0 || y > WIN_H)
		return (1);
	floorx = (int)floor(x / WALL_DIM);
	floory = (int)floor(y / WALL_DIM);
	if (img->info->land[floory][floorx] != '0' || img->map[(int)
		((int)y - (int)round(img->player->stepy))
			/ (int)WALL_DIM][floorx] == '1' || img->map[floory]
			[((int)x - (int)round(img->player->stepx)) / (int)WALL_DIM] == '1')
		return (1);
	return (0);
}
