/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:04:01 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/28 15:06:31 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define TRUE 1
# define FALSE 0

# define BUFFER_SIZE 42

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_UP 	126
# define KEY_DOWN	125

# define PI 3.141592
# define WALL_WIDTH 1
# define DBL_MAX __DBL_MAX__

typedef struct s_disposable_ray
{
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;
	int		is_wallhit;
	double	wall_hitx;
	double	wall_hity;
	double	distance;
}	t_disposable_ray;

typedef struct s_key
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	turn_left;
	int	turn_right;
}	t_key;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_player
{
	t_vec	location;
	double	rotate_angle;
	double	walk_speed;
	double	turn_speed;
}	t_player;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_ray
{
	double	ray_angle;
	double	wall_hitx;
	double	wall_hity;
	double	distance;
	int		was_hit_vert;
	int		is_ray_down;
	int		is_ray_up;
	int		is_ray_left;
	int		is_ray_right;
}	t_ray;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_cal
{
	double	correct_length;
	double	distance_plane;
	int		wall_strip_height;
	int		wall_top;
	int		wall_top_adjust;
	int		wall_bottom;
	int		wall_bottom_adjust;
	int		wall_height;
}	t_cal;

typedef struct s_wall
{
	void	*wall_img;
	int		*texture;
	double	width;
	double	height;
}	t_wall;

typedef struct s_game
{
	int				win_width;
	int				win_height;
	int				map_width;
	int				map_height;
	int				ray_cnt;
	int				tile_size;
	double			fov;
	void			*win;
	void			*mlx;
	char			**map;
	t_wall			*wall;
	t_color			*colors;
	t_player		player;
	t_vec			player_dir;
	t_vec			plane;
	t_img			img;
	t_key			key;
	t_ray			ray;
}	t_game;

size_t			ft_strlen(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char *s1, char const *s2);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strncmp(char *str1, char *str2, int size);
void			*ft_calloc(size_t nelem, size_t elsize);
char			*ft_strtrim(char const *s1, char const *set);

char			*get_next_line(int fd);
t_game			*hj_pasing(int argc, char **argv);
void			hj_pasing_player(char **map, t_game *game, \
t_player *player);
t_game			*hj_pasing(int argc, char **argv);
char			*hj_strjoin(char **str);
void			all_free(char **str);
void			ft_error_exit(char *str, int code);
void			hj_putstr_fd(char *str, int fd);
char			*hj_split_join(char **spstr, int i, char *str);
void			hj_check_map_all(char **map, t_game *game);
void			ft_error_exit(char *str, int code);
void			init_checker(t_game *game);
void			ft_error_exit_game(t_game *game, \
char *str, int exit_code);
int				hj_wall_fc(char **mapfile, t_game *game);
int				hj_wfc_chk1(char *str, t_game *game, int size, int x);
int				hj_wfc_chk2(char *str, t_game *game, int size);
char			*hj_str_n_dup(char *str, int i);
int				hj_strlen(char *str);
char			*hj_strdup(char *str);
int				map_check(char **map, int i, int i2);
void			ft_free_of_game(t_game *game);
int				hj_strrcmp(char *str1, char *str2);
char			*check_map_endl(char *line);
int				hj_map_push(char *str);
char			*is_sp_push_save(char *str);
int				hj_move_chk(double x, double y, t_game *game, int dir);

t_game			*init_game(char *file);
void			init_player(t_game *game, t_player *player);
void			init_ray(t_ray *ray, double angle);
int				goodbye(t_game *game);

void			render_background(t_game *game);
void			render_map(t_game *game);
void			render_3d(t_game *game, int idx);

int				*make_texture(t_game *game, void *img);
int				calculate_tile(t_game *game);

int				ft_loop(void *game_void);

unsigned long	create_rgb(int r, int g, int b);
void			draw_ray(t_game *game);
void			draw_sky(t_game *game, int idx, int wall_top);
void			draw_land(t_game *game, int idx, int wall_bottom);
int				draw_player(t_game *game);
void			fill_wall(t_game *game, t_cal cal, int idx);

void			cal_distance(t_game *game, t_disposable_ray *ray);
void			cal_ray(t_game *game, t_disposable_ray *ray, int horz, \
int vert);
void			cal_vert(t_game *game, t_disposable_ray *vert);
void			cal_horz(t_game *game, t_disposable_ray *horz);
double			distance(double x1, double y1, \
double x2, double y2);
int				is_wall(t_game *game, double x, double y);

int				update_player(t_game *game);
double			*update_move(t_game *game);
int				update_turn(t_game *game);

int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				hj_key_exe(int key, t_game *game);

int				error_return(char *str, int exit);
void			free_game(t_game *game);

int				find_dir(t_game *game);

#endif
