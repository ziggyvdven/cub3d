
#include "../includes/cub3d.h"

bool	ft_find_player_in_line(t_map_parse *map_parse, int map_size, char p)
{
	int pos_x;

	pos_x = ft_strchrpos(map_parse->map[map_size - 1], p);
	if (pos_x != -1)
	{
		map_parse->player = TRUE;
		map_parse->player_x = pos_x;
		map_parse->player_y = map_size - 1;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_check_map(t_map_parse *map_parse)
{
	int	map_size;
	
	map_size = ft_array_len(map_parse->map);
	while (map_size > map_parse->lastidentline)
	{
		if (ft_find_player_in_line(map_parse, map_size, 'N'))
			break;
		if (ft_find_player_in_line(map_parse, map_size, 'S'))
			break;
		if (ft_find_player_in_line(map_parse, map_size, 'W'))
			break;
		if (ft_find_player_in_line(map_parse, map_size, 'E'))
			break; 
		map_size--;
	}
	if (map_parse->player != TRUE)
		ft_error_message(E_MISSPLAYER);
	// flootfill à partir de cette position
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
	if (ft_all_identflags(map_parse) != 6)
		ft_error_message(E_MISSTEXT);
	ft_check_map(map_parse);
	printf("player_X: %d\n", map_parse->player_x);
	printf("player_Y: %d\n", map_parse->player_y);
	printf("Lastidentline: %d\n", map_parse->lastidentline);
	// parse la map
}
