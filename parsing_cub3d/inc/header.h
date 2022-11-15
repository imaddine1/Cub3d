/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:37:21 by iharile           #+#    #+#             */
/*   Updated: 2022/10/16 17:37:34 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H 
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <mlx.h>
# include <math.h>

/* Parser
	✅ use this function when you finish to deallocate struct 
	✅ handle tabs return error if found
	❌ i need to check if path have spaces
 	❌ check this test
	1111111111111111111
	10000000001100000001
	*❌* you need to check each 0 surrounded by 1 or 0 instead of check space srounded by 1s
	❌ i have SEGV in floor and ceilling like 255,0,1,
*/
/* Execution
	❌ check the path is xpm in function of minilibx
*/
# define FIELD_OF_VIEW 60;
# define PLAYER_HEIGHT 32;

typedef struct information
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	direction;
	int		f[3];
	int		c[3];
	char	**land;
}	t_info;

typedef struct player
{
	float		posx;
	float		posy;
	double		pdx;
	double		pdy;
	float		wallx;
	float		wally;
	int			turn_direct;
	int			walk_direct;
	float		rotation;
	int			turn_direction;
	int			move_direction;
	float		wall_distance;
}	t_player;

typedef struct s_image
{
	void		*mlx;
	void		*img;
	void		*win;
	int			x;
	int			y;
	int			row;
	int			col;
	void		*image_wall;
	void		*image_space;
	void		*image_player;
	char		*addr_wall;
	char		*addr_space;
	char		*addr_player;
	int			bits_pixel;
	int			endian;
	int			l;
	t_player	player;
	t_info		*info;
	char		**map;
}	t_image;

// parser
int		ft_splen(char **s);
void	msg_exit(char *str);
void	check_extension(char *str);
t_info	*check_map(char *s, t_info *map);
void	ft_free(char **s);
int		my_atoi(char *str);
void	take_objects(char *s, t_info *map);
void	free_struct(t_info *map);
void	free_and_msg(char **m1, char **m2, char *s1,  char *msg);
void	norm_walls(char **divide_lines, int i, int j, char *main_str);
void	norm_land_numbers(char *main_str, int j);
int		ft_splen(char **s);
long	sizeof_file(char *s);
void	ft_free(char **s);
void	take_info_by_struct(char *s, t_info *map);
void	take_direction(char *s, t_info *map);
void	take_land(char *s, t_info *map);
void	take_objects(char *s, t_info *map);
char	**matrixdup(char **s);
int		check_each_object(char *s, t_info *map);
void	check_objects(char *s);
int		norm_floor_ceilling(char *s, t_info *map, char c, char **double_str);
int		floor_ceilling(char *s, t_info *map, char c);
void	land_newlines(char *s, char *main_str);
void	land_surrounded_walls(char *s, char *main_str);
char	land_numbers(char *s, char *main_str);
void	land_holes(char *s, char *main_str);
int		check_hole(char **s, int row, int col);

//executer
void	ft_init_img(t_info *info, t_image *new);
void	initialize(char *c, t_image *ply);
void	ft_getpos_player(t_info *map, t_image *img);
void	execute(t_image *map);

#endif