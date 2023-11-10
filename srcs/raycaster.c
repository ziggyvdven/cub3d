/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:24:02 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/10 14:33:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//calculate ray position and direction
void	calc_ray_dir(int x)
{
	double	camx;

	camx = 2 * x / (double)SCREENWIDTH - 1;
	ray()->raydirx = dir()->x + plane()->x * camx;
	if (ray()->raydirx == 0)
		ray()->deltax = 1e30;
	else
		ray()->deltax = fabs(1 / ray()->raydirx);
	ray()->raydiry = dir()->y + plane()->y * camx;
	if (ray()->raydiry == 0)
		ray()->deltay = 1e30;
	else
		ray()->deltay = fabs(1 / ray()->raydiry);
}

void	set_step(void)
{
	if (ray()->raydirx < 0)
		ray()->stepx = -1;
	else
		ray()->stepx = 1;
	if (ray()->raydiry < 0)
		ray()->stepy = -1;
	else
		ray()->stepy = 1;
}

void	calc_sidedist(int posx, int posy)
{
	ray()->mapx = posx;
	ray()->mapy = posy;
	if (ray()->raydirx < 0)
		ray()->sidedistx = (pos()->x - ray()->mapx) * ray()->deltax;
	else
		ray()->sidedistx = (ray()->mapx + 1.0 - pos()->x) * ray()->deltax;
	if (ray()->raydiry < 0)
		ray()->sidedisty = (pos()->y - ray()->mapy) * ray()->deltay;
	else
		ray()->sidedisty = (ray()->mapy + 1.0 - pos()->y) * ray()->deltay;
}

int	dda(double deltax, double deltay, int stepx, int stepy)
{
	int		hit;
	int		side;

	hit = 0;
	while (hit == 0)
	{
		if (ray()->sidedistx < ray()->sidedisty)
		{
			ray()->sidedistx += deltax;
			ray()->mapx += stepx;
			side = 0;
		}
		else
		{
			ray()->sidedisty += deltay;
			ray()->mapy += stepy;
			side = 1;
		}
		if (wm()->map[ray()->mapy][ray()->mapx] > 0)
			hit = 1;
	}
	return (side);
}

void	ft_raycaster(void *param)
{
	int		x;
	int		side;
	int		colour;

	x = -1;
	side = 0;
	(void)param;
	empty_img_buffer(data()->buf);
	while (++x < SCREENWIDTH)
	{
		calc_ray_dir(x);
		set_step();
		calc_sidedist(pos()->x, pos()->y);
		side = dda(ray()->deltax, ray()->deltay, ray()->stepx, ray()->stepy);
		calc_wall_height(side);
		colour = set_colour(ray()->mapx, ray()->mapy, side);
		draw_walls(ray()->drawstart,
			ray()->drawend, SCREENWIDTH - x - 1, colour);
	}
}
