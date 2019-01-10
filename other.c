/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 20:53:13 by mhedeon           #+#    #+#             */
/*   Updated: 2018/07/03 17:06:39 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_width(char **tmp)
{
	int	width;

	width = 0;
	while (*tmp)
	{
		width++;
		tmp++;
	}
	return (width);
}

void	transf_map(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->top[y][x].x = (x - map->width / 2.0) * (WIN_WIDTH /
								(double)map->width / 2.0);
			map->top[y][x].y = (y - map->height / 2.0) * (WIN_HEIGHT /
								(double)map->height / 2.0);
		}
	}
}

void	draw_frame(t_mlx *mlx)
{
	t_top	top1;
	t_top	top2;

	top1.x = 41;
	top1.y = 42;
	top1.c = 0x0000FF;
	top2.x = 41;
	top2.y = 195;
	top2.c = 0xFF0000;
	draw_line(mlx, &top1, &top2);
	top2.x = 350;
	top2.y = 42;
	draw_line(mlx, &top1, &top2);
	top1.x = 350;
	top1.y = 195;
	draw_line(mlx, &top1, &top2);
	top2.x = 42;
	top2.y = 195;
	draw_line(mlx, &top1, &top2);
}

void	set_info(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 50, 0xFF0000, "Help:   H");
	if (mlx->help > 0)
	{
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 70,
						0xFF0000, "Move:   up, down, left, right");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 90, 0xFF0000,
						"Rotate: x, y, z");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 110, 0xFF0000,
						"Size:   <, >");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 130, 0xFF0000,
						"Zoom:   +, -");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 150, 0xFF0000,
						"Blure:  Enter(on/off)");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 170, 0xFF0000,
						"Exit:   ESC");
	}
}
