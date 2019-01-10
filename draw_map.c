/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:24:39 by mhedeon           #+#    #+#             */
/*   Updated: 2018/07/03 17:04:35 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_field(t_map *map, t_view *field)
{
	int			x;
	int			y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			field->top[y][x].x = map->top[y][x].x;
			field->top[y][x].y = map->top[y][x].y;
			field->top[y][x].z = map->top[y][x].z;
			field->top[y][x].c = map->top[y][x].c;
		}
	}
}

static void		trans_field(t_mlx *mlx, t_map *map, t_view *field)
{
	int			x;
	int			y;

	if (field->blur > 0)
		ft_bzero((void *)mlx->img->img, mlx->img->size * WIN_HEIGHT);
	get_field(map, field);
	height(map, field);
	rot(map, field);
	zoom(map, field);
	move(map, field);
	if (mlx->help > 0)
		draw_frame(mlx);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			field->top[y][x].x += WIN_WIDTH / 2.0;
			field->top[y][x].y += WIN_HEIGHT / 2.0;
		}
	}
}

void			draw_map(t_mlx *mlx, t_map *map, t_view *field)
{
	int			x;
	int			y;

	trans_field(mlx, map, field);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width - 1)
		{
			if (y > 0)
				draw_line(mlx, &field->top[y][x], &field->top[y - 1][x]);
			draw_line(mlx, &field->top[y][x], &field->top[y][x + 1]);
			if (y < map->height - 1)
				draw_line(mlx, &field->top[y][x], &field->top[y + 1][x + 1]);
		}
		if (y > 0)
			draw_line(mlx, &field->top[y][x], &field->top[y - 1][x]);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
							mlx->img->img_ptr, 0, 0);
}
