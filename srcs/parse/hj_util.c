/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   hj_util.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/10 16:02:29 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/03/10 18:08:48 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*hj_strdup(char *str)
{
	char	*result;
	int		i;
	int		size;

	size = hj_strlen(str);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

int	hj_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*hj_strjoin(char **str)
{
	char	*dest;
	char	*result;
	int		i;

	result = hj_strdup("");
	i = 0;
	while (str[i])
	{
		dest = result;
		result = ft_strjoin(dest, str[i]);
		free(dest);
		dest = NULL;
		i++;
	}
	free(dest);
	return (result);
}

void	all_free(char **str)
{
	int	i;

	if (!str[0])
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	ft_error_exit(char *str, int code)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(code);
}
