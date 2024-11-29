/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   hj_pasing_player.c						:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/10 15:34:39 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/03/10 17:57:54 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		hj_player_chk(char **map);
int		hj_player_chk(char **map);
double	hj_dir_chk(char c);
void	hj_player_create(t_player *player, char **map, t_game *game);

void	hj_pasing_player(char **map, t_game *game, t_player *player)
{
	int			chk;

	init_player(game, player);
	chk = hj_player_chk(map);
	if (chk == 0)
		ft_error_exit_game(game, "Error\nEmpty Player\n", 1);
	else if (chk != 1)
		ft_error_exit_game(game, "Error\nToo Many Player\n", 1);
	else
		hj_player_create(player, map, game);
}

void	hj_player_create(t_player *player, char **map, t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' || \
				map[y][x] == 'S' || map[y][x] == 'W')
			{
				player->location.x = ((double)x + 0.5) * game->tile_size;
				player->location.y = ((double)y + 0.5) * game->tile_size;
				player->rotate_angle = hj_dir_chk(map[y][x]);
				map[y][x] = '0';
			}
			else if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != ' ' \
			&& (map[y][x] < 9 || map[y][x] > 13))
				ft_error_exit_game(game, "Error\nInvalid argus\n", 1);
		}
	}
}

double	hj_dir_chk(char c)
{
	double	result;

	result = 0;
	if (c == 'E')
		result = (double)0 / (double)360 * PI * 2;
	else if (c == 'S')
		result = (double)90 / (double)360 * PI * 2;
	else if (c == 'W')
		result = (double)180 / (double)360 * PI * 2;
	else if (c == 'N')
		result = (double)270 / (double)360 * PI * 2;
	return (result);
}

int	hj_player_chk(char **map)
{
	int	result;
	int	x;
	int	y;

	result = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' || \
				map[y][x] == 'S' || map[y][x] == 'W')
				result++;
			x++;
		}
		y++;
	}
	return (result);
}
