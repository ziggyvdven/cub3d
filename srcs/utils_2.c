/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:14:57 by lfrank            #+#    #+#             */
/*   Updated: 2023/11/23 17:22:32 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_str_replace(char *str, char *to_replace, char *replace_with)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == to_replace[j] && str[i] && to_replace[j])
		{
			i++;
			j++;
		}
		if (to_replace[j] == '\0')
			ft_replace_algo(&str, to_replace, replace_with, i);
		j = 0;
		i++;
	}
	return (str);
}

//debug
void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		printf("%s\n", array[i++]);
}

int	get_mapwidth(char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x])
	{
		x++;
	}
	return (x);
}

int	get_mapheight(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
	{
	}
	return (y);
}
