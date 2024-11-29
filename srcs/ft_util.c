/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:58:07 by hoslim            #+#    #+#             */
/*   Updated: 2023/03/27 15:25:16 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = malloc(elsize * nelem);
	if (!tmp)
		return (0);
	i = 0;
	while (i < elsize)
		tmp[i++] = 0;
	return (tmp);
}

int	calculate_tile(t_game *game)
{
	int	ret;

	ret = 32;
	while (ret > 10 && game->map_height * ret < 800.0)
		ret++;
	while (ret > 10 && game->map_width * ret < 1280.0)
		ret++;
	while (ret > 10 && game->map_height * ret > 800.0)
		ret--;
	while (ret > 10 && game->map_width * ret > 1280.0)
		ret--;
	return (ret);
}

char	*check_map_endl(char *line)
{
	char	*result;
	int		i;
	int		line_size;

	if (ft_strchr(line, '\n') == 0)
		return (line);
	else
	{
		line_size = hj_strlen(line);
		result = malloc(sizeof(char) * (line_size + 2));
		if (result == NULL)
			return (NULL);
		i = -1;
		while (++i < line_size - 1)
			result[i] = line[i];
		result[i] = ' ';
		result[i + 1] = '\n';
		result[i + 2] = '\0';
	}
	free(line);
	return (result);
}
