
#include "../includes/cub3d.h"

void	ft_trim_line(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			line[j++] = line[i];
		i++;
	}
	if (j > 0 && line[j - 1] == ' ')
		j--;
	line[j] = '\0';
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


void	ft_validate_map(t_map_parse *map_parse)
{
	int	i;

	i = 0;
	while (map_parse->map[i])
	{
		if (ft_is_identifier(map_parse->map[i]) == TRUE)
			ft_trim_line(map_parse->map[i]);
		ft_check_identifiers(map_parse, map_parse->map[i]);
		i++;
	}
	if (ft_all_identflags(map_parse) != TRUE)
		ft_error_message(E_MISSTEXT);
	printf("validation passed\n");
	// parse la map
}
