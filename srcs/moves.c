/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:09:08 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/08 20:42:47 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_moves(mlx_key_data_t keydata, void *param)
{
	double	movespeed;
	double	rotspeed;
	double	olddirx;
	double	oldplanex;
	(void)param;

	movespeed = data()->mlx->delta_time * 40.0;
	rotspeed = data()->mlx->delta_time * 10.0;
	ft_overlay(data()->mlx);
		printf("dirx = %f diry = %2f\nplanex = %f planey = %2f\n", dir()->x, dir()->y, plane()->x, plane()->y);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data()->mlx);
	if (mlx_is_key_down(data()->mlx, 265) || mlx_is_key_down(data()->mlx, 87))
	{
		if (wm()->map[(int)pos()->x + (int)dir()->x * (int)movespeed][(int)pos()->y] == false)
			pos()->x += dir()->x * movespeed;
		if (wm()->map[(int)pos()->x][(int)pos()->y + (int)dir()->y * (int)movespeed] == false)
			pos()->y += dir()->y * movespeed;
	}
	else if (mlx_is_key_down(data()->mlx, 264) || mlx_is_key_down(data()->mlx, 83))
	{
		if (wm()->map[(int)pos()->x - (int)dir()->x * (int)movespeed][(int)pos()->y] == false)
			pos()->x -= dir()->x * movespeed;
		if (wm()->map[(int)pos()->x][(int)pos()->y - (int)dir()->y * (int)movespeed] == false)
			pos()->y -= dir()->y * movespeed;
	}
	else if (mlx_is_key_down(data()->mlx, 263) || mlx_is_key_down(data()->mlx, 65))
	{
		olddirx = dir()->x;
		dir()->x = dir()->x * cos(rotspeed) - dir()->y * sin(rotspeed);
		dir()->y = olddirx * sin(rotspeed) + dir()->y * cos(rotspeed);
		oldplanex = plane()->x;
		plane()->x = plane()->x * cos(rotspeed) - plane()->y * sin(rotspeed);
		plane()->y = oldplanex * sin(rotspeed) + plane()->y * cos(rotspeed);
	}
	else if (mlx_is_key_down(data()->mlx, 262) || mlx_is_key_down(data()->mlx, 68))
	{
		olddirx = dir()->x;
		dir()->x = dir()->x * cos(-rotspeed) - dir()->y * sin(-rotspeed);
		dir()->y = olddirx * sin(-rotspeed) + dir()->y * cos(-rotspeed);
		oldplanex = plane()->x;
		plane()->x = plane()->x * cos(-rotspeed) - plane()->y * sin(-rotspeed);
		plane()->y = oldplanex * sin(-rotspeed) + plane()->y * cos(-rotspeed);
	}
	return ;
}
