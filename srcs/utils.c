
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

char	*ft_join_three(char *s1, char *s2, char *s3)
{
	char	*s2_s3;
	char	*s1_s2_s3;

	s2_s3 = ft_strjoin(s2, s3);
	s1_s2_s3 = ft_strjoin(s1, s2_s3);
	free(s2_s3);
	return (s1_s2_s3);
}

void	ft_replace_algo(char **str, char *to_replace, char *replace_with, int i)
{
	char	*tmp;
	char	*before_var;
	char	*after_var;

	tmp = *str;
	before_var = ft_substr(*str, 0, (i - ft_strlen(to_replace)));
	after_var = ft_substr(*str, i, SIZE_MAX);
	if (replace_with == NULL)
		replace_with = "";
	*str = ft_join_three(before_var, replace_with, after_var);
	free(tmp);
	free(before_var);
	free(after_var);
}

char	*ft_str_replace(char *str, char *to_replace, char *replace_with)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == to_replace[j] && str[i] && to_replace[j])
		{
			i++;
			j++;
		}
		if (to_replace[j] == '\0')
		{
			ft_replace_algo(&str, to_replace, replace_with, i);
			break ;
		}
		j = 0;
		i++;
	}
	return (str);
}


//debug
void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		printf("%s\n", array[i++]);
}