/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:51:41 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/29 17:30:30 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_loop(void *game_void)
{
	t_game	*game;

	game = game_void;
	game->img.data = (int *)mlx_get_data_addr(game->img.img, \
	&(game->img.bpp), &(game->img.line_size), &(game->img.endian));
	update_player(game);
	render_background(game);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	*make_texture(t_game *game, void *img)
{
	int		*texture;
	int		row;
	int		col;
	t_img	buffer_img;

	texture = malloc(sizeof(int) * 64 * 64);
	if (texture == NULL)
		return (NULL);
	buffer_img.data = (int *)mlx_get_data_addr(img, &buffer_img.bpp, \
	&buffer_img.line_size, &buffer_img.endian);
	row = -1;
	while (++row < 64)
	{
		col = -1;
		while (++col < 64)
			texture[row * 64 + col] = buffer_img.data[row * 64 + col];
	}
	mlx_destroy_image(game->mlx, img);
	return (texture);
}

int	fill_texture(t_game *game, int real_row, t_cal cal)
{
	int	col;
	int	row;
	int	direction;

	direction = find_dir(game);
	if (direction == 3 || direction == 2)
		col = ((int)game->ray.wall_hity % game->tile_size) \
		* (64.0 / game->tile_size);
	else
		col = ((int)game->ray.wall_hitx % game->tile_size) \
		* (64.0 / game->tile_size);
	row = (cal.wall_top_adjust - cal.wall_top + real_row) * \
	64 / cal.wall_height;
	if (direction == 2 || direction == 1)
		return (game->wall[direction].texture[row * 64 + (63 - col)]);
	return (game->wall[direction].texture[row * 64 + col]);
}

void	fill_wall(t_game *game, t_cal cal, int idx)
{
	int		x;
	int		y;
	int		real_row;

	real_row = 0;
	y = cal.wall_top_adjust - 1;
	while (++y < cal.wall_bottom_adjust)
	{
		x = -1;
		while (++x < WALL_WIDTH)
		{
			if (game->img.data[game->win_width * y + (x + idx * WALL_WIDTH)] \
			== 0x111110)
				game->img.data[game->win_width * y + (x + idx * WALL_WIDTH)] = \
				fill_texture(game, real_row, cal);
		}
		real_row++;
	}
	draw_sky(game, idx, cal.wall_bottom_adjust);
	draw_land(game, idx, cal.wall_top_adjust);
}
