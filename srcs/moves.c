/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:09:08 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/10 14:59:22 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rotate(double rotspeed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = dir()->x;
	dir()->x = dir()->x * cos(rotspeed) - dir()->y * sin(rotspeed);
	dir()->y = olddirx * sin(rotspeed) + dir()->y * cos(rotspeed);
	oldplanex = plane()->x;
	plane()->x = plane()->x * cos(rotspeed) - plane()->y * sin(rotspeed);
	plane()->y = oldplanex * sin(rotspeed) + plane()->y * cos(rotspeed);
}

void	ft_move(double ms, int direction)
{
	if (direction == 1)
	{
		if (wm()->map[(int)(pos()->y + dir()->y)]
			[(int)pos()->x] == false)
			pos()->y += dir()->y * ms;
		if (wm()->map[(int)pos()->y]
			[(int)(pos()->x + dir()->x)] == false)
			pos()->x += dir()->x * ms;
	}
	if (direction == 0)
	{
		if (wm()->map[(int)pos()->y]
			[(int)(pos()->x - dir()->x)] == false)
			pos()->x -= dir()->x * ms;
		if (wm()->map[(int)(pos()->y - dir()->y)]
			[(int)pos()->x] == false)
			pos()->y -= dir()->y * ms;
	}
}

void	ft_moves(mlx_key_data_t keydata, void *param)
{
	double	movespeed;
	double	rotspeed;
	mlx_t	*mlx;

	mlx = param;
	movespeed = mlx->delta_time * 20.0;
	rotspeed = mlx->delta_time * 10.0;
	ft_overlay(mlx);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, 265) || mlx_is_key_down(mlx, 87))
		ft_move(movespeed, 1);
	else if (mlx_is_key_down(mlx, 264) || mlx_is_key_down(mlx, 83))
		ft_move(movespeed, 0);
	else if (mlx_is_key_down(mlx, 263) || mlx_is_key_down(mlx, 65))
		ft_rotate(-rotspeed);
	else if (mlx_is_key_down(mlx, 262) || mlx_is_key_down(mlx, 68))
		ft_rotate(rotspeed);
	return ;
}
