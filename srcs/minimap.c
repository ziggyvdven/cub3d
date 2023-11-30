/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:18:16 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/30 14:31:53 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_minimap_img(mlx_t *mlx)
{
	mlx_image_t	*minimap;
	uint32_t	x;
	uint32_t	y;

	y = 0;
	minimap = mlx_new_image(mlx, SCREENWIDTH * 0.2, SCREENHEIGHT * 0.2);
	memset(minimap->pixels, 255, minimap->width
		* minimap->height * sizeof(int32_t));
	mlx_image_to_window(mlx, minimap, 50, SCREENHEIGHT - 250);
	while (y < minimap->height)
	{
		x = 0;
		while (x < minimap->width)
		{
			mlx_put_pixel(minimap, x, y, get_rgba(50, 50, 50, 150));
			x++;
		}
		y++;
	}
	mini()->map = minimap;
}

void	draw_map_cube(uint32_t x, uint32_t y, t_minimap	*m, int color)
{
	uint32_t	i;
	uint32_t	j;

	i = y + 1;
	while (++i < y + m->yscale)
	{
		j = x - 1;
		while (++j < x + m->xscale)
		{
			if (i >= 0 && i < mini()->map->height
				&& j >= 0 && j < mini()->map->width)
				mlx_put_pixel(mini()->map, j, i, color);
		}
	}
}

void	draw_mmap(t_minimap	*m, uint32_t y, double posx, double posy)
{
	uint32_t	x;

	x = -1;
	while (++x < m->mapwidth)
	{
		if (wm()->map[y][x] && wm()->map[y][x] == '1')
		{
			m->mmapx = x * m->xscale;
			m->mmapy = y * m->yscale;
			draw_map_cube(m->mmapx, m->mmapy, m, get_rgba(150, 150, 150, 150));
			draw_map_cube(floor(posx * m->xscale),
				floor(posy * m->yscale), m, get_rgba(50, 50, 50, 150));
			draw_map_cube(floor(pos()->x * m->xscale),
				floor(pos()->y * m->yscale), m, get_rgba(225, 0, 0, 150));
		}
	}
}

void	ft_init_minimap(t_minimap *minimap)
{
	minimap->map = NULL;
	minimap->mapwidth = 0;
	minimap->mapheight = 0;
	minimap->xscale = 0;
	minimap->yscale = 0;
	minimap->mmapx = 0;
	minimap->mmapy = 0;
}

void	ft_minimap(void)
{
	uint32_t		y;
	static double	prev_posx = 0;
	static double	prev_posy = 0;
	t_minimap		m;

	ft_init_minimap(&m);
	if (key()->map_active == FALSE)
		return ;
	m.mapheight = get_mapheight(wm()->map);
	m.yscale = mini()->map->height / (float)m.mapheight;
	y = -1;
	if (!prev_posx)
	{
		prev_posx = pos()->x;
		prev_posy = pos()->y;
	}
	while (++y < m.mapheight)
	{
		m.mapwidth = get_mapwidth(wm()->map, y);
		m.xscale = mini()->map->width / (float)m.mapwidth;
		draw_mmap(&m, y, prev_posx, prev_posy);
	}
	prev_posx = pos()->x;
	prev_posy = pos()->y;
	return ;
}
