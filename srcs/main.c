/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:51:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/09 16:51:48 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_direction(int d)
{
	if (d == WEST)
	{
		dir()->x = -1;
		dir()->y = 0;
		plane()->x = 0;
		plane()->y = 0.66;
	}
	if (d == SOUTH)
	{
		dir()->x = 0;
		dir()->y = 1;
		plane()->x = 0.66;
		plane()->y = 0;
	}
	if (d == EAST)
	{
		dir()->x = 1;
		dir()->y = 0;
		plane()->x = 0;
		plane()->y = -0.66;
	}
	if (d == NORTH)
	{
		dir()->x = 0;
		dir()->y = -1;
		plane()->x = -0.66;
		plane()->y = 0;
	}
}

void	set_values(int dir)
{
	pos()->x = 2;
	pos()->y = 12;
	set_direction(dir);
	data()->time = 0;
	data()->oldtime = 0;
	return ;
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;

	(void)argv;
	(void)argc;
	set_values(EAST);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "cub3D", true);
	data()->mlx = mlx;
	mlx_loop_hook(mlx, &ft_raycaster, NULL);
	create_img_buffer(mlx);
	mlx_key_hook(mlx, &ft_moves, mlx);
	mlx_loop(mlx);
	return (0);
}
