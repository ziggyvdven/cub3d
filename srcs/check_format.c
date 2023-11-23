/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:31 by lfrank            #+#    #+#             */
/*   Updated: 2023/11/22 19:00:24 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	ft_check_format(char *map)
{
	int	end;

	end = ft_strlen(map) - 1;
	if (map[end] != 'b')
		return (FALSE);
	end--;
	if (map[end] != 'u')
		return (FALSE);
	end--;
	if (map[end] != 'c')
		return (FALSE);
	end--;
	if (map[end] != '.')
		return (FALSE);
	return (TRUE);
}

bool	ft_check_textureformat(char *map)
{
	int	end;

	end = ft_strlen(map) - 1;
	if (map[end] != 'g')
		return (FALSE);
	end--;
	if (map[end] != 'n')
		return (FALSE);
	end--;
	if (map[end] != 'p')
		return (FALSE);
	end--;
	if (map[end] != '.')
		return (FALSE);
	return (TRUE);
}
