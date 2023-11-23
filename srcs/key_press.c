/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:00:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/23 18:04:31 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_ctrls(void *param)
{
	double	movespeed;
	double	rotspeed;
	mlx_t	*mlx;

	mlx = param;
	movespeed = mlx->delta_time * 7.0;
	rotspeed = mlx->delta_time * 2.0;
	if (key()->up == true)
		ft_move_up(movespeed);
	else if (key()->down == true)
		ft_move_down(movespeed);
	if (key()->a == true)
		ft_move_left(movespeed);
	else if (key()->d == true)
		ft_move_right(movespeed);
	if (key()->left == true)
		ft_rotate(-rotspeed);
	else if (key()->right == true)
		ft_rotate(rotspeed);
	return ;
}

void	ft_key_release(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		key()->up = false;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		key()->down = false;
	if ((keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_RELEASE)
		key()->left = false;
	else if ((keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_RELEASE)
		key()->right = false;
	if ((keydata.key == MLX_KEY_A) && keydata.action == MLX_RELEASE)
		key()->a = false;
	else if ((keydata.key == MLX_KEY_D) && keydata.action == MLX_RELEASE)
		key()->d = false;
}

void	ft_key_bonus(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_C) && key()->m_active == true)
		key()->m_active = false;
	else if (mlx_is_key_down(mlx, MLX_KEY_C))
		key()->m_active = true;
	if (mlx_is_key_down(mlx, MLX_KEY_M) && key()->map_active == true)
	{
		mlx_delete_image(mlx, mini()->map);
		key()->map_active = false;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_M))
	{
		create_minimap_img(mlx);
		key()->map_active = true;
	}
}

void	ft_key_press(mlx_key_data_t keydata, mlx_t *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_free_ar(wm()->map);
		ft_free_ar(wm()->map);
		mlx_close_window(mlx);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		key()->d = true;
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
		key()->a = true;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		key()->up = true;
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
		key()->down = true;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		key()->left = true;
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		key()->right = true;
	ft_key_bonus(mlx);
}

void	ft_moves(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	ft_overlay(mlx);
	ft_key_press(keydata, mlx);
	ft_key_release(keydata);
	return ;
}
