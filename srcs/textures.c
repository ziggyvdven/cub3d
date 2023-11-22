/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:47:10 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/17 14:47:51 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	generate_textures(void)
{
	data()->texture[0] = *mlx_load_png("./textures/wood.png");
	data()->texture[1] = *mlx_load_png("./textures/mossy.png");
	data()->texture[2] = *mlx_load_png("./textures/eagle.png");
	data()->texture[3] = *mlx_load_png("./textures/redbrick.png");
	printf("width = %d height = %d\n", data()->texture[0].width, data()->texture[0].height);
}
