/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:51:35 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/22 18:34:31 by zvan-de-         ###   ########.fr       */
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
	ray()->lineheight = lineheight;
	return (perpwalldist);
}

int	set_texture(int mapx, int mapy, int side, int texnum)
{
	if (side == 1)
	{
		if (pos()->y >= mapy)
			texnum = 0;
		if (pos()->y <= mapy)
			texnum = 1;
	}
	if (side == 0)
	{
		if (pos()->x >= mapx)
			texnum = 2;
		if (pos()->x <= mapx)
			texnum = 3;
	}
	// if (wm()->map[mapy][mapx] == 5)
	// 	colour = get_rgba(0, 255, 0, 255);
	// if (wm()->map[mapy][mapx] == 3)
	// 	colour = get_rgba(0, 0, 255, 255);
	// if (side == 0) 
	// 	colour = math_rgba(colour, 2, DIV);
	return (texnum);
}

void	draw_walls(int drawstart, int drawend, int x, int side, double perpwalldist)
{
	// int		y;
	u_int32_t	colour;
	double		wallx;
	int			texx;
	int			texy;
	int			texnum;
	double		step;
	double		texpos;
	int			r;
	int			g;
	int			b;
	// int			a;

	texnum = 0;
	if (side == 0)
		wallx = pos()->y + ray()->raydiry * perpwalldist;
	else
		wallx = pos()->x + ray()->raydirx * perpwalldist;
	wallx -= floor((wallx));
	texx = (((int)(wallx * (double)TEXWIDTH)));
	// if (side == 1 && ray()->raydirx > 0)
	// 	texx = TEXWIDTH - texx - 1;
	// if (side == 0 && ray()->raydiry < 0)
	// 	texx = TEXWIDTH - texx - 1;
	texnum = set_texture(ray()->mapx, ray()->mapy, side, texnum);
	step = (1.0 * TEXHEIGHT / ray()->lineheight);
	texpos = (drawstart - SCREENHEIGHT / 2 + ray()->lineheight / 2) * step;
	if (drawstart <= drawend)
	{
		while (drawstart < drawend)
		{
			texy = ((int)texpos & (TEXHEIGHT - 1));
			texpos += step;
			// // printf("texy = %d texx = %d step = %.2f\n", texy, texx, step);
			r = data()->texture[texnum].pixels[TEXHEIGHT * (texy * 4) + (texx * 4)];
			g = data()->texture[texnum].pixels[TEXHEIGHT * (texy * 4) + (texx * 4) + sizeof(u_int8_t)];
			b = data()->texture[texnum].pixels[TEXHEIGHT * (texy * 4) + (texx * 4) + (sizeof(u_int8_t) * 2)];
			// a = data()->texture[texnum].pixels[TEXHEIGHT * (texy * 4) + (texx * 4)];
			colour = get_rgba(r, g, b, 255);
			// printf("texture: %d\n",);
			// printf("color = %d\n", colour);
			mlx_put_pixel(data()->buf, x, drawstart, colour);
			drawstart++;
		}
	}
}

