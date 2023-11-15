/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:51:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/15 11:37:07 by lfrank           ###   ########.fr       */
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
	t_map_parse	map_parse;

	if (argc != 2)
		ft_error_message(E_ARG);
	map_parse = ft_parsing(argv[1]);
	ft_free_ar(map_parse.map);
	ft_free_ar(map_parse.exec_map);
	mlx_t		*mlx;

	(void)argv;
	(void)argc;
	set_values(EAST);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "cub3D", true);
	data()->mlx = mlx;
	mlx_loop_hook(mlx, &ft_raycaster, mlx);
	create_img_buffer(mlx);
	mlx_key_hook(mlx, &ft_moves, mlx);
	mlx_loop(mlx);
	return (0);
}
