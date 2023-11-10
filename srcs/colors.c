/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:00:44 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/10 16:45:29 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int	get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int	get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

int	math_rgba(int color, int div, int operator)
{
	int	r;
	int	g;
	int	b;

	if (operator == DIV)
	{
		r = get_r(color) / div;
		g = get_g(color) / div;
		b = get_b(color) / div;
		return (r << 24 | g << 16 | b << 8 | 255);
	}
	if (operator == ADD)
	{
		r = get_r(color) + div;
		g = get_g(color) + div;
		b = get_b(color) + div;
		return (r << 24 | g << 16 | b << 8 | 255);
	}
	r = 0;
	g = get_g(color) + div;
	b = 230;
	return (r << 24 | g << 16 | b << 8 | 255);
}
