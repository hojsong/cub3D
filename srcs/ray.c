/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:42:48 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/28 14:56:38 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_sky(t_game *game, int idx, int wall_top)
{
	int	x;
	int	y;

	y = 0;
	while (y < wall_top)
	{
		x = 0;
		while (x < 1)
		{
			if (game->img.data[game->win_width * y + (x + idx * 1)] == 0x111110)
				game->img.data[game->win_width * y + (x + idx * 1)] = \
				create_rgb(game->colors[1].r, game->colors[1].g, \
				game->colors[1].b);
			x++;
		}
		y++;
	}
}

void	draw_land(t_game *game, int idx, int wall_bottom)
{
	int	x;
	int	y;

	y = wall_bottom;
	while (y < game->win_height)
	{
		x = 0;
		while (x < 1)
		{
			if (game->img.data[game->win_width * y + (x + idx * 1)] == 0x111110)
				game->img.data[game->win_width * y + (x + idx * 1)] = \
				create_rgb(game->colors[0].r, game->colors[0].g, \
				game->colors[0].b);
			x++;
		}
		y++;
	}
}

void	draw_one_ray(t_game *game, double angle, int i)
{
	t_disposable_ray	horz;
	t_disposable_ray	vert;

	init_ray(&(game->ray), angle);
	cal_horz(game, &horz);
	cal_vert(game, &vert);
	if (vert.distance < horz.distance)
	{
		game->ray.wall_hitx = vert.wall_hitx;
		game->ray.wall_hity = vert.wall_hity;
		game->ray.distance = vert.distance;
		game->ray.was_hit_vert = TRUE;
	}
	else
	{
		game->ray.wall_hitx = horz.wall_hitx;
		game->ray.wall_hity = horz.wall_hity;
		game->ray.distance = horz.distance;
		game->ray.was_hit_vert = FALSE;
	}
	render_3d(game, i);
}

void	draw_ray(t_game *game)
{
	double	angle;
	double	ray_range;
	int		i;

	ray_range = game->fov;
	angle = game->player.rotate_angle - (ray_range / 2);
	i = -1;
	while (++i < game->ray_cnt)
	{
		draw_one_ray(game, angle, i);
		angle += ray_range / (double)game->ray_cnt;
	}
}
