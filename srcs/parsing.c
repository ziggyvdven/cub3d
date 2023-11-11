
#include "../includes/cub3d.h"

int	ft_get_map_size(char *map)
{
	int		fd;
	char	*line;
	int		size;

	size = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		size++;
	}
	free(line);
	close(fd);
	return (size);
}

void	ft_read_map(t_map_parse *map_parse, char *map)
{
	int			fd;
	char		*line;
	int			i;
	int			size;

	i = 0;
	size = ft_get_map_size(map);
	fd = open(map, O_RDONLY);
	map_parse->map = (char **)ft_calloc(size + 1, sizeof(char *));
	while (i <= size)
	{
		line = get_next_line(fd);
		map_parse->map[i] = line;
		i++;
	}
	free(line);
	close (fd);
}

void	ft_init_map_parse(t_map_parse *map_parse)
{
	map_parse->NO = FALSE;
	map_parse->SO = FALSE;
	map_parse->WE = FALSE;
	map_parse->EA = FALSE;
	map_parse->F = FALSE;
	map_parse->C = FALSE;
	map_parse->player = FALSE;
}

void	ft_parsing(char *map)
{
	t_map_parse	map_parse;

	ft_init_map_parse(&map_parse);
	if (ft_check_format(map) != TRUE || ft_check_file(map) != TRUE)
		ft_error_message(E_FILE);
	ft_read_map(&map_parse, map);
	ft_validate_map(&map_parse);
}