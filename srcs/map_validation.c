
#include "../includes/cub3d.h"

void	ft_floodfill(t_map_parse *map_parse, int x, int y)
{
	if (x <= 0 || y <= 0 || map_parse->map[y][x] == '1'
		|| map_parse->map[y][x] == 'o')
	{
		return ;
	}
	else if (map_parse->map[y][x] == '0')
		map_parse->map[y][x] = 'o';
	else
	{
		printf("yx: %d\n", map_parse->map[y][x]);
		printf("y: %d\n", y);
		printf("x: %d\n", x);
		ft_error_message(E_INVALIDMAP);
	}
	ft_floodfill(map_parse, x, (y + 1));
	ft_floodfill(map_parse, x, (y - 1));
	ft_floodfill(map_parse, (x + 1), y);
	ft_floodfill(map_parse, (x - 1), y);
}

void	ft_prepare_map(t_map_parse *map_parse)
{
	int	map_size;
	int i;
	
	i = 0;
	map_size = ft_array_len(map_parse->map);
	while (map_size > map_parse->lastidentline)
	{
		map_parse->map[map_size - 1] = ft_str_replace(
				map_parse->map[map_size - 1], "\t", "    ");
		map_size--;
	}
}

void	ft_find_player_in_line(t_map_parse *map_parse, int map_size, char p)
{
	int pos_x;

	pos_x = ft_strchrpos(map_parse->map[map_size - 1], p);
	if (pos_x != -1)
	{
		map_parse->player++;
		map_parse->player_x = pos_x;
		map_parse->player_y = map_size - 1;
	}
}

void	ft_check_map(t_map_parse *map_parse)
{
	int	map_size;
	
	map_size = ft_array_len(map_parse->map);
	while (map_size > map_parse->lastidentline)
	{
		ft_find_player_in_line(map_parse, map_size, 'N');
		ft_find_player_in_line(map_parse, map_size, 'S');
		ft_find_player_in_line(map_parse, map_size, 'W');
		ft_find_player_in_line(map_parse, map_size, 'E');
		map_size--;
	}
	if (map_parse->player != 1)
		ft_error_message(E_MISSPLAYER);
	map_parse->map[map_parse->player_y][map_parse->player_x] = '0';
	ft_floodfill(map_parse, map_parse->player_x, map_parse->player_y);
}

void	ft_validate_map(t_map_parse *map_parse)
{
	int	i;

	i = 0;
	while (map_parse->map[i])
	{
		if (ft_is_identifier(map_parse->map[i]) == TRUE)
			ft_trim_line(map_parse->map[i]);
		ft_check_identifiers(map_parse, map_parse->map[i], i);
		i++;
	}
	printf("floor: %x\n", map_parse->floor_color);
	if (ft_all_identflags(map_parse) != 6)
		ft_error_message(E_MISSTEXT);
	ft_prepare_map(map_parse);
	ft_check_map(map_parse);
	printf("player_X: %d\n", map_parse->player_x);
	printf("player_Y: %d\n", map_parse->player_y);
	printf("Lastidentline: %d\n", map_parse->lastidentline);
	// parse la map
}
