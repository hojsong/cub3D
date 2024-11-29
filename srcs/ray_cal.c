/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:47:50 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/28 14:58:07 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cal_distance(t_game *game, t_disposable_ray *ray)
{
	if (ray->is_wallhit == TRUE)
	{
		ray->distance = distance(game->player.location.x, \
		game->player.location.y, ray->wall_hitx, ray->wall_hity);
		if (ray->distance == 0)
			ray->distance = 0.1;
	}
	else
		ray->distance = DBL_MAX;
}

void	cal_ray(t_game *game, t_disposable_ray *ray, int horz, int vert)
{
	double	next_touch_x;
	double	next_touch_y;

	next_touch_x = ray->xintercept;
	next_touch_y = ray->yintercept;
	while (next_touch_x >= 0 && next_touch_x <= game->win_width \
	&& next_touch_y >= 0 && next_touch_y <= game->win_height)
	{
		if (is_wall(game, next_touch_x + vert, next_touch_y + horz))
		{
			ray->is_wallhit = TRUE;
			ray->wall_hitx = next_touch_x;
			ray->wall_hity = next_touch_y;
			break ;
		}
		else
		{
			next_touch_x += ray->xstep;
			next_touch_y += ray->ystep;
		}
	}
	cal_distance(game, ray);
}

int	modify_value(int check)
{
	if (check == 1)
		return (-1);
	return (0);
}

void	cal_vert(t_game *game, t_disposable_ray *vert)
{
	vert->is_wallhit = FALSE;
	vert->wall_hitx = 0;
	vert->wall_hity = 0;
	vert->xintercept = floor(game->player.location.x / \
	game->tile_size) * game->tile_size;
	if (game->ray.is_ray_right)
		vert->xintercept += game->tile_size;
	vert->yintercept = game->player.location.y + (vert->xintercept \
	- game->player.location.x) * tan(game->ray.ray_angle);
	vert->xstep = game->tile_size;
	if (game->ray.is_ray_left)
		vert->xstep *= -1;
	vert->ystep = game->tile_size * tan(game->ray.ray_angle);
	if (game->ray.is_ray_up && vert->ystep > 0)
		vert->ystep *= -1;
	if (game->ray.is_ray_down && vert->ystep < 0)
		vert->ystep *= -1;
	cal_ray(game, vert, 0, modify_value(game->ray.is_ray_left));
}

void	cal_horz(t_game *game, t_disposable_ray *horz)
{
	horz->is_wallhit = FALSE;
	horz->wall_hitx = 0;
	horz->wall_hity = 0;
	horz->yintercept = floor(game->player.location.y / \
	game->tile_size) * game->tile_size;
	if (game->ray.is_ray_down)
		horz->yintercept += game->tile_size;
	horz->xintercept = game->player.location.x + (horz->yintercept \
	- game->player.location.y) / tan(game->ray.ray_angle);
	horz->ystep = game->tile_size;
	if (game->ray.is_ray_up)
		horz->ystep *= -1;
	horz->xstep = game->tile_size / tan(game->ray.ray_angle);
	if (game->ray.is_ray_left && horz->xstep > 0)
		horz->xstep *= -1;
	if (game->ray.is_ray_right && horz->xstep < 0)
		horz->xstep *= -1;
	cal_ray(game, horz, modify_value(game->ray.is_ray_up), 0);
}
