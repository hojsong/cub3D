/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:34:04 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/26 13:40:58 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	update_move_xy(t_game *game)
{
	double	move;

	move = 0;
	if (game->key.left == 1 && game->key.up == 1)
		move = 1;
	else if (game->key.right == 1 && game->key.up == 1)
		move = -1;
	else if (game->key.right == 1 && game->key.down == 1)
		move = -1;
	else if (game->key.left == 1 && game->key.down == 1)
		move = 1;
	else if (game->key.left == 1 && game->key.right == 0)
		move = 1;
	else if (game->key.right == 1 && game->key.left == 0)
		move = -1;
	else if (game->key.up == 1 && game->key.down == 0)
		move = 1;
	else if (game->key.down == 1 && game->key.up == 0)
		move = -1;
	return (move);
}

double	update_move_dir(t_game *game)
{
	double	dir;

	dir = 0;
	if (game->key.left == 1 && game->key.up == 1)
		dir = PI / 4;
	else if (game->key.right == 1 && game->key.up == 1)
		dir = PI / 4 * 3;
	else if (game->key.right == 1 && game->key.down == 1)
		dir = PI / 4;
	else if (game->key.left == 1 && game->key.down == 1)
		dir = PI / 4 * 3;
	else if (game->key.left == 1 && game->key.right == 0)
		dir = PI / 2.0;
	else if (game->key.right == 1 && game->key.left == 0)
		dir = PI / 2.0;
	return (dir);
}

int	update_turn(t_game *game)
{
	double	move;

	move = 0;
	if (game->key.turn_left == 1 && game->key.turn_right == 0)
		move = -1;
	else if (game->key.turn_right == 1 && game->key.turn_left == 0)
		move = 1;
	return (move);
}

double	*update_move(t_game *game)
{
	double	*ret;

	ret = malloc(sizeof(double) * 2);
	if (ret == NULL)
		return (NULL);
	ret[0] = update_move_xy(game);
	ret[1] = update_move_dir(game);
	return (ret);
}
