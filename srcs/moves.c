/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:09:08 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/22 18:25:46 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_ctrls	*key(void)
{
	static t_ctrls	crtls;

	return (&crtls);
}

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
	// int	teleport = 0;

	if (direction == UP)
	{
		// printf("next spoty %d, next spots %d value = %d\n", (int)(pos()->y + dir()->y), (int)(pos()->x + dir()->x), wm()->map[(int)(pos()->y + dir()->y)]
		// 	[(int)(pos()->x + dir()->x)]);
		if (wm()->map[(int)(pos()->y + dir()->y - 0.1)]
			[(int)pos()->x] == '0')
			pos()->y += dir()->y * ms;
		if (wm()->map[(int)pos()->y]
			[(int)(pos()->x + dir()->x - 0.1)] == '0')
			pos()->x += dir()->x * ms;
		// if (wm()->map[(int)(pos()->y + dir()->y)]
		// 	[(int)(pos()->x)] == 5)
		// {
		// 	pos()->y += dir()->y * ms;
		// 	teleport = 1;
		// }
		// if (wm()->map[(int)(pos()->y)]
		// 	[(int)(pos()->x + dir()->x)] == 5)
		// {
		// 	pos()->x += dir()->x * ms;
		// 	if (teleport)
		// 	{
		// 		pos()->x = 12;
		// 		pos()->y = 23;
		// 		set_direction(NORTH);
		// 	}
		// }
	}
	else if (direction == DOWN)
	{
		if (wm()->map[(int)pos()->y]
			[(int)(pos()->x - dir()->x + 0.1)] == '0')
			pos()->x -= dir()->x * ms;
		if (wm()->map[(int)(pos()->y - dir()->y + 0.1)]
			[(int)pos()->x] == '0')
			pos()->y -= dir()->y * ms;
	}
	else if (direction == RIGHT)
	{
		if (wm()->map[(int)pos()->y]
			[(int)(pos()->x - plane()->x + 0.1)] == '0')
			pos()->x -= plane()->x * ms;
		if (wm()->map[(int)(pos()->y - plane()->y + 0.1)]
			[(int)pos()->x] == '0')
			pos()->y -= plane()->y * ms;
	}
	else if (direction == LEFT)
	{
		if (wm()->map[(int)(pos()->y + plane()->y + 0.1)]
			[(int)pos()->x] == '0')
			pos()->y += plane()->y * ms;
		if (wm()->map[(int)pos()->y]
			[(int)(pos()->x + plane()->x + 0.1)] == '0')
			pos()->x += plane()->x * ms;
	}
}

void	ft_ctrls(void *param)
{
	double	movespeed;
	double	rotspeed;
	mlx_t	*mlx;

	mlx = param;
	movespeed = mlx->delta_time * 10.0;
	rotspeed = mlx->delta_time * 2.0;
	if (key()->up == true)
		ft_move(movespeed, UP);
	else if (key()->down == true)
		ft_move(movespeed, DOWN);
	if (key()->a == true)
		ft_move(movespeed, LEFT);
	else if (key()->d == true)
		ft_move(movespeed, RIGHT);
	if (key()->left == true)
		ft_rotate(-rotspeed);
	else if (key()->right == true)
		ft_rotate(rotspeed);
	return ;
}

void	ft_moves(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	ft_overlay(mlx);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
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
	return ;
}

