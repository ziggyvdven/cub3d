
#include "../includes/cub3d.h"

int	ft_all_identflags(t_map_parse *map_parse)
{
	return (map_parse->NO + map_parse->SO + map_parse->WE + map_parse->EA
		+ map_parse->F + map_parse->C);
}

bool	ft_check_colorcode(int red, int green, int blue)
{
	if (red >= 0 && red <= 255 && green >= 0 && green <= 255 && blue >= 0
		&& blue <= 255)
			return (TRUE);
	else
		return (FALSE);
}

bool	ft_check_color(char *line, char *ident, int *identflag)
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
			return (TRUE);
		}
		else
			ft_free_ar(colorcodes);
	}
	return (FALSE);
}

bool	ft_check_identifier(char *line, char *ident, int *identflag)
{
	if (ft_strncmp(line, ident, 2) == 0)
	{
		if ((ft_check_textureformat(&line[2]) != TRUE)
			|| (ft_check_file(&line[2]) != TRUE))
			ft_error_message(E_TEXTUREFILE);
		(*identflag)++;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_check_identifiers(t_map_parse *map_parse, char *line, int linepos)
{
	if (ft_check_identifier(line, "NO", &map_parse->NO) == TRUE)
		map_parse->lastidentline = linepos;
	if (ft_check_identifier(line, "SO", &map_parse->SO) == TRUE)
		map_parse->lastidentline = linepos;
	if (ft_check_identifier(line, "WE", &map_parse->WE) == TRUE)
		map_parse->lastidentline = linepos;
	if (ft_check_identifier(line, "EA", &map_parse->EA) == TRUE)
		map_parse->lastidentline = linepos;
	if (ft_check_color(line, "C", &map_parse->C) == TRUE)
		map_parse->lastidentline = linepos;
	if (ft_check_color(line, "F", &map_parse->F) == TRUE)
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
