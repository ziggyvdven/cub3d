/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:51:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/12/06 15:17:29 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_close(t_map_parse map_parse)
{
	mlx_delete_texture(data()->texture[0]);
	mlx_delete_texture(data()->texture[1]);
	mlx_delete_texture(data()->texture[2]);
	mlx_delete_texture(data()->texture[3]);
	mlx_delete_texture(data()->texture[4]);
	ft_free_ar(map_parse.map);

}

void	set_direction(int d)
{
	if (d == WEST || d == EAST)
	{
		dir()->x = -1.0;
		dir()->y = 0.0;
		plane()->x = 0.0;
		plane()->y = 0.66;
		if (d == EAST)
		{
			dir()->x *= -1.0;
			plane()->y *= -1.0;
		}
	}
	if (d == SOUTH || d == NORTH)
	{
		dir()->x = 0.0;
		dir()->y = 1.0;
		plane()->x = 0.66;
		plane()->y = 0.0;
		if (d == NORTH)
		{
			dir()->y *= -1.0;
			plane()->x *= -1.0;
		}
	}
}

void	set_values(t_map_parse *map)
{
	pos()->x = (double)map->player_x + 0.5;
	pos()->y = (double)map->player_y + 0.5 ;
	set_direction(map->direction);
	data()->time = 0.0;
	data()->oldtime = 0.0;
	generate_textures(map);
	overlay()->hand_active = false;
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
	create_img_buffer(mlx, &map_parse);
	mlx_loop_hook(mlx, &ft_raycaster, mlx);
	mlx_key_hook(mlx, &ft_moves, mlx);
	mlx_loop(mlx);
	ft_close(map_parse);
	mlx_terminate(mlx);
	return (0);
}
