/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 20:35:27 by mhedeon           #+#    #+#             */
/*   Updated: 2018/07/02 22:36:47 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rot_init(t_view *field, double rot_all[3][3])
{
	double	xangle;
	double	yangle;
	double	zangle;

	xangle = field->angle_x * M_PI / 180.0;
	yangle = field->angle_y * M_PI / 180.0;
	zangle = field->angle_z * M_PI / 180.0;
	rot_all[0][0] = cos(-yangle) * cos(-zangle);
	rot_all[1][0] = sin(-xangle) * sin(-yangle) *
						cos(-zangle) + cos(-xangle) * sin(-zangle);
	rot_all[2][0] = sin(-xangle) * sin(-zangle) - cos(-xangle) *
						sin(-yangle) * cos(-zangle);
	rot_all[0][1] = -cos(-yangle) * sin(-zangle);
	rot_all[1][1] = cos(-xangle) * cos(-zangle) - sin(-xangle) *
						sin(-yangle) * sin(-zangle);
	rot_all[2][1] = cos(-xangle) * sin(-yangle) * sin(-zangle) +
						sin(-xangle) * cos(-zangle);
	rot_all[0][2] = sin(-yangle);
	rot_all[1][2] = -sin(-xangle) * cos(-yangle);
	rot_all[2][2] = cos(-xangle) * cos(-yangle);
}

void		rot(t_map *map, t_view *field)
{
	int		x;
	int		y;
	double	tmp[3];
	double	rot_all[3][3];

	rot_init(field, rot_all);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			tmp[0] = rot_all[0][0] * field->top[y][x].x + rot_all[0][1] *
						field->top[y][x].y + rot_all[0][2] * field->top[y][x].z;
			tmp[1] = rot_all[1][0] * field->top[y][x].x + rot_all[1][1] *
						field->top[y][x].y + rot_all[1][2] * field->top[y][x].z;
			tmp[2] = rot_all[2][0] * field->top[y][x].x + rot_all[2][1] *
						field->top[y][x].y + rot_all[2][2] * field->top[y][x].z;
			field->top[y][x].x = tmp[0];
			field->top[y][x].y = tmp[1];
			field->top[y][x].z = tmp[2];
		}
	}
}

void		zoom(t_map *map, t_view *field)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			field->top[y][x].x *= field->zoom;
			field->top[y][x].y *= field->zoom;
			field->top[y][x].z *= field->zoom;
		}
	}
}

void		move(t_map *map, t_view *field)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			field->top[y][x].x += field->move_x;
			field->top[y][x].y += field->move_y;
		}
	}
}

void		height(t_map *map, t_view *field)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			field->top[y][x].z *= field->height;
	}
}
