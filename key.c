/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:55:35 by mhedeon           #+#    #+#             */
/*   Updated: 2018/07/03 17:06:05 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move_k(int key, t_mlx *mlx)
{
	if (key == KEY_MOVE_UP)
		mlx->field->move_y -= 10;
	else if (key == KEY_MOVE_DOWN)
		mlx->field->move_y += 10;
	else if (key == KEY_MOVE_RIGHT)
		mlx->field->move_x += 10;
	else if (key == KEY_MOVE_LEFT)
		mlx->field->move_x -= 10;
}

static void	rotate_k(int key, t_mlx *mlx)
{
	if (key == KEY_X)
		mlx->field->angle_x = (mlx->field->angle_x + 5) % 360;
	else if (key == KEY_Y)
		mlx->field->angle_y = (mlx->field->angle_y + 5) % 360;
	else if (key == KEY_Z)
		mlx->field->angle_z = (mlx->field->angle_z + 5) % 360;
}

static void	other_s(int key, t_mlx *mlx)
{
	if (key == KEY_ZOOM_PLUS)
		mlx->field->zoom += 0.1;
	else if (key == KEY_ZOOM_MINUS)
		mlx->field->zoom -= 0.1;
	else if (key == KEY_HEIHGT_PLUS)
		mlx->field->height += 0.1;
	else if (key == KEY_HEIHGT_MINUS)
		mlx->field->height -= 0.1;
	else if (key == KEY_ENTER)
		mlx->field->blur *= -1;
	else if (key == KEY_H)
		mlx->help *= -1;
}

int			deal_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		destruct(mlx);
	move_k(key, mlx);
	rotate_k(key, mlx);
	other_s(key, mlx);
	set_info(mlx);
	draw_map(mlx, mlx->map, mlx->field);
	set_info(mlx);
	return (0);
}
