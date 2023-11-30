/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:53:00 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/30 17:13:56 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_y(int y)
{
	int	map_h;

	map_h = get_mapheight(wm()->map);
	if (y >= map_h || y <= 0)
		return (1);
	return (0);
}

int	check_x(int x)
{
	int	map_w;

	map_w = get_max_mapwidth(wm()->map);
	if (x >= map_w || x <= 0)
		return (1);
	return (0);
}

int	ft_check_map_end(char **map, int y, int x)
{
	if (get_mapheight(map) <= y || y <= 0)
		return (1);
	else if (get_max_mapwidth(map) <= x || x <= 0)
		return (1);
	return (0);
}
