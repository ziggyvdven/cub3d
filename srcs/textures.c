/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:47:10 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/24 14:50:19 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	generate_textures(t_map_parse *map)
{
	data()->texture[0] = *mlx_load_png(map->texture_so);
	data()->texture[1] = *mlx_load_png(map->texture_no);
	data()->texture[2] = *mlx_load_png(map->texture_ea);
	data()->texture[3] = *mlx_load_png(map->texture_we);
	data()->texture[4] = *mlx_load_png("./textures/hand.png");
}

int	set_texture(int mapx, int mapy, int side)
{
	if (side == 1)
	{
		if (pos()->y >= mapy)
			return (0);
		if (pos()->y <= mapy)
			return (1);
	}
	if (side == 0)
	{
		if (pos()->x >= mapx)
			return (2);
		if (pos()->x <= mapx)
			return (3);
	}
	return (0);
}

void create_hand(void)
{
	static int	y = 0;
	static int	up = 0;

	if (y == 0)
		up = 1;
	if (!overlay()->hand)
	{
		overlay()->hand = mlx_texture_to_image
		(data()->mlx, &data()->texture[4]);
		mlx_image_to_window(data()->mlx, overlay()->hand,
			(SCREENWIDTH / 2) + SCREENWIDTH * 0.1,
			SCREENHEIGHT - overlay()->hand->height);
	}
	// if (key()->is_moving == false)
	// 	return;
	// if (y <= 50 && up)
	// {
	// 	overlay()->hand->instances[0].y += 1;
	// 	y++;
	// }
	// if (y >= 0 && !up)
	// {
	// 	overlay()->hand->instances[0].y -= 1;
	// 	y--;
	// }
	// if (y == 49)
	// 	up = 0;
}


