/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:40:06 by zouazahr          #+#    #+#             */
/*   Updated: 2022/11/07 15:37:55 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	pixel_fill_n(t_image *img, int i, int j, int x1)
{
	char	*dst;
	int		y;

	if (img->player->proj_w > WIN_H)
		y = ((int)(round(x1 + (img->player->proj_w - WIN_H) / 2)
					* (2000.0 / img->player->proj_w))) % 2000;
	else
		y = ((int)(round(x1 * (2000.0 / img->player->proj_w))) % 2000);
	dst = (img->image->addr_north + ((y * img->image->length_n
					+ (int)round(img->player->where
						* (img->image->bpp_n / 8)))));
	my_mlx_pixel_put(img->image, j, i, *(unsigned int *)dst);
}

void	pixel_fill_e(t_image *img, int i, int j, int x1)
{
	char	*dst;
	int		y;

	if (img->player->proj_w > WIN_H)
		y = ((int)(round(x1 + (img->player->proj_w - WIN_H) / 2)
					* (2000.0 / img->player->proj_w))) % 2000;
	else
		y = ((int)(round(x1 * (2000.0 / img->player->proj_w))) % 2000);
	dst = (img->image->addr_east + ((y * img->image->length_e
					+ (int)round(img->player->where
						* (img->image->bpp_e / 8)))));
	my_mlx_pixel_put(img->image, j, i, *(unsigned int *)dst);
}

void	pixel_fill_s(t_image *img, int i, int j, int x1)
{
	char	*dst;
	int		y;

	if (img->player->proj_w > WIN_H)
		y = ((int)(round(x1 + (img->player->proj_w - WIN_H) / 2)
					* (2000.0 / img->player->proj_w))) % 2000;
	else
		y = ((int)(round(x1 * (2000.0 / img->player->proj_w))) % 2000);
	dst = (img->image->addr_south + ((y * img->image->length_s
					+ (int)round(img->player->where
						* (img->image->bpp_s / 8)))));
	my_mlx_pixel_put(img->image, j, i, *(unsigned int *)dst);
}

void	pixel_fill_w(t_image *img, int i, int j, int x1)
{
	char	*dst;
	int		y;

	if (img->player->proj_w > WIN_H)
		y = ((int)(round(x1 + (img->player->proj_w - WIN_H) / 2)
					* (2000.0 / img->player->proj_w))) % 2000;
	else
		y = ((int)(round(x1 * (2000.0 / img->player->proj_w))) % 2000);
	dst = (img->image->addr_west + ((y * img->image->length_w
					+ (int)round(img->player->where
						* (img->image->bpp_w / 8)))));
	my_mlx_pixel_put(img->image, j, i, *(unsigned int *)dst);
}

int	ceiling_floor(t_image *img, int j, int i, int nbr)
{
	if (nbr == 0)
	{
		while (i++ < WIN_H && i < img->player->wallbegin)
			my_mlx_pixel_put(img->image, j, i, img->info->hexceilling);
	}
	else
	{
		while (i < WIN_H)
			my_mlx_pixel_put(img->image, j, i++, img->info->hexfloor);
	}
	return (i);
}
