/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hj_util3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:54:47 by hojsong           #+#    #+#             */
/*   Updated: 2023/03/28 14:21:04 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_error_exit_game(t_game *game, char *str, int exit_code)
{
	if (str != NULL)
		hj_putstr_fd(str, 2);
	if (game)
		ft_free_of_game(game);
	exit(exit_code);
}

void	colors_free(t_color **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		if (colors[i])
			free(colors[i]);
		i++;
	}
	free(colors);
}

void	wall_free(t_wall *wall)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (wall[i].texture)
			free(wall[i].texture);
	}
	free(wall);
}

void	ft_free_of_game(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->img.img)
		free(game->img.img);
	if (game->img.data)
		free(game->img.data);
	if (game->map)
		all_free(game->map);
	if (game->colors)
		free(game->colors);
	if (game->wall)
		wall_free(game->wall);
}

void	init_checker(t_game *game)
{
	if (game->player.location.x == -1)
		ft_error_exit_game(game, "Error\nWrong Player\n", 1);
	if (game->map == NULL)
		ft_error_exit_game(game, "Error\nWrong Map\n", 1);
	if (game->wall[0].texture == NULL)
		ft_error_exit_game(game, "Error\nEmpty or Wrong North Wall\n", 1);
	if (game->wall[1].texture == NULL)
		ft_error_exit_game(game, "Error\nEmpty or Wrong South Wall\n", 1);
	if (game->wall[2].texture == NULL)
		ft_error_exit_game(game, "Error\nEmpty or Wrong West Wall\n", 1);
	if (game->wall[3].texture == NULL)
		ft_error_exit_game(game, "Error\nEmpty or Wrong East Wall\n", 1);
	if (game->colors[0].r == -1 || \
	game->colors[0].g == -1 || game->colors[0].b == -1)
		ft_error_exit_game(game, "Error\nEmpty or Wrong Floor Color\n", 1);
	if (game->colors[1].r == -1 || \
	game->colors[1].g == -1 || game->colors[1].b == -1)
		ft_error_exit_game(game, "Error\nEmpty or Wrong Ceiling Color\n", 1);
}
