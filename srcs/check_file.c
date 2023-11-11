
#include "../includes/cub3d.h"

bool	ft_check_file(char *file) 
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}
