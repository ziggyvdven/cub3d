/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:11:40 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/24 11:47:36 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mouse(mlx_t *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key()->m_active == FALSE)
		return ;
	mlx_get_mouse_pos(mlx, &x, &y);
	mlx_set_cursor_mode(mlx, MLX_MOUSE_HIDDEN);
	if (x > (double)(SCREENWIDTH * 0.5))
	{
		ft_rotate(ROTATE_SPEED * MOUSE_SPEED);
		mlx_set_mouse_pos(mlx, SCREENWIDTH * 0.5, SCREENHEIGHT * 0.5);
	}
	if (x < (double)(SCREENWIDTH * 0.5))
	{
		ft_rotate(-ROTATE_SPEED * MOUSE_SPEED);
		mlx_set_mouse_pos(mlx, SCREENWIDTH * 0.5, SCREENHEIGHT * 0.5);
	}
}
