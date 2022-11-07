/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:29:44 by iharile           #+#    #+#             */
/*   Updated: 2022/11/07 16:36:20 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header.h"

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
	if (map->info != NULL)
		free(map->info);
	if (map->player != NULL)
		free(map->player);
	if (map->image != NULL)
		free(map->player);
	free(map);
}

int	main(int ac, char **av)
{
	int		fd;
	t_image	*map;

	map = malloc(sizeof(t_image));
	if (ac != 2)
		msg_exit("\033[0;32mput the map as aregement!!\033[0m;");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		msg_exit("\033[0;31mthis file not exist\033[0;m");
	close (fd);
	check_extension(av[1]);
	map->info = NULL;
	map->info = check_map(av[1], map->info);
	// this for test
	printf ("NORTH:%s\n", map->info->no);
	printf ("SOUTH:%s\n", map->info->so);
	printf ("EAST : %s\n", map->info->ea);
	printf ("WEAST:%s\n", map->info->we);
	int j = -1;
	printf ("F: ");
	while (++j < 3)
		printf ( "%d ", map->info->f[j]);
	j = -1;
	printf ("\nC: ");
	while (++j < 3)
		printf ("%d ", map->info->c[j]);
	printf ("\nhex f: %d\nhex c: %d\n", map->info->hexfloor, map->info->hexceilling);
	printf ("direction %c\n", map->info->direction);
	j = -1;
	printf ("land:\n");
	while (map->info->land[++j])
		printf (">%s<\n", map->info->land[j]);
	execute(map);
	free_struct(map->info);
	free_struct2(map);
	printf("hello\n");
	return (0);
}
