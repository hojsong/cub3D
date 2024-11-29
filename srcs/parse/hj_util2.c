/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hj_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:56:28 by hojsong           #+#    #+#             */
/*   Updated: 2023/03/27 18:34:14 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	hj_strrcmp(char *str1, char *str2)
{
	int	i;
	int	i2;

	if (str1 == NULL || str2 == NULL)
		return (1);
	i = 0;
	i2 = 0;
	while (str1[i])
		i++;
	while (str2[i2])
		i2++;
	while (str1[i - 1] == str2[i2 - 1] && i-- > 0 && i2-- > 0)
		;
	if (i != 0 && i2 != 0)
		return (1);
	return (0);
}

void	hj_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_strncmp(char *str1, char *str2, int size)
{
	int	i;

	if (str1 == NULL || str2 == NULL)
		return (1);
	i = 0;
	while (i < size && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

char	*hj_str_n_dup(char *str, int i)
{
	char	*result;
	int		len;
	int		idx;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	len = 0;
	while (str[i + len] && (str[i + len] != ' ' \
	|| (str[i + len] >= 9 && str[i + len] <= 13)))
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (str[i + idx] && (str[i + idx] != ' ' \
	|| (str[i + idx] >= 9 && str[i + idx] <= 13)))
	{
		result[idx] = str[i + idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

char	*hj_split_join(char **spstr, int i, char *str)
{
	char	*result;
	char	*dest;

	result = hj_strdup("");
	while (spstr[i])
	{
		dest = result;
		result = ft_strjoin(dest, spstr[i]);
		free(dest);
		dest = result;
		result = ft_strjoin(dest, str);
		free(dest);
		dest = NULL;
		i++;
	}
	return (result);
}
