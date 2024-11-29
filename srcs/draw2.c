/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:10:47 by hojsong           #+#    #+#             */
/*   Updated: 2023/03/26 07:11:12 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_dir(t_game *game)
{
	int	result;

	if (game->ray.was_hit_vert)
	{
		if (game->ray.wall_hitx - game->player.location.x < 0)
			result = 2;
		else
			result = 3;
	}
	else
	{
		if (game->ray.wall_hity - game->player.location.y < 0)
			result = 0;
		else
			result = 1;
	}
	return (result);
}
