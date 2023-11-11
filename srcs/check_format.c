
#include "../includes/cub3d.h"

bool	ft_check_format(char *map)
{
	int	end;

	end = ft_strlen(map) - 1;
	if (map[end] != 'b')
		return(FALSE);
	end--;
	if (map[end] != 'u')
		return(FALSE);
	end--;
	if (map[end] != 'c')
		return(FALSE);
	end--;
	if (map[end] != '.')
		return(FALSE);
	return (TRUE);
}

bool	ft_check_textureformat(char *map)
{
	int	end;

	end = ft_strlen(map) - 1;
	if (map[end] != '2')
		return(FALSE);
	end--;
	if (map[end] != '4')
		return(FALSE);
	end--;
	if (map[end] != 'm')
		return(FALSE);
	end--;
	if (map[end] != 'p')
		return(FALSE);
	end--;
	if (map[end] != 'x')
		return(FALSE);
	end--;
	if (map[end] != '.')
		return(FALSE);
	return (TRUE);
}
