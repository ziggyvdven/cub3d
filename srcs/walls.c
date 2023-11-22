/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:51:35 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/22 17:09:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	calc_wall_height(int side)
{
	double		perpwalldist;
	int			lineheight;

	if (side == 0)
		perpwalldist = (ray()->sidedistx - ray()->deltax);
	else
		perpwalldist = (ray()->sidedisty - ray()->deltay);
	lineheight = (int)(SCREENHEIGHT / perpwalldist);
	ray()->drawstart = -lineheight / 2 + SCREENHEIGHT / 2;
	if (ray()->drawstart < 0)
		ray()->drawstart = 0;
	ray()->drawend = lineheight / 2 + SCREENHEIGHT / 2;
	if (ray()->drawend >= SCREENHEIGHT)
		ray()->drawend = SCREENHEIGHT - 1;
	return (perpwalldist);
}

int	set_colour(int mapx, int mapy, int side, double walldist)
{
	int	colour;
	double wallx;

	if (side == 0)
		wallx = pos()->y + walldist * ray()->raydiry;
	else
		wallx = pos()->x + walldist * ray()->raydiry;
	wallx -= floor(wallx);
	if (side == 1)
	{
		if (pos()->y >= mapy)
			colour = get_rgba(255, 82, 63, 255);
		if (pos()->y <= mapy)
			colour = get_rgba(225, 109, 63, 255);
	}
	if (side == 0)
	{
		if (pos()->x >= mapx)
			colour = get_rgba(225, 109, 63, 255);
		if (pos()->x <= mapx)
			colour = get_rgba(255, 82, 63, 255);
	}
	if (wm()->map[mapy][mapx] == 5)
		colour = get_rgba(0, 255, 0, 255);
	if (wm()->map[mapy][mapx] == 3)
		colour = get_rgba(0, 0, 255, 255);
	if (side == 0) 
		colour = math_rgba(colour, 2, DIV);
	if (wallx == 0.0)
		colour = get_rgba(0, 255, 0, 255);
	if (wallx == 1.0)
		colour = get_rgba(0, 255, 0, 255);
	return (colour);
}

void	draw_walls(int drawstart, int drawend, int x, int colour)
{
	if (drawstart <= drawend)
	{
		while (drawstart < drawend)
		{
			mlx_put_pixel(data()->buf, x, drawstart, colour);
			drawstart++;
		}
	}
}

