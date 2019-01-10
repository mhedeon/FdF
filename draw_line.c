/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:13:12 by mhedeon           #+#    #+#             */
/*   Updated: 2018/07/03 15:57:55 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel_img(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(mlx->img->img + x * mlx->img->bits + y * mlx->img->size) =
			mlx_get_color_value(mlx->mlx_ptr, color);
}

int			rgb(int s, int e, double d_color)
{
	int		r;
	int		g;
	int		b;

	r = (s >> 16) + ((e >> 16) - (s >> 16)) * d_color;
	g = ((s >> 8) & 0xFF) + ((e >> 8 & 0xFF) - (s >> 8 & 0xFF)) * d_color;
	b = (s & 0xFF) + ((e & 0xFF) - (s & 0xFF)) * d_color;
	return (r << 16 | g << 8 | b);
}

static int	color(t_top *s, t_top *e, int *arr)
{
	int		color;
	double	d_color;
	int		full_len;
	int		curr_len;

	if (s->c - e->c == 0)
		return (s->c);
	full_len = (int)sqrt(arr[0] * arr[0] + arr[1] * arr[1]);
	curr_len = (int)sqrt(fabs(e->x - arr[7]) * fabs(e->x - arr[7]) +
					fabs(e->y - arr[8]) * fabs(e->y - arr[8]));
	d_color = ((full_len - curr_len) / (double)full_len);
	color = rgb(s->c, e->c, d_color);
	return (color);
}

/*
** arr[0] - dx - full length_x
** arr[1] - dy - full length_y
** arr[2] - sx - step_x
** arr[3] - sy - step_y
** arr[4] - d
** arr[5] - d1
** arr[6] - d2
** arr[7] - x
** arr[8] - y
*/

static void	init_arr(int *arr, t_top *s, t_top *e)
{
	arr[0] = fabs(e->x - s->x);
	arr[1] = fabs(e->y - s->y);
	arr[2] = e->x >= s->x ? 1 : -1;
	arr[3] = e->y >= s->y ? 1 : -1;
	arr[4] = arr[1] <= arr[0] ? (arr[1] << 1) - arr[0] :
				(arr[0] << 1) - arr[1];
	arr[5] = arr[1] <= arr[0] ? arr[1] << 1 :
				arr[0] << 1;
	arr[6] = arr[1] <= arr[0] ? (arr[1] - arr[0]) << 1 :
				(arr[0] - arr[1]) << 1;
	arr[7] = arr[1] <= arr[0] ? s->x + arr[2] : s->x;
	arr[8] = arr[1] <= arr[0] ? s->y : s->y + arr[3];
}

void		draw_line(t_mlx *mlx, t_top *s, t_top *e)
{
	int		i;
	int		arr[9];

	i = 0;
	init_arr(arr, s, e);
	put_pixel_img(mlx, s->x, s->y, color(s, e, arr));
	while (++i < arr[arr[1] <= arr[0] ? 0 : 1] + 1)
	{
		if (arr[4] > 0)
		{
			arr[4] += arr[6];
			arr[arr[1] <= arr[0] ? 8 : 7] += arr[arr[1] <= arr[0] ? 3 : 2];
		}
		else
			arr[4] += arr[5];
		put_pixel_img(mlx, arr[7], arr[8], color(s, e, arr));
		arr[arr[1] <= arr[0] ? 7 : 8] += arr[arr[1] <= arr[0] ? 2 : 3];
	}
}
