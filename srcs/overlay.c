/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:55:11 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/23 17:41:31 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_overlay	*overlay(void)
{
	static t_overlay	overlay;

	return (&overlay);
}

void	ft_overlay_entry(mlx_t *mlx, mlx_image_t *img, char *str)
{
	mlx_image_t	*posi;

	mlx_delete_image(mlx, img);
	posi = mlx_put_string(mlx, str, 1000, 10);
	overlay()->pos = posi;
	free (str);
}

void	ft_overlay(mlx_t *mlx)
{
	char	*str;
	char	*x;
	char	*y;

	x = ft_itoa(pos()->x);
	y = ft_itoa(pos()->y);
	str = ft_strjoin("Pos x:", x);
	str = ft_strjoin_free(str, " y:");
	str = ft_strjoin_free(str, y);
	free(x);
	free(y);
	ft_overlay_entry(mlx, overlay()->pos, str);
}
