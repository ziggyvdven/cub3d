/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:10:38 by lfrank            #+#    #+#             */
/*   Updated: 2023/11/15 11:11:04 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	ft_check_colorcode(int red, int green, int blue)
{
	if (red >= 0 && red <= 255 && green >= 0 && green <= 255 && blue >= 0
		&& blue <= 255)
		return (TRUE);
	else
		return (FALSE);
}

bool	ft_check_color(int *color, char *line, char *ident, int *identflag)
{
	char	**colorcodes;
	int		red;
	int		green;
	int		blue;

	if (ft_strncmp(line, ident, 1) == 0)
	{
		colorcodes = ft_split(++line, ',');
		if (ft_array_len(colorcodes) == 3)
		{
			red = ft_atoi(colorcodes[0]);
			green = ft_atoi(colorcodes[1]);
			blue = ft_atoi(colorcodes[2]);
			ft_free_ar(colorcodes);
			if (ft_check_colorcode(red, green, blue) != TRUE)
				ft_error_message(E_COLOR);
			(*identflag)++;
			*color = get_rgba(red, green, blue, 255);
			return (TRUE);
		}
		else
			ft_free_ar(colorcodes);
	}
	return (FALSE);
}
