/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgbuffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:29 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/10 16:46:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_background(mlx_t *mlx)
{
	mlx_image_t	*background;
	int32_t		x;
	int32_t		y;
	int32_t		floor;
	int32_t		ceiling;

	if (!mlx)
		return ;
	floor = get_rgba(180, 180, 180, 255);
	ceiling = get_rgba(0, 50, 255, 255);
	y = -1;
	background = mlx_new_image(mlx, SCREENWIDTH, SCREENHEIGHT);
	mlx_image_to_window(mlx, background, 0, 0);
	while (y++ < SCREENHEIGHT)
	{
		x = -1;
		while (x++ < SCREENWIDTH && y < SCREENHEIGHT - 1)
		{
			if (y < SCREENHEIGHT / 2)
				mlx_put_pixel(background, x, y, ceiling);
			else
				mlx_put_pixel(background, x, y, floor);
		}
		if (y % (SCREENHEIGHT / 255) == 0)
			ceiling = math_rgba(ceiling, 1, SUB);
		if (y % (SCREENHEIGHT / 255) == 0)
			floor = math_rgba(floor, 1, ADD);
	}
}

void	create_img_buffer(mlx_t *mlx)
{
	mlx_image_t	*buf;

	if (!mlx)
		return ;
	create_background(mlx);
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
