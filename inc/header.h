/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:37:21 by iharile           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/15 18:29:47 by zouazahr         ###   ########.fr       */
=======
/*   Updated: 2022/11/10 14:53:33 by iharile          ###   ########.fr       */
>>>>>>> 49b491b3a64a0dd52d9ddca3a54b4ce497346a1e
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H 

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include <mlx.h>
<<<<<<< HEAD

=======
>>>>>>> 49b491b3a64a0dd52d9ddca3a54b4ce497346a1e
# define FIELD_OF_VIEW 60;
# define PLAYER_HEIGHT 32;
# define WIN_H 1080.0
# define WIN_W 1920.0
# define HALF_WALL 30.0
# define WALL_DIM 64.0

typedef struct information
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	direction;
	int		f[3];
	int		c[3];
	int		hexfloor;
	int		hexceilling;
	char	**land;
}	t_info;

typedef struct player
{
	double		posx;
	double		posy;
	double		pdx;
	double		pdy;
	double		wallx;
	double		wally;
	char		wall_direct;
	int			turn_direct;
	int			walk_direct;
	double		rotation;
	int			turn_direction;
	int			move_direction;
	double		wall_distance;
	double		proj_w;
	double		wallbegin;
	int			where;
	double		stepx;
	double		stepy;
	char		line;
}	t_player;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
	char	*addr_north;
	int		bpp_n;
	int		length_n;
	int		endian_n;
	char	*addr_south;
	int		bpp_s;
	int		length_s;
	int		endian_s;
	char	*addr_east;
	int		bpp_e;
	int		length_e;
	int		endian_e;
	char	*addr_west;
	int		bpp_w;
	int		length_w;
	int		endian_w;
}				t_data;

typedef struct s_image
{
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	int				row;
	int				col;
	void			*wall_north;
	void			*wall_south;
	void			*wall_east;
	void			*wall_west;
	char			*addr_space;
	char			*addr_player;
	int				bits_pixel;
	int				endian;
	int				l;
	int				h_n;
	int				w_n;
	int				h_s;
	int				w_s;
	int				h_w;
	int				w_w;
	int				h_e;
	int				w_e;
	t_player		*player;
	t_info			*info;
	t_data			*image;
	char			**map;
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
void	free_and_msg(char **m1, char **m2, char *s1, char *msg);
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
void	check_objects(char *s, int j);
int		norm_floor_ceilling(char *af_sp, t_info *map, char c, char *bf_sp);
int		floor_ceilling(char *s, t_info *map, char c);
void	land_newlines(char *s, char *main_str);
void	land_surrounded_walls(char *s, char *main_str);
char	land_numbers(char *s, char *main_str);
void	land_holes(char *s, char *main_str);
void	land_zero_invalid_place(char *s, char *main_str);
int		check_hole(char **s, int row, int col);
char	*copy_before_space(char *s);
char	*copy_after_space(char *s, char *bf);
int		count_until_space(char *s);
int		free_return(char **db_str, char *str1, char *str2, int ret);
int		dfs(char *s, char c);
int		hex(int *arr);
char	*fd_texture(char *str, char *after, t_info *map);
void	player_surrounded(char *str, char *main_str, char c);
void	all_things_of_land(char *s, char *main_str);
/*inside main.c: to find end of objects in map*/
int		index_end_objects(char **divide_lines);
/*insdier handle_objects to find if some object is null*/
int		check_before_after(char *bf, char *af);
//executer
void	free_struct2(t_image *map);
void	move_left(t_image *ply);
void	move_right(t_image *ply);
void	move_back(t_image *ply);
void	move_front(t_image *ply);
void	check_rotation(t_info *map, t_player *player);
int		check_ray(t_image *img, int pixelX, int pixelY);
double	calculate_walldistance(t_player *ply, double angle);
void	checkwall_n(t_player *ply, int i, t_image *im);
void	checkwall_s(t_player *ply, int i, t_image *im);
void	set_walls(t_image *img, double pixelX, double pixelY, double angle);
void	pixel_fill_n(t_image *img, int i, int j, int y1);
void	pixel_fill_e(t_image *img, int i, int j, int y1);
void	pixel_fill_s(t_image *img, int i, int j, int y1);
void	pixel_fill_w(t_image *img, int i, int j, int y1);
int		ceiling_floor(t_image *img, int j, int i, int nbr);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	**ft_strdupc(char **env);
int		ft_test(int key, t_image *img);
int		exit_s(void);
void	init_walls(t_image *map);
void	rotate_left(t_player *player);
void	rotate_right(t_player *player);
int		draw_line(t_image *img, double beginX, double beginY, double angle);
void	turnto3d(t_image *img, int j);
void	ft_init_img(t_image *ply);
void	ft_getpos_player(t_info *map, t_image *img);
void	execute(t_image *map);
int		wallcheck(double x, double y, t_image *img);
#endif