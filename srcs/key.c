/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:36:39 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/26 13:08:45 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->key.left = 0;
	if (keycode == KEY_D)
		game->key.right = 0;
	if (keycode == KEY_W)
		game->key.up = 0;
	if (keycode == KEY_S)
		game->key.down = 0;
	if (keycode == KEY_LEFT)
		game->key.turn_left = 0;
	if (keycode == KEY_RIGHT)
		game->key.turn_right = 0;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->key.left = 1;
	if (keycode == KEY_D)
		game->key.right = 1;
	if (keycode == KEY_W)
		game->key.up = 1;
	if (keycode == KEY_S)
		game->key.down = 1;
	if (keycode == KEY_LEFT)
		game->key.turn_left = 1;
	if (keycode == KEY_RIGHT)
		game->key.turn_right = 1;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
