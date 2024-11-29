/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:04:07 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/27 15:37:44 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_h(char *str)
{
	int	idx;
	int	ret;

	idx = -1;
	ret = 1;
	while (str[++idx])
	{
		if (str[idx] == '\n')
			ret++;
	}
	return (ret);
}

void	init_player(t_game *game, t_player *player)
{
	player->location.x = -1;
	player->location.y = -1;
	player->rotate_angle = PI / 2;
	player->walk_speed = 2;
	player->turn_speed = 1 * (PI / 180);
	game->player_dir.x = 1;
	game->player_dir.y = 0;
	game->plane.x = 0;
	game->plane.y = 0.66;
}

double	normalize_angle(double angle)
{
	if (angle >= 0)
	{
		while (angle >= PI * 2)
			angle -= PI * 2;
	}
	else
	{
		while (angle <= 0)
			angle += PI * 2;
	}
	return (angle);
}

void	init_ray(t_ray *ray, double angle)
{
	ray->ray_angle = normalize_angle(angle);
	ray->wall_hitx = 0;
	ray->wall_hity = 0;
	ray->distance = 0;
	ray->was_hit_vert = FALSE;
	if (ray->ray_angle > 0 && ray->ray_angle < PI)
	{
		ray->is_ray_down = 1;
		ray->is_ray_up = 0;
	}
	else
	{
		ray->is_ray_down = 0;
		ray->is_ray_up = 1;
	}
	if (ray->ray_angle < 0.5 * PI || ray->ray_angle > 1.5 * PI)
	{
		ray->is_ray_right = 1;
		ray->is_ray_left = 0;
	}
	else
	{
		ray->is_ray_right = 0;
		ray->is_ray_left = 1;
	}
}
