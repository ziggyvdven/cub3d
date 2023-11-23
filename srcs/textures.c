/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:47:10 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/22 18:58:31 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	generate_textures(t_map_parse *map)
{
	data()->texture[0] = *mlx_load_png(map->texture_no);
	data()->texture[1] = *mlx_load_png(map->texture_so);
	data()->texture[2] = *mlx_load_png(map->texture_we);
	data()->texture[3] = *mlx_load_png(map->texture_ea);
}
