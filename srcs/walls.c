/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:51:35 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/09 16:28:41 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calc_wall_height(int side)
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
}

int	set_colour(int mapx, int mapy, int side)
{
	int	colour;

	printf("mapx = %d mapy = %d\n", mapx, mapy);
	if (side == 1)
	{
		if (pos()->y >= mapy)
		 	colour = get_rgba(255, 0, 0, 255);
		if (pos()->y <= mapy)
			colour = get_rgba(0, 0, 225, 255);
	}
	if (side == 0)
	{
		if (pos()->x >= mapx)
		 colour = get_rgba(225, 165, 0, 255);
		if (pos()->x <= mapx)
			colour = get_rgba(106, 90, 205, 255);
	}
	if (side == 0) 
		colour = div_rgba(colour);
	return (colour);
}

void	draw_walls(int	drawstart, int drawend, int x, int colour)
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

