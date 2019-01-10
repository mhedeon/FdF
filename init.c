/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:07:08 by mhedeon           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/10 16:04:58 by mhedeon          ###   ########.fr       */
=======
/*   Updated: 2019/01/10 15:49:22 by mhedeon          ###   ########.fr       */
>>>>>>> aa7ae68d94f88822257bead5079849a94f40309a
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_mlx(t_mlx *mlx, t_map *map, t_img *img, t_view *field)
{
	mlx->help = -1;
	mlx->map = map;
	mlx->img = img;
	mlx->field = field;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
}

static void		init_field(t_map *map, t_view *field)
{
	field->zoom = 1;
	field->blur = 1;
	field->height = 1;
	field->angle_x = 315;
	field->angle_y = 15;
	field->angle_z = 340;
	field->move_x = 0;
	field->move_y = 0;
}

static void		init_img(t_mlx *mlx, t_img *img)
{
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
	img->img = mlx_get_data_addr(img->img_ptr,
									&img->bits, &img->size, &img->end);
	img->bits /= 8;
}

void			initial(t_mlx *mlx, t_map *map, t_img *img, t_view *field)
{
	int			x;
	int			y;

	init_mlx(mlx, map, img, field);
	init_field(map, field);
	init_img(mlx, img);
	y = -1;
	field->top = (t_top **)malloc(sizeof(t_top) * map->height);
	while (++y < map->height)
		field->top[y] = (t_top *)malloc(sizeof(t_top) * map->width);
}

void			destruct(t_mlx *mlx)
{
	int			y;

	y = -1;
	while (++y < mlx->map->height)
	{
		free(mlx->map->top[y]);
		free(mlx->field->top[y]);
	}
	free(mlx->map->top);
	free(mlx->field->top);
	free(mlx->img->img);
	exit(1);
}
