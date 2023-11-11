
#include "../includes/cub3d.h"

bool	ft_all_identflags(t_map_parse *map_parse)
{
	return (map_parse->NO && map_parse->SO && map_parse->WE && map_parse->EA
		&& map_parse->F && map_parse->C);
}

bool	ft_check_colorcode(int red, int green, int blue)
{
	if (red >= 0 && red <= 255 && green >= 0 && green <= 255 && blue >= 0
		&& blue <= 255)
			return (TRUE);
	else
		return (FALSE);
}
//debug
void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		printf("%s\n", array[i++]);
}

void	ft_check_color(char *line, char *ident, bool *identflag)
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
			*identflag = TRUE;
		}
		else
			ft_free_ar(colorcodes);
	}
}

void	ft_check_identifier(char *line, char *ident, bool *identflag)
{
	if (ft_strncmp(line, ident, 2) == 0)
	{
		if ((ft_check_textureformat(&line[2]) != TRUE)
			|| (ft_check_file(&line[2]) != TRUE))
			ft_error_message(E_TEXTUREFILE);
		*identflag = TRUE;
	}
}

void	ft_check_identifiers(t_map_parse *map_parse, char *line)
{
	ft_check_identifier(line, "NO", &map_parse->NO);
	ft_check_identifier(line, "SO", &map_parse->SO);
	ft_check_identifier(line, "WE", &map_parse->WE);
	ft_check_identifier(line, "EA", &map_parse->EA);
	ft_check_color(line, "C", &map_parse->C);
	ft_check_color(line, "F", &map_parse->F);
}