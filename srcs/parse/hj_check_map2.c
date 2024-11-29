/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hj_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:24:39 by hojsong           #+#    #+#             */
/*   Updated: 2023/03/28 15:11:19 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		hj_wfc_chk2(char *str, t_game *game, int size);
void	*hj_wall_init(t_game *game, char *str);
t_color	hj_col_init(char *str);
int		hj_col_atoi(char *str, int *i);

int	hj_wfc_chk1(char *str, t_game *game, int size, int x)
{
	char	*stx;

	if (ft_strncmp(str, "NO ", 3) == 0)
		x = 0;
	else if (ft_strncmp(str, "SO ", 3) == 0)
		x = 1;
	else if (ft_strncmp(str, "WE ", 3) == 0)
		x = 2;
	else if (ft_strncmp(str, "EA ", 3) == 0)
		x = 3;
	else if (str == NULL || str[0] == 0)
		return (0);
	else
		x = 10;
	stx = hj_str_n_dup(str, 3);
	if (hj_strrcmp(stx, ".xpm") || size != x)
	{
		free(stx);
		ft_error_exit_game(game, "Error\nWrong Wall\n", 1);
	}
	game->wall[x].wall_img = hj_wall_init(game, stx);
	if (game->wall[x].wall_img == NULL)
		return (1);
	game->wall[x].texture = make_texture(game, game->wall[x].wall_img);
	return (1);
}

int	hj_wfc_chk2(char *str, t_game *game, int size)
{
	game->colors[size - 4].r = -1;
	if (ft_strncmp(str, "F ", 2) == 0 && size == 4)
		game->colors[0] = hj_col_init(ft_strdup(str));
	else if (ft_strncmp(str, "C ", 2) == 0 && size == 5)
		game->colors[1] = hj_col_init(ft_strdup(str));
	else if (str == NULL || str[0] == 0)
		return (0);
	return (1);
}

void	*hj_wall_init(t_game *game, char *str)
{
	void	*result;
	int		img_width;
	int		img_height;

	result = mlx_xpm_file_to_image(game->mlx, str, \
			&img_width, &img_height);
	free(str);
	return (result);
}

t_color	hj_col_init(char *str)
{
	t_color	result;
	int		i;

	i = 2;
	result.r = hj_col_atoi(str, &i);
	if (str[i] == ',')
		i++;
	result.g = hj_col_atoi(str, &i);
	if (str[i] == ',')
		i++;
	result.b = hj_col_atoi(str, &i);
	if (str[i])
		result.b = -1;
	free(str);
	return (result);
}

int	hj_col_atoi(char *str, int *i)
{
	int	result;

	result = -1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		*i += 1;
	if (str[*i] >= '0' && str[*i] <= '9')
		result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = (result * 10) + (str[*i] - '0');
		*i += 1;
	}
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		*i += 1;
	if (result <= 255 && (str[*i] == ',' || str[*i] == '\0'))
		return (result);
	return (-1);
}
