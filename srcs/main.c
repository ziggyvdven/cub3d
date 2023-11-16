/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:51:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/15 16:28:25 by zvan-de-         ###   ########.fr       */
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

void	set_values(t_map_parse *map)
{
	pos()->x = map->player_x;
	pos()->y = map->player_y;
	set_direction(NORTH);
	data()->time = 0;
	data()->oldtime = 0;
	return ;
}

int32_t	main(int argc, char **argv)
{
	t_map_parse	map_parse;
	mlx_t		*mlx;

	(void)argv;
	if (argc != 2)
		ft_error_message(E_ARG);
	map_parse = ft_parsing(argv[1]);
	set_values(&map_parse);
	wm()->map = map_parse.exec_map;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "cub3D", true);
	data()->mlx = mlx;
	mlx_loop_hook(mlx, &ft_raycaster, mlx);
	create_img_buffer(mlx, &map_parse);
	mlx_key_hook(mlx, &ft_moves, mlx);
	mlx_loop(mlx);
	return (0);
}
