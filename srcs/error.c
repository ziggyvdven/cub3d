
#include "../includes/cub3d.h"

void	ft_error_message(char *str)
{
	if (!str)
		printf("Error: ./cub3d");
	else
		printf("Error: " "%s", str);
	exit(1);
}
