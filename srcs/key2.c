/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:54:45 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/26 18:54:05 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	move_chk(double x, double y, char **map)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	if (map[my][mx] == '1')
		return (1);
	return (0);
}

int	hj_move_chk(double x, double y, t_game *game, int dir)
{
	double	co;
	double	si;
	int		direction;
	int		result;

	direction = (int)(game->player.rotate_angle / PI * 180) % 90;
	co = cos((double)direction * PI / 180.0) * game->player.walk_speed;
	si = sin((double)direction * PI / 180.0) * game->player.walk_speed;
	if (dir == 0)
		result = move_chk(((x + co) / game->tile_size) + (0.3 * co), \
		((y + si) / game->tile_size) + (0.3 * si), game->map);
	else if (dir == 1)
		result = move_chk(((x - si) / game->tile_size) - (0.3 * si), \
		((y + co) / game->tile_size) + (0.3 * si), game->map);
	else if (dir == 2)
		result = move_chk(((x - co) / game->tile_size) - (0.3 * co), \
		((y - si) / game->tile_size) - (0.3 * si), game->map);
	else
		result = move_chk(((x + si) / game->tile_size) + (0.3 * si), \
		((y - co) / game->tile_size) - (0.3 * co), game->map);
	return (result);
}

void	move_exe(t_player *player, double sx, double cy, t_game *game)
{
	player->location.x += (game->player.walk_speed * sx);
	player->location.y += (game->player.walk_speed * cy);
}

void	hj_move_math(t_game *game, int key)
{
	int		direction;
	int		dir;
	int		p_dir;

	if (hj_move_chk(game->player.location.x, game->player.location.y \
	, game, key) == 0)
		return ;
	p_dir = (int)(game->player.rotate_angle * 180 / PI);
	dir = (key + (p_dir / 90)) % 4;
	direction = (p_dir) % 90;
	if (dir == 0)
		move_exe(&game->player, cos((double)direction * PI / 180), \
			sin((double)direction * PI / 180), game);
	else if (dir == 1)
		move_exe(&game->player, -1 * sin((double)direction * PI / 180), \
			cos((double)direction * PI / 180), game);
	else if (dir == 2)
		move_exe(&game->player, -1 * cos((double)direction * PI / 180), \
			-1 * sin((double)direction * PI / 180), game);
	else if (dir == 3)
		move_exe(&game->player, sin((double)direction * PI / 180), \
			-1 * cos((double)direction * PI / 180), game);
}

int	hj_key_exe(int key, t_game *game)
{
	if (key < 4)
		hj_move_math(game, key);
	return (0);
}
