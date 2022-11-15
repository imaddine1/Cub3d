/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:29:44 by iharile           #+#    #+#             */
/*   Updated: 2022/10/15 15:26:58 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	free_struct(t_info *map)
{
	if (map->no != NULL)
		free (map->no);
	if (map->so != NULL)
		free (map->so);
	if (map->we != NULL)
		free (map->we);
	if (map->ea != NULL)
		free (map->ea);
	if (map->land != NULL)
	{
		printf ("i free double pointer\n");
		ft_free(map->land);
	}
	free (map);
}

int	main(int ac, char **av)
{
	int		fd;
	t_image	*map = NULL;

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
	printf ("NORTH : %s\n", map->info->no);
	printf ("SOUTH : %s\n", map->info->so);
	printf ("EAST : %s\n", map->info->ea);
	printf ("WEAST : %s\n", map->info->we);
	int j = -1;
	printf ("F: ");
	while (++j < 3)
		printf ( "%d ", map->info->f[j]);
	j = -1;
	printf ("\nC: ");
	while (++j < 3)
		printf ("%d ", map->info->c[j]);
	printf ("\ndirection %c\n", map->info->direction);
	j = -1;
	printf ("land:\n");
	while (map->info->land[++j])
		printf ("%s\n", map->info->land[j]);
	execute(map);
	free_struct(map->info);
	//system ("leaks cub3D");
	return (0);
}
