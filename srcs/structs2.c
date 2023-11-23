/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:21:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/23 17:22:02 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_worldmap	*wm(void)
{
	static t_worldmap	map;

	return (&map);
}

t_ctrls	*key(void)
{
	static t_ctrls	crtls;

	return (&crtls);
}

t_minimap	*mini(void)
{
	static t_minimap	map;

	return (&map);
}
