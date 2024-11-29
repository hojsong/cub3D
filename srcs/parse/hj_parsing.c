/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   hj_pasing.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/10 15:34:39 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/03/10 17:57:54 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**hj_save_map(int fd);
int		hj_map_chk_1(char *map);

char	**hj_pasing_map(int fd, t_game *game)
{
	char	**result;
	char	**mapfile;
	char	*check_map;
	int		i;

	mapfile = hj_save_map(fd);
	if (mapfile == NULL)
		ft_error_exit_game(game, "Error\nfile error\n", 1);
	i = hj_wall_fc(mapfile, game);
	if (mapfile[i] == NULL)
	{
		all_free(mapfile);
		ft_error_exit_game(game, "Error\nMap error\n", 1);
	}
	check_map = hj_split_join(mapfile, i, "\n");
	if (hj_map_chk_1(check_map))
		ft_error_exit_game(game, "Error\nMap error\n", 1);
	result = ft_split(check_map, '\n');
	hj_check_map_all(result, game);
	all_free(mapfile);
	free(check_map);
	return (result);
}

char	**hj_save_map(int fd)
{
	char	*line;
	char	*save_line;
	char	*gnl;
	char	**map;

	save_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = check_map_endl(line);
		gnl = save_line;
		save_line = ft_strjoin(gnl, line);
		free(gnl);
		free(line);
	}
	map = ft_split(save_line, '\n');
	free(save_line);
	return (map);
}

int	hj_map_chk_1(char *map)
{
	char	**str2;
	char	*str;
	int		i;

	str2 = ft_split(map, ' ');
	if (str2 == NULL)
		return (1);
	str = hj_strjoin(str2);
	all_free(str2);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (i > 0 && str[i - 1] == '\n' && \
				(str[i + 1] != '\n' && str[i + 1] != '\0'))
			{
				free(str);
				return (1);
			}
		}
		i++;
	}
	free(str);
	return (0);
}

void	game_init(t_game *game)
{
	int	i;

	game->fov = 60 * (PI / 180.0);
	game->wall = malloc(sizeof(t_wall) * 4);
	if (game->wall == NULL)
		return ;
	i = -1;
	while (++i < 4)
		game->wall[i].texture = NULL;
	game->colors = malloc(sizeof(t_color) * 2);
	if (game->colors == NULL)
		return ;
	game->map = NULL;
	game->key.down = 0;
	game->key.up = 0;
	game->key.left = 0;
	game->key.right = 0;
	game->key.turn_left = 0;
	game->key.turn_right = 0;
	game->img.img = NULL;
	game->img.data = NULL;
}

t_game	*hj_pasing(int argc, char **argv)
{
	t_game	*game;	
	int		fd;

	if (argc != 2)
		ft_error_exit("Error\narguments is not 2\n", 1);
	fd = open(argv[1], O_RDONLY | 0644);
	if (fd == -1)
		ft_error_exit("Error\nfile open error\n", 1);
	game = malloc(sizeof(t_game) * 1);
	if (game == NULL)
		return (NULL);
	game->mlx = mlx_init();
	game_init(game);
	game->map = hj_pasing_map(fd, game);
	if (game == NULL)
		return (NULL);
	game->tile_size = calculate_tile(game);
	game->win_width = game->map_width * game->tile_size;
	game->win_height = game->map_height * game->tile_size;
	hj_pasing_player(game->map, game, &(game->player));
	game->win = mlx_new_window(game->mlx, game->win_width, \
	game->win_height, "cub3D");
	game->ray_cnt = game->win_width / 1;
	init_checker(game);
	return (game);
}
