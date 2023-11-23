/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:35 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/23 17:23:01 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

typedef struct s_minimap
{
	mlx_image_t		*map;
	uint32_t		mapwidth;
	uint32_t		mapheight;
	float			xscale;
	float			yscale;
	int				mmapx;
	int				mmapy;
}				t_minimap;

/*UTILS************************************************************************/
void		create_minimap_img(mlx_t *mlx);
void		ft_minimap(void);
int			get_mapheight(char **map);
int			get_mapwidth(char **map, int y);
t_minimap	*mini(void);