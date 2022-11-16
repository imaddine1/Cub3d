/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:29:44 by iharile           #+#    #+#             */
/*   Updated: 2022/11/16 17:56:00 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header.h"

int	index_end_objects(char **divide_lines)
{
	int		i;
	char	*trim;

	i = 0;
	while (divide_lines[i])
	{
		trim = ft_strtrim(divide_lines[i], " ");
		if (trim[0] == '1' || trim[0] == '0')
		{
			free (trim);
			return (i);
		}
		free (trim);
		i++;
	}
	return (-1);
}

void	all_things_of_land(char *s, char *main_str)
{
	char	c;

	land_surrounded_walls(s, main_str);
	land_zero_invalid_place(s, main_str);
	c = land_numbers(s, main_str);
	land_newlines(s, main_str);
	player_surrounded(s, main_str, c);
	if (!dfs(s, c))
		free_and_msg(0, 0, main_str,
			"\033[0;31mplayer can access to space\033[0;m");
}

void	free_struct(t_info *map)
{
	if (map->no != NULL)
		free(map->no);
	if (map->so != NULL)
		free(map->so);
	if (map->we != NULL)
		free(map->we);
	if (map->ea != NULL)
		free(map->ea);
	if (map->land != NULL)
		ft_free(map->land);
	free (map);
}

void	free_struct2(t_image *map)
{
	if (map->map != NULL)
		ft_free(map->map);
	if (map->mlx != NULL)
		free(map->mlx);
	if (map->wall_north != NULL)
		free(map->wall_north);
	if (map->wall_south != NULL)
		free(map->wall_south);
	if (map->wall_east != NULL)
		free(map->wall_east);
	if (map->wall_west != NULL)
		free(map->wall_west);
	if (map->player != NULL)
		free(map->player);
	if (map->image != NULL)
		free(map->image);
	free(map);
}

int	main(int ac, char **av)
{
	int		fd;
	t_info	*map;
	t_image	*img;

	if (ac != 2)
		msg_exit("\033[0;32mput the map as aregement!!\033[0m;");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		msg_exit("\033[0;31mthis file not exist\033[0;m");
	close (fd);
	check_extension(av[1]);
	map = NULL;
	map = check_map(av[1], map);
	img = malloc(sizeof(t_image));
	if (!img)
		return (0);
	img->info = map;
	execute(img, map);
	free_struct(map);
	free_struct2(img);
	return (0);
}
