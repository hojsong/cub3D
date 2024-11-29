/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:03:30 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/29 17:30:32 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2 || open(av[1], O_RDONLY) == -1)
		return (error_return("Error\nWrong argv", 1));
	if (hj_strrcmp(av[1], ".cub"))
		ft_error_exit("Error\nWrong extension\n", 1);
	game = hj_pasing(ac, av);
	game->img.img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	mlx_hook(game->win, 17, 0, goodbye, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, ft_loop, game);
	mlx_loop(game->mlx);
	ft_free_of_game(game);
}
