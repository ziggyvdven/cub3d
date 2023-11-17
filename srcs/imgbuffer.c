/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgbuffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:29 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/16 13:37:48 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

mlx_image_t	*create_background_layer(mlx_t *mlx)
{
	mlx_image_t	*layer1;
	mlx_image_t	*layer2;
	int32_t		x;
	int32_t		y;

	layer1 = mlx_new_image(mlx, SCREENWIDTH, SCREENHEIGHT);
	memset(layer1->pixels, 255, SCREENWIDTH
		* layer1->height * sizeof(int32_t));
	y = (SCREENHEIGHT / 2) - 1;
	while (++y < SCREENHEIGHT)
	{
		x = -1;
		while (++x < SCREENWIDTH)
			mlx_put_pixel(layer1, x, y, get_rgba(255, 255, 255, 225));
	}
	mlx_image_to_window(mlx, layer1, 0, 0);
	layer2 = mlx_new_image(mlx, SCREENWIDTH, SCREENHEIGHT);
	mlx_image_to_window(mlx, layer2, 0, 0);
	return (layer2);
}


void	create_background(mlx_t *mlx, int32_t floor, int32_t ceiling)
{
	int32_t		x;
	int32_t		y;
	mlx_image_t	*background;

	if (!mlx)
		return ;
	background = create_background_layer(mlx);
	y = -1;
	while (++y < SCREENHEIGHT)
	{
		x = -1;
		while (++x < SCREENWIDTH)
		{
		//printf("Y = %d A= %d\n", y, get_a(floor));
			if (y < SCREENHEIGHT / 2)
				mlx_put_pixel(background, x, y, ceiling);
			else
				mlx_put_pixel(background, x, y, floor);
		}
		if (y < SCREENHEIGHT / 2 && y > SCREENHEIGHT
			/ 4 && y % ((SCREENHEIGHT / 4) / 255) == 0)
			ceiling = gradient(ceiling, 1, SUB);
		if (y > (SCREENHEIGHT / 2) && y % ((SCREENHEIGHT / 2) / 255) == 0)
		{
			floor = gradient(floor, 1, SUB);
		}
	}
}

void	create_img_buffer(mlx_t *mlx, t_map_parse *map)
{
	mlx_image_t	*buf;

	if (!mlx)
		return ;
	create_background(mlx, map->floor_color, map->ceiling_color);
	buf = mlx_new_image(mlx, SCREENWIDTH, SCREENHEIGHT);
	mlx_image_to_window(mlx, buf, 0, 0);
	data()->buf = buf;
}

void	empty_img_buffer(void *param)
{
	mlx_image_t	*buf;

	buf = param;
	memset(buf->pixels, 0, buf->width
		* buf->height * sizeof(int));
}
