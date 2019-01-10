/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:20:42 by mhedeon           #+#    #+#             */
/*   Updated: 2018/07/03 17:10:39 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft/get_next_line.h"
# include "libft/libft.h"

# include <stdio.h>
# include <string.h>

# define WIN_HEIGHT 1200
# define WIN_WIDTH 2000

# define KEY_ESC 53
# define KEY_ENTER 36
# define KEY_H 4
# define KEY_X 7
# define KEY_Y 16
# define KEY_Z 6
# define KEY_ZOOM_PLUS 69
# define KEY_ZOOM_MINUS	78
# define KEY_MOVE_UP 126
# define KEY_MOVE_DOWN 125
# define KEY_MOVE_LEFT 123
# define KEY_MOVE_RIGHT 124
# define KEY_HEIHGT_PLUS 47
# define KEY_HEIHGT_MINUS 43

typedef struct	s_top
{
	double		x;
	double		y;
	double		z;
	int			c;
}				t_top;

typedef struct	s_map
{
	int			width;
	int			height;
	t_top		**top;
}				t_map;

typedef struct	s_view
{
	double		zoom;
	int			blur;
	double		height;
	int			move_x;
	int			move_y;
	int			angle_x;
	int			angle_y;
	int			angle_z;
	t_top		**top;
}				t_view;

typedef struct	s_img
{
	int			end;
	int			bits;
	int			size;
	char		*img;
	void		*img_ptr;
}				t_img;

typedef struct	s_mlx
{
	int			help;
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_img		*img;
	t_view		*field;
}				t_mlx;

void			set_info(t_mlx *mlx);
void			destruct(t_mlx *mlx);
int				get_width(char **tmp);
void			transf_map(t_map *map);
void			draw_frame(t_mlx *mlx);
int				deal_key(int key, t_mlx *mlx);
void			rot(t_map *map, t_view *field);
void			zoom(t_map *map, t_view *field);
void			move(t_map *map, t_view *field);
int				rgb(int s, int e, double d_color);
void			height(t_map *map, t_view *field);
int				valid_map(char *filename, t_map *map);
int				parse_top(t_map *map, char *tmp, int x);
int				valid_file(int ac, char **av, t_map *map);
void			draw_line(t_mlx *mlx, t_top *s, t_top *e);
void			draw_img(t_mlx *mlx, t_img *img, t_map *map);
void			draw_map(t_mlx *mlx, t_map *map, t_view *field);
void			initial(t_mlx *mlx, t_map *map, t_img *img, t_view *field);

#endif
