/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:40:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/17 14:48:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/includes/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "error.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

/*MACROS***********************************************************************/
# define TRUE 			1
# define FALSE 			0

# define WORD_EXP		102
# define D_QUOTE_EXP	103
# define FLAG_EXP		104
# define MACRO			105
# define WSPACE			106

# define MAPWIDTH		24
# define MAPHEIGHT		24
# define TEXWIDTH		64
# define TEXHEIGHT		64
# define SCREENWIDTH	1280
# define SCREENHEIGHT	1024

# define NORTH			601
# define EAST			602
# define SOUTH			603
# define WEST			604

# define UP				611
# define DOWN			612
# define LEFT			613
# define RIGHT			614

# define DIV			701
# define ADD			702
# define SUB			703

typedef struct s_map_parse {
	char	**map;
	char	**exec_map;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		player;
	int		f;
	int		c;
	bool	floodfill;
	int		player_x;
	int		player_y;
	int		lastidentline;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		floor_color;
	int		ceiling_color;
}	t_map_parse;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_dir
{
	double	x;
	double	y;
}	t_dir;

typedef struct s_plane
{
	double	x;
	double	y;
}	t_plane;

typedef struct s_ctrls
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	a;
	bool	d;
}			t_ctrls;

typedef struct s_worldmap
{
	char	**map;
}			t_worldmap;

typedef struct s_data
{
	double			time;
	double			oldtime;
	double			frametime;
	mlx_t			*mlx;
	mlx_image_t		*buf;
	mlx_texture_t	texture[4];
}				t_data;

typedef struct s_mv
{
	double		mspeed;
	double		rpeed;
	double		olddirx;
	double		oldplanex;
}	t_mv;

typedef struct s_raycaster
{
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltax;
	double		deltay;
	int			stepx;
	int			stepy;
	int			drawstart;
	int			drawend;
	int			colour;
	int			lineheight;
}	t_raycaster;

typedef struct s_overlay
{
	mlx_image_t	*pos;
	char		*str;
}				t_overlay;

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
void		ft_check_identifiers(t_map_parse *map_parse, char *line,
				int linepos);
bool		ft_check_identifier(char **texture, char *line, char *ident,
				int *identflag);
bool		ft_check_color(int *color, char *line, char *ident, int *identflag);
int			ft_all_identflags(t_map_parse *map_parse);
bool		ft_check_colorcode(int red, int green, int blue);
void		ft_check_map(t_map_parse *map_parse);
void		ft_find_player_in_line(t_map_parse *map_parse, int map_size,
				char p);
void		ft_prepare_map(t_map_parse *map_parse);
void		ft_convert_map(t_map_parse *map_parse);

/*ERROR************************************************************************/

void		ft_error_message(char *str);

/*MLX**************************************************************************/
void		empty_img_buffer(void *param);

/*IMG**************************************************************************/
void		create_background(mlx_t *mlx, int32_t floor, int32_t ceiling);
void		create_img_buffer(mlx_t *mlx, t_map_parse *map);
void		empty_img_buffer(void *param);
int			get_rgba(int r, int g, int b, int a);
int			get_r(int rgba);
int			get_g(int rgba);
int			get_b(int rgba);
int			get_a(int rgba);
int			math_rgba(int color, int div, int operator);
int			calc_wall_height(int side);
int			set_texture(int mapx, int mapy, int side, int texnum);
void		draw_walls(int drawstart, int drawend, int x, int side, int perpwalldist);
int			gradient(int color, int div, int operator);

/*EXEC*************************************************************************/
void		set_direction(int d);
void		ft_raycaster(void *param);
void		ft_moves(mlx_key_data_t keydata, void *param);
void		ft_ctrls(void *param);

/*TEXTURE**********************************************************************/
void		generate_textures(void);

/*UTILS************************************************************************/

int			ft_array_len(char **array);
void		ft_trim_line(char *line);
int			ft_strchrpos(const char *s, char c);
char		*ft_str_replace(char *str, char *to_replace, char *replace_with);
void		ft_replace_algo(char **str, char *to_replace,
				char *replace_with, int i);
char		*ft_join_three(char *s1, char *s2, char *s3);
int			get_rgba(int r, int g, int b, int a);
void		ft_print_array(char **array); //debug
t_pos		*pos(void);
t_dir		*dir(void);
t_plane		*plane(void);
t_data		*data(void);
t_worldmap	*wm(void);
t_raycaster	*ray(void);


void		ft_overlay(mlx_t *mlx);

#endif