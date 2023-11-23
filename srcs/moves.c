/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:09:08 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/23 12:12:07 by zvan-de-         ###   ########.fr       */
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

void	ft_move_up(double ms)
{
	if (wm()->map[(int)(pos()->y + dir()->y - 0.1)]
		[(int)pos()->x] == '0')
		pos()->y += dir()->y * ms;
	if (wm()->map[(int)pos()->y]
		[(int)(pos()->x + dir()->x - 0.1)] == '0')
		pos()->x += dir()->x * ms;
}

void	ft_move_down(double ms)
{
	if (wm()->map[(int)pos()->y]
		[(int)(pos()->x - dir()->x + 0.1)] == '0')
		pos()->x -= dir()->x * ms;
	if (wm()->map[(int)(pos()->y - dir()->y + 0.1)]
		[(int)pos()->x] == '0')
		pos()->y -= dir()->y * ms;
}

void	ft_move_right(double ms)
{
	if (wm()->map[(int)pos()->y]
		[(int)(pos()->x - plane()->x + 0.1)] == '0')
		pos()->x -= plane()->x * ms;
	if (wm()->map[(int)(pos()->y - plane()->y + 0.1)]
		[(int)pos()->x] == '0')
		pos()->y -= plane()->y * ms;
}

void	ft_move_left(double ms)
{
	if (wm()->map[(int)(pos()->y + plane()->y + 0.1)]
		[(int)pos()->x] == '0')
		pos()->y += plane()->y * ms;
	if (wm()->map[(int)pos()->y]
		[(int)(pos()->x + plane()->x + 0.1)] == '0')
		pos()->x += plane()->x * ms;
}
