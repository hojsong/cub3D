/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_dfs.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/10 16:06:17 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/03/10 18:50:45 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	hj_check_map_all(char **map, t_game *game)
{
	int	i;
	int	i2;

	i = -1;
	while (map[++i])
	{
		i2 = -1;
		while (map[i][++i2])
		{
			if (map[i][i2] != '1' && map[i][i2] != ' ')
			{
				if (map_check(map, i, i2))
				{
					all_free(map);
					ft_error_exit_game(game, "Error\nMap error\n", 1);
				}
			}
		}
		if (game->map_width < i2)
			game->map_width = i2;
	}
	game->map_height = i;
}

int	map_check(char **map, int i, int i2)
{
	if (i == 0 || i2 == 0)
		return (1);
	if (map[i][i2 + 1] == ' ' || map[i][i2 + 1] == '\0')
		return (1);
	if (!map[i + 1] || hj_strlen(map[i + 1]) < i2 || \
		map[i + 1][i2] == ' ' || map[i + 1][i2] == '\0')
		return (1);
	if ((map[i][i2 - 1] == ' ' || map[i][i2 - 1] == '\0'))
		return (1);
	if (hj_strlen(map[i - 1]) < i2 || (map[i - 1][i2] == ' ' || \
		map[i - 1][i2] == '\0'))
		return (1);
	if (!map[i + 1] || hj_strlen(map[i + 1]) < i2 + 1 || \
		map[i + 1][i2 + 1] == ' ' || map[i + 1][i2 + 1] == '\0')
		return (1);
	if (hj_strlen(map[i - 1]) < i2 || (map[i - 1][i2 - 1] == ' ' || \
		map[i - 1][i2 - 1] == '\0'))
		return (1);
	if (!map[i + 1] || hj_strlen(map[i + 1]) < i2 || \
		map[i + 1][i2 - 1] == ' ' || map[i + 1][i2 - 1] == '\0')
		return (1);
	if (hj_strlen(map[i - 1]) < i2 + 1 || (map[i - 1][i2 + 1] == ' ' || \
		map[i - 1][i2 + 1] == '\0'))
		return (1);
	return (0);
}

void	hj_check_push(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == ' ')
			break ;
		*i += 1;
	}
}

char	*is_sp_push_save(char *str)
{
	char	*result;
	int		i;
	int		idx;
	int		size;

	i = 0;
	size = hj_strlen(str);
	while (i < size)
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
			break ;
	}
	if (size == i)
		return (NULL);
	result = malloc(sizeof(char) * (size - i + 1));
	idx = 0;
	while (str[i + idx])
	{
		result[idx] = str[i + idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
