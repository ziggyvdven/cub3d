/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:03:56 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/23 11:39:17 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_pos	*pos(void)
{
	static t_pos	pos;

	return (&pos);
}

t_dir	*dir(void)
{
	static t_dir	dir;

	return (&dir);
}

t_plane	*plane(void)
{
	static t_plane	plane;

	return (&plane);
}

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_raycaster	*ray(void)
{
	static t_raycaster	ray;

	return (&ray);
}
