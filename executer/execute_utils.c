/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:50:30 by zouazahr          #+#    #+#             */
/*   Updated: 2022/11/09 17:18:46 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_W || x < 0 || y > WIN_H || y < 0)
		return ;
	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
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

int	ft_test(int key, t_image *img)
{
	mlx_clear_window(img->mlx, img->win);
	if (key == 124)
		rotate_right(img->player);
	if (key == 123)
		rotate_left(img->player);
	if (key == 13)
		move_front(img);
	if (key == 1)
		move_back(img);
	if (key == 0)
		move_left(img);
	if (key == 2)
		move_right(img);
	if (key == 53)
	{
		//system("leaks cub3D");
		exit(0);
	}
	ft_init_img(img);
	return (1);
}

int	exit_s(void)
{
	system("leaks cub3D");
	exit(0);
}

void	init_walls(t_image *map)
{
	int			i;
	int			j;

	map->mlx = mlx_init();
	map->wall_north = mlx_xpm_file_to_image(map->mlx, map->info->no, &i, &j);
	map->wall_south = mlx_xpm_file_to_image(map->mlx, map->info->so, &i, &j);
	map->wall_east = mlx_xpm_file_to_image(map->mlx, map->info->ea, &i, &j);
	map->wall_west = mlx_xpm_file_to_image(map->mlx, map->info->we, &i, &j);
	if (!map->wall_north || !map->wall_east
		|| !map->wall_south || !map->wall_west)
	{
		printf("ERROR! PLEASE CHECK YOUR TEXTURES\n");
		free_struct(map->info);
		free_struct2(map);
		system("leaks cub3D");
		exit (0);
	}
	map->image->addr_north = mlx_get_data_addr(map->wall_north,
			&map->image->bpp_n, &map->image->length_n, &map->image->endian_n);
	map->image->addr_south = mlx_get_data_addr(map->wall_south,
			&map->image->bpp_s, &map->image->length_s, &map->image->endian_s);
	map->image->addr_east = mlx_get_data_addr(map->wall_east,
			&map->image->bpp_e, &map->image->length_e, &map->image->endian_e);
	map->image->addr_west = mlx_get_data_addr(map->wall_west,
			&map->image->bpp_w, &map->image->length_w, &map->image->endian_w);
}
