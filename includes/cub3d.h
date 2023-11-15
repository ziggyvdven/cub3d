/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:40:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/02 14:46:46 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/includes/libft.h"
# include "error.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>


/*MACROS***********************************************************************/

# define TRUE 1
# define FALSE 0

# define WORD_EXP		102
# define D_QUOTE_EXP	103
# define FLAG_EXP		104
# define MACRO			105
# define WSPACE			106

/*STRUCTS**********************************************************************/

typedef struct s_map_parse {
	char	**map;
	char	**exec_map;
	int		NO;
	int		SO;
	int		WE;
	int		EA;
	int		player;
	int		F;
	int		C;
	bool	floodfill;
	int		player_x;
	int		player_y;
	int		lastidentline;
	char	*texture_NO;
	char	*texture_SO;
	char	*texture_WE;
	char	*texture_EA;
	int		floor_color;
	int		ceiling_color;
} t_map_parse;

/*PARSING**********************************************************************/

t_map_parse	ft_parsing(char *map);
bool		ft_check_format(char *map);
bool		ft_check_file(char *file);
void		ft_init_map_parse(t_map_parse *map_parse);
void		ft_read_map(t_map_parse *map_parse, char *map);
int			ft_get_map_size(char *map);
void		ft_validate_map(t_map_parse *map_parse);
bool		ft_is_identifier(char *line);
bool		ft_check_textureformat(char *map);
void		ft_check_identifiers(t_map_parse *map_parse, char *line, int linepos);
bool		ft_check_identifier(char **texture, char *line, char *ident,
				int *identflag);
bool		ft_check_color(int *color, char *line, char *ident, int *identflag);
int			ft_all_identflags(t_map_parse *map_parse);
bool		ft_check_colorcode(int red, int green, int blue);
void		ft_check_map(t_map_parse *map_parse);
void		ft_find_player_in_line(t_map_parse *map_parse, int map_size, char p);
void		ft_prepare_map(t_map_parse *map_parse);
void 		ft_convert_map(t_map_parse *map_parse);

/*ERROR************************************************************************/

void	ft_error_message(char *str);

/*EXEC*************************************************************************/

/*UTILS************************************************************************/

int		ft_array_len(char **array);
void	ft_trim_line(char *line);
int		ft_strchrpos(const char *s, char c);
char	*ft_str_replace(char *str, char *to_replace, char *replace_with);
void	ft_replace_algo(char **str, char *to_replace,
			char *replace_with, int i);
char	*ft_join_three(char *s1, char *s2, char *s3);
void	ft_print_array(char **array); //debug
int		get_rgba(int r, int g, int b, int a);

#endif