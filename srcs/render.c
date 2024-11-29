/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:41 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/28 15:08:45 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	update_player(t_game *game)
{
	double	*move;
	double	real_turn;
	double	real_move;
	double	x;
	double	y;

	move = update_move(game);
	real_turn = update_turn(game);
	game->player.rotate_angle += real_turn * game->player.turn_speed;
	real_move = move[0] * game->player.walk_speed;
	x = game->player.location.x + real_move * \
	cos(game->player.rotate_angle - move[1]) * 1.2;
	y = game->player.location.y + real_move * \
	sin(game->player.rotate_angle - move[1]) * 1.2;
	if (!is_wall(game, x, y))
	{
		game->player.location.x = x;
		game->player.location.y = y;
	}
	free(move);
	return (0);
}

void	render_background(t_game *game)
{
	int	col;
	int	row;

	row = 0;
	while (row < game->win_height)
	{
		col = 0;
		while (col < game->win_width)
		{
			game->img.data[game->win_width * row + col] = 0x111110;
			col++;
		}
		row++;
	}
}

void	render_3d(t_game *game, int idx)
{
	t_cal	cal;

	if (game->ray.distance == 0)
		game->ray.distance = 0.1;
	cal.correct_length = game->ray.distance * \
	cos(game->ray.ray_angle - game->player.rotate_angle);
	cal.distance_plane = (game->win_width / 2) / tan(game->fov / 2);
	cal.wall_strip_height = (int)((game->tile_size / cal.correct_length) \
	* cal.distance_plane);
	cal.wall_top = (game->win_height / 2) - (cal.wall_strip_height / 2);
	if (cal.wall_top < 0)
		cal.wall_top_adjust = 1;
	else
		cal.wall_top_adjust = cal.wall_top;
	cal.wall_bottom = (game->win_height / 2) + (cal.wall_strip_height / 2);
	if (cal.wall_bottom > game->win_height)
		cal.wall_bottom_adjust = game->win_height;
	else
		cal.wall_bottom_adjust = cal.wall_bottom;
	cal.wall_height = cal.wall_bottom - cal.wall_top;
	fill_wall(game, cal, idx);
}
