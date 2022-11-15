/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:31:24 by zouazahr          #+#    #+#             */
/*   Updated: 2022/10/17 16:03:35 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	check_ray(t_image *img, int pixelX, int pixelY)
{
	if (img->map[pixelY / 64][pixelX / 64] == '1')
		return (1);
	return (0);
}

float	calculate_walldistance(t_player *ply)
{
	float	distance;

	distance = sqrtf(((ply->wallx - ply->posx) * (ply->wallx - ply->posx)) + ((ply->wally - ply->posy) * (ply->wally - ply->posy)));
	return (distance);
}

void	set_walls(t_player *ply, float pixelX, float pixelY)
{
	ply->wallx = pixelX;
	ply->wally = pixelY;
	ply->wall_distance = calculate_walldistance(ply);
}

int draw_line(t_image *img, float beginX, float beginY, float endX, float endY)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
	double pixelX = beginX;
	double pixelY = beginY;
	while (1)
	{
		//mlx_pixel_put(img->mlx, img->win, pixelX, pixelY, 0xFFFFFF);
		if (check_ray(img, (int)pixelX, (int)pixelY))
		{
			set_walls(&img->player, pixelX, pixelY);
			break ;
		}
		pixelX += deltaX;
		pixelY += deltaY;
	}
	return (1);
}

void	turnto3d(t_image *img, int j)
{
	int i = 0;
	//float dist_projectpane = (tan(img->player.rotation) / 540);
	double dist_projectpane =  (1920 / 2) / tan(30 * (M_PI / 180));
	printf("Project -> %f\n", dist_projectpane);

	printf("Distance -> %f\n",img->player.wall_distance);
	float projected_wall = (64 / img->player.wall_distance) * dist_projectpane;
	double wallbegin = (1080 / 2) - (projected_wall / 2);
	//int wallend = (projected_wall / 2) + (1080 / 2);
	printf("WALLBEGIN ======== %f **** PROJECTEDWALL ===== %f\n", wallbegin, projected_wall);
	printf("1 I => %d\n", i);
	while (i < 1080 && i < wallbegin)
	{
 		mlx_pixel_put(img->mlx, img->win, j, i, 0XFFFF00);
		i++;	
	}
	printf("2 I => %d\n", i);
	while (i < 1080 && i < wallbegin + projected_wall)
	{
		mlx_pixel_put(img->mlx, img->win, j, i, 0X000000);
		i++;
	}
	printf("3 I => %d\n", i);
	while (i < 1080 && i < 1080)
	{
		mlx_pixel_put(img->mlx, img->win, j, i, 0XFFFF00);
		i++;
	}
}

void	ft_init_img(t_info *map, t_image *ply)
{
	int	image_width;
	int	image_height;

	//int i = -1;
	//int j;
	ply->image_space = mlx_xpm_file_to_image(ply->mlx, map->so, &image_height, &image_width);
	ply->image_wall = mlx_xpm_file_to_image(ply->mlx, map->no, &image_height, &image_width);
	ply->image_player = mlx_xpm_file_to_image(ply->mlx, "./executer/images/salute.xpm", &image_height, &image_width);
	// while (map->land[++i])
	// {
	// 	j = 0;
	// 	while (map->land[i][j])
	// 	{
	// 		if (map->land[i][j] == '1')
	// 			mlx_put_image_to_window(ply->mlx, ply->win, ply->image_wall, j * 64, i * 64);
	// 		if (map->land[i][j] == '0' || map->land[i][j] == map->direction)
	// 			mlx_put_image_to_window(ply->mlx, ply->win,ply->image_space, j * 64, i * 64);		
	// 		j++;
	// 	}
	// }
	float angle = (ply->player.rotation - (M_PI / 6));
	int x = 0;
	printf("Widht %f\n", ply->player.rotation + (M_PI / 6));
	while (x <= 1000)
	{
		draw_line(ply,  ply->player.posx + 32, ply->player.posy + 32, 32 + ply->player.posx + cos(angle) * 30,32 + ply->player.posy + sin(angle) * 30);
		turnto3d(ply, x);
		angle += M_PI / 1920;
		printf("Angle -> %f\n", angle);
		x++;
	}
	printf("x %d\n", x);
	// exit(0);
}

char	**ft_strdupc(char **env)
{
	int		i;
	int		lendoub;
	char	**str;

	i = 0;
	if (env == NULL)
		return (NULL);
	lendoub = ft_splen(env);
	str = malloc (sizeof(char *) * (lendoub + 1));
	if (str == 0)
	{
		free(str);
		return (NULL);
	}
	while (i < lendoub)
	{
		str[i] = ft_strdup(env[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

void	initialize(char *c, t_image *ply)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(ply->mlx, c, &img_width, &img_height);
	mlx_put_image_to_window(ply->mlx, ply->win, img, ply->x, ply->y);
}

void	check_rotation(t_info *map, t_player *player)
{
	if (map->direction == 'N')
		player->rotation = 3 * M_PI / 2;
	else if (map->direction == 'S')
		player->rotation = M_PI / 2;
	else if (map->direction == 'W')
		player->rotation = M_PI;
	else
		player->rotation = M_PI * 2;
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
				img->player.posx = j * 64;
				img->player.posy = i * 64;
				check_rotation(map, &img->player);
			}
			j++;
		}
		i++;
	}
}

void rotate_left(t_image *ply, t_player *player)
{
	ft_init_img((*ply).info, ply);
	player->rotation += (-1) * (2 * M_PI / 180);
	// float angle = (ply->player.rotation - (M_PI / 6));
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image_player, ply->player.posx, ply->player.posy);
	// while (angle <= ply->player.rotation + (M_PI / 6))
	// {
	// 	draw_line(ply,  player->posx + 32, player->posy + 32, 32 + player->posx + cos(angle) * 30,32 + player->posy + sin(angle) * 30, angle);
	// 	angle += M_PI / 1920;
	// }
}

void rotate_right(t_image *ply, t_player *player)
{
	ft_init_img((*ply).info, ply);
	player->rotation += (1) * (2 * M_PI / 180);
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image_player, ply->player.posx, ply->player.posy);
}

void move_front(t_image *ply)
{
	int	image_height;
	int	image_width;
	int	posx;
	int	posy;

	//mlx_destroy_image(ply->win, ply->image_player);
	ft_init_img((*ply).info, ply);
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image_space, ply->player.posx, ply->player.posy);
	posy = sin(ply->player.rotation) * 7;
	posx = cos(ply->player.rotation) * 7;
	if (ply->map[(int)(((ply->player.posy + posy) / 64))][(int)(((ply->player.posx + posx)/ 64))] == '0')
	{
		ply->player.posy += posy;
		ply->player.posx += posx;
	}
	ply->image_player = mlx_xpm_file_to_image(ply->mlx, "./executer/images/salute.xpm", &image_height, &image_width);
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image_player, ply->player.posx, ply->player.posy);
}

void move_back(t_image *ply)
{
	int	image_height;
	int	image_width;
	int	posx;
	int	posy;

	posy = sin(ply->player.rotation) * 7;
	posx = cos(ply->player.rotation) * 7;
	//mlx_destroy_image(ply->win, ply->image_player);
	ft_init_img((*ply).info, ply);
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image_space, ply->player.posx, ply->player.posy);
	if (ply->map[(int)(((ply->player.posy - posy) / 64))][(int)(((ply->player.posx - posx) / 64))] == '0')
	{
		ply->player.posy -=posy;
		ply->player.posx -= posx;
	}
	ply->image_player = mlx_xpm_file_to_image(ply->mlx, "./executer/images/salute.xpm", &image_height, &image_width);
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image_player, ply->player.posx, ply->player.posy);
}

void move_right(t_image *ply)
{
	int	image_height;
	int	image_width;
	int	posx;
	int	posy;

	//mlx_destroy_image(ply->mlx, ply->image_player);
	ft_init_img((*ply).info, ply);
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image_space, ply->player.posx, ply->player.posy);
	posx = cos(ply->player.rotation + (3 * M_PI) / 2) * 7;
	posy = sin(ply->player.rotation + (3 * M_PI) / 2) * 7;
	if (ply->map[(int)(((ply->player.posy - posy) / 64))][(int)(((ply->player.posx - posx)/ 64))] == '0')
	{
		ply->player.posx -= posx;
		ply->player.posy -= posy;
	}
	ply->image_player = mlx_xpm_file_to_image(ply->mlx, "./executer/images/salute.xpm", &image_height, &image_width);
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image_player, ply->player.posx, ply->player.posy);
}

void move_left(t_image *ply)
{
	int	image_height;
	int	image_width;
	int	posx;
	int	posy;

	//mlx_destroy_image(ply->win, ply->image_player);
	ft_init_img((*ply).info, ply);
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image_space, ply->player.posx, ply->player.posy);
	posx = cos(ply->player.rotation + (3 * M_PI) / 2) * 7;
	posy = sin(ply->player.rotation + (3 * M_PI) / 2) * 7;
	if (ply->map[(int)(((ply->player.posy + posy) / 64))][(int)(((ply->player.posx + posx)/ 64))] == '0')
	{
		ply->player.posx += posx;
		ply->player.posy += posy;
	}
	ply->image_player = mlx_xpm_file_to_image(ply->mlx, "./executer/images/salute.xpm", &image_height, &image_width);
	mlx_put_image_to_window(ply->mlx, ply->win, ply->image_player, ply->player.posx, ply->player.posy);
}

int	ft_test(int key, t_image *img)
{
	//if (key == 2 && g_str[g_pos_pl.x][g_pos_pl.y + 1] != '1')
	//	move_right(key, ++g_move);
//	if (key == 13 && g_str[g_pos_pl.x - 1][g_pos_pl.y] != '1')
//		move_up(key, ++g_move);

	//float angle = (img->player.rotation - (M_PI / 6));
	// while (angle <= ply->player.rotation + (M_PI / 6))
	// {
	// 	angle += ((M_PI / 3) / 1920);
	// }
	
	if (key == 124)
	{
		rotate_right(img, &img->player);
		//draw_line(img,  img->player.posx + 32, img->player.posy + 32, 32 + img->player.posx + cos(angle) * 30,32 + img->player.posy + sin(angle) * 30, img->player.rotation);
	}
	if (key == 123)
	{
		rotate_left(img, &img->player);
		//draw_line(img,  img->player.posx + 32, img->player.posy + 32, 32 + img->player.posx + cos(angle) * 30,32 + img->player.posy + sin(angle) * 30, img->player.rotation);
	}
	if (key == 13)
	{
		move_front(img);
		//draw_line(img,  img->player.posx + 32, img->player.posy + 32, 32 + img->player.posx + cos(angle) * 30,32 + img->player.posy + sin(angle) * 30, img->player.rotation);
	}
	if (key == 1)
	{
		move_back(img);
		//draw_line(img,  img->player.posx + 32, img->player.posy + 32, 32 + img->player.posx + cos(angle) * 30,32 + img->player.posy + sin(angle) * 30, img->player.rotation);
	}
	if (key == 0)
 		move_left(img);
	if (key == 2)
		move_right(img);
	if (key == 53)
	{
	// 	ft_free_it();
	 	exit(0);
	}
	return (1);
}

int	exit_s(void)
{
	exit(0);
}

void	execute(t_image *map)
{
	int			i;
	int			j;

	i = -1;
	j = 0;
	ft_getpos_player(map->info, map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1920, 1080, "Test");
	map->map = ft_strdupc(map->info->land);
	ft_init_img((*map).info, map);
	i = 0;
	mlx_put_image_to_window(map->mlx, map->win, map->image_player, map->player.posx, map->player.posy);
	mlx_hook(map->win, 17, 0, exit_s, NULL);
	mlx_key_hook(map->win, ft_test, map);
	mlx_loop(map->mlx);
}
