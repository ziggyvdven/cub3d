/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:07 by lfrank            #+#    #+#             */
/*   Updated: 2023/11/15 11:24:00 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_all_identflags(t_map_parse *map_parse)
{
	return (map_parse->no + map_parse->so + map_parse->we + map_parse->ea
		+ map_parse->f + map_parse->c);
}

bool	ft_check_identifier(char **texture, char *line, char *ident,
			int *identflag)
{
	if (ft_strncmp(line, ident, 2) == 0)
	{
		if ((ft_check_textureformat(&line[2]) != TRUE)
			|| (ft_check_file(&line[2]) != TRUE))
			ft_error_message(E_TEXTUREFILE);
		(*identflag)++;
		*texture = &line[2];
		return (TRUE);
	}
	return (FALSE);
}

void	ft_check_identifiers(t_map_parse *map_parse, char *line, int linepos)
{
	if (ft_check_identifier(&map_parse->texture_no, line, "NO", &map_parse->no))
		map_parse->lastidentline = linepos;
	if (ft_check_identifier(&map_parse->texture_so, line, "SO", &map_parse->so))
		map_parse->lastidentline = linepos;
	if (ft_check_identifier(&map_parse->texture_we, line, "WE", &map_parse->we))
		map_parse->lastidentline = linepos;
	if (ft_check_identifier(&map_parse->texture_ea, line, "EA", &map_parse->ea))
		map_parse->lastidentline = linepos;
	if (ft_check_color(&map_parse->ceiling_color, line, "C", &map_parse->c))
		map_parse->lastidentline = linepos;
	if (ft_check_color(&map_parse->floor_color, line, "F", &map_parse->f))
		map_parse->lastidentline = linepos;
}

bool	ft_is_identifier(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		return (TRUE);
	if (ft_strncmp(&line[i], "EA", 2) == 0)
		return (TRUE);
	if (ft_strncmp(&line[i], "SO", 2) == 0)
		return (TRUE);
	if (ft_strncmp(&line[i], "WE", 2) == 0)
		return (TRUE);
	if (ft_strncmp(&line[i], "C", 1) == 0)
		return (TRUE);
	if (ft_strncmp(&line[i], "F", 1) == 0)
		return (TRUE);
	return (FALSE);
}
