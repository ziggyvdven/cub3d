/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:11:32 by lfrank            #+#    #+#             */
/*   Updated: 2023/11/15 11:13:04 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_replace_by_zeros(t_map_parse *map_parse)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map_parse->exec_map[y])
	{
		x = 0;
		while (map_parse->exec_map[y][x])
		{
			if (map_parse->exec_map[y][x] != '1'
				&& map_parse->exec_map[y][x] != '\n')
			{
				map_parse->exec_map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	ft_convert_map(t_map_parse *map_parse)
{
	int	map_size;
	int	exec_map_size;

	map_size = ft_array_len(map_parse->map);
	exec_map_size = map_size - 1 - map_parse->lastidentline;
	map_parse->exec_map = (char **)ft_calloc(exec_map_size + 1, sizeof(char *));
	while (map_size > map_parse->lastidentline + 1)
	{
		map_parse->exec_map[exec_map_size - 1] = ft_strdup
			(map_parse->map[map_size - 1]);
		map_size--;
		exec_map_size--;
	}
	map_parse->player_y = map_parse->player_y - map_parse->lastidentline - 1;
	ft_replace_by_zeros(map_parse);
}
