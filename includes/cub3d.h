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
	bool	NO;
	bool	SO;
	bool	WE;
	bool	EA;
	bool	player;
	bool	F;
	bool	C;
	bool	floodfill;
} t_map_parse;

/*PARSING**********************************************************************/

void	ft_parsing(char *map);
bool	ft_check_format(char *map);
bool	ft_check_file(char *file);
void	ft_init_map_parse(t_map_parse *map_parse);
void	ft_read_map(t_map_parse *map_parse, char *map);
int		ft_get_map_size(char *map);
void	ft_validate_map(t_map_parse *map_parse);
bool	ft_is_identifier(char *line);
void	ft_trim_line(char *line);
bool	ft_check_textureformat(char *map);
void	ft_check_identifiers(t_map_parse *map_parse, char *line);
void	ft_check_identifier(char *line, char *ident, bool *identflag);
void	ft_check_color(char *line, char *ident, bool *identflag);
bool	ft_all_identflags(t_map_parse *map_parse);
bool	ft_check_colorcode(int red, int green, int blue);

/*ERROR************************************************************************/

void	ft_error_message(char *str);

/*EXEC*************************************************************************/

/*UTILS************************************************************************/

int		ft_array_len(char **array);

#endif