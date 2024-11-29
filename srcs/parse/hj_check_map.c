/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hj_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:24:39 by hojsong           #+#    #+#             */
/*   Updated: 2023/03/28 15:18:22 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	hj_wfc_chk(char	*str, t_game *game, int size)
{
	char	*str2;

	str2 = is_sp_push_save(str);
	if (size < 4 && hj_wfc_chk1(str2, game, size, 0))
	{
		free(str2);
		return (1);
	}
	if (hj_wfc_chk2(str2, game, size))
	{
		free(str2);
		return (1);
	}
	return (0);
}

int	hj_map_push(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
			break ;
	}
	if (str[i])
		return (1);
	return (0);
}

int	hj_wall_fc(char **mapfile, t_game *game)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = 0;
	while (mapfile[i])
	{
		if (hj_wfc_chk(mapfile[i], game, size))
			size++;
		i++;
		if (size == 6)
			break ;
	}
	while (mapfile[i + j])
	{
		if (hj_map_push(mapfile[i + j]))
			break ;
		j++;
	}
	if (j == 0)
		ft_error_exit_game(game, "Error\nMap error\n", 1);
	return (i + j);
}
