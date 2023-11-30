/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:24:02 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/30 14:25:40 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_map_end(char **map, int y, int x)
{
	if (get_mapheight(map) <= y || y <= 0)
		return (1);
	else if (get_max_mapwidth(map) <= x || x <= 0)
		return (1);
	return (0);
}

void	calc_ray_dir(int x)
{
	double	camx;

	camx = 2.0 * x / (double)SCREENWIDTH - 1.0;
	ray()->raydirx = dir()->x + plane()->x * camx;
	if (ray()->raydirx == 0.0)
		ray()->deltax = 1e30;
	else
		ray()->deltax = fabs(1.0 / ray()->raydirx);
	ray()->raydiry = dir()->y + plane()->y * camx;
	if (ray()->raydiry == 0.0)
		ray()->deltay = 1e30;
	else
		ray()->deltay = fabs(1.0 / ray()->raydiry);
}

void	set_step(void)
{
	if (ray()->raydirx < 0.0)
		ray()->stepx = -1.0;
	else
		ray()->stepx = 1.0;
	if (ray()->raydiry < 0.0)
		ray()->stepy = -1.0;
	else
		ray()->stepy = 1.0;
}

void	calc_sidedist(int posx, int posy)
{
	ray()->mapx = posx;
	ray()->mapy = posy;
	if (ray()->raydirx < 0.0)
		ray()->sidedistx = (pos()->x - (double)ray()->mapx) * ray()->deltax;
	else
		ray()->sidedistx = ((double)ray()->mapx + 1.0 - pos()->x)
		* ray()->deltax;
	if (ray()->raydiry < 0.0)
		ray()->sidedisty = (pos()->y - (double)ray()->mapy) * ray()->deltay;
	else
		ray()->sidedisty = ((double)ray()->mapy + 1.0 - pos()->y)
		* ray()->deltay;
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
		if (ft_check_map_end(wm()->map, ray()->mapy, ray()->mapx))
			hit = 1;
		else if (wm()->map[ray()->mapy][ray()->mapx] == '1')
			hit = 1;
	}
	return (side);
}

void	ft_raycaster(void *param)
{
	int		x;
	int		side;
	mlx_t	*mlx;

	x = -1;
	side = 0;
	mlx = param;
	ft_ctrls(mlx);
	ft_minimap();
	empty_img_buffer(data()->buf);
	ft_mouse(mlx);
	while (++x < SCREENWIDTH)
	{
		calc_ray_dir(x);
		set_step();
		calc_sidedist((int)pos()->x, (int)pos()->y);
		side = dda(ray()->deltax, ray()->deltay, ray()->stepx, ray()->stepy);
		calc_wall_height(side);
		draw_walls(ray()->drawstart,
			ray()->drawend, SCREENWIDTH - x - 1, side);
	}
}
