/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:51:35 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/12/02 17:32:02 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calc_wall_height(int side)
{
	int			lineheight;
	double		perpwalldist;

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
	ray()->perpwalldist = perpwalldist;
}

double	calc_texx(double perpwalldist, int side)
{
	double	wallx;
	int		texx;

	if (side == 0)
		wallx = pos()->y + ray()->raydiry * perpwalldist;
	else
		wallx = pos()->x + ray()->raydirx * perpwalldist;
	wallx -= floor((wallx));
	texx = (((int)(wallx * (double)TEXWIDTH)));
	return (texx);
}

int	get_pixel_colour(int texy, int texx, int side)
{
	int			r;
	int			g;
	int			b;
	int			tex;

	tex = set_texture(ray()->mapx, ray()->mapy, side);
	texx *= 4;
	texy *= 4;
	r = data()->texture[tex]->pixels[TEXHEIGHT * texy + texx];
	g = data()->texture[tex]->pixels[TEXHEIGHT * texy + texx + 1];
	b = data()->texture[tex]->pixels[TEXHEIGHT * texy + texx + 2];
	return (get_rgba(r, g, b, 255));
}

void	draw_walls(int drawstart, int drawend, int x, int side)
{
	u_int32_t	colour;
	int			texx;
	int			texy;
	double		step;
	double		texpos;

	texx = calc_texx(ray()->perpwalldist, side);
	step = (1.0 * TEXHEIGHT / ray()->lineheight);
	texpos = (drawstart - SCREENHEIGHT / 2 + ray()->lineheight / 2) * step;
	if (drawstart <= drawend)
	{
		while (drawstart < drawend)
		{
			texy = ((int)texpos & (TEXHEIGHT - 1));
			texpos += step;
			colour = get_pixel_colour(texy, texx, side);
			mlx_put_pixel(data()->buf, x, drawstart, colour);
			drawstart++;
		}
	}
}
