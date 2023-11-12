
#include "../includes/cub3d.h"

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

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

int	ft_strchrpos(const char *s, char c)
{
	int		pos;

	pos = 0;
	if (!s)
		return (-1);
	while (s[pos] != c && s[pos] != '\0')
	{
		pos++;
	}
	if ( s[pos] == c)
		return (pos);
	return (-1);
}