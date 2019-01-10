/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:58:49 by mhedeon           #+#    #+#             */
/*   Updated: 2018/07/03 17:13:29 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_map	map;
	t_mlx	mlx;
	t_img	img;
	t_view	field;

	if (valid_file(ac, av, &map))
	{
		initial(&mlx, &map, &img, &field);
		draw_map(&mlx, &map, &field);
		set_info(&mlx);
		mlx_hook(mlx.win_ptr, 2, 0, deal_key, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	return (0);
}
