/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:40:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/10 17:59:53 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/includes/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

/*MACROS***********************************************************************/

# define MAPWIDTH		24
# define MAPHEIGHT		24
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
}	t_ctrls;

typedef struct s_worldmap
{
	int	map[MAPWIDTH][MAPHEIGHT];
}	t_worldmap;

typedef struct s_data
{
	double		time;
	double		oldtime;
	double		frametime;
	mlx_t		*mlx;
	mlx_image_t	*buf;
}	t_data;

typedef struct s_mv
{
	double	mspeed;
	double	rpeed;
	double	olddirx;
	double	oldplanex;
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
}	t_raycaster;

typedef struct s_overlay
{
	mlx_image_t	*pos;
	char		*str;
}	t_overlay;

/*PARSING**********************************************************************/

/*MLX**************************************************************************/
void			create_img_buffer(mlx_t *mlx);
void			empty_img_buffer(void *param);

/*IMG**************************************************************************/
void			create_background(mlx_t *mlx);
void			create_img_buffer(mlx_t *mlx);
void			empty_img_buffer(void *param);
int				get_rgba(int r, int g, int b, int a);
int				get_r(int rgba);
int				get_g(int rgba);
int				get_b(int rgba);
int				math_rgba(int color, int div, int operator);
void			calc_wall_height(int side);
int				set_colour(int mapx, int mapy, int side);
void			draw_walls(int drawstart, int drawend, int x, int colour);

/*EXEC*************************************************************************/
void			ft_raycaster(void *param);
void			ft_moves(mlx_key_data_t keydata, void *param);
void			ft_ctrls(void *param);

/*UTILS************************************************************************/
void			set_direction(int d);

/*STRUCTS**********************************************************************/
t_pos			*pos(void);
t_dir			*dir(void);
t_plane			*plane(void);
t_data			*data(void);
t_worldmap		*wm(void);
t_raycaster		*ray(void);


void	ft_overlay(mlx_t *mlx);

#endif