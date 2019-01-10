/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 19:05:52 by mhedeon           #+#    #+#             */
/*   Updated: 2018/07/03 15:54:52 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(char *filename)
{
	int		i;
	char	buff;
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &buff, 1))
		i = buff == '\n' ? i + 1 : i;
	close(fd);
	return (i);
}

static int	get_color(char *hex)
{
	int		i;
	int		color;
	int		digit;

	i = ft_strlen(hex) - 1;
	color = 0;
	while (*hex)
	{
		digit = ft_isalpha(*hex) ? ft_toupper(*hex) - 'A' + 10 : *hex - '0';
		color += digit * ft_pow(16, i--);
		hex++;
	}
	return (color);
}

int			parse_top(t_map *map, char *tmp, int x)
{
	int		i;

	i = -1;
	map->top[map->height][x].x = x;
	map->top[map->height][x].y = map->height;
	while (tmp[++i] != ',' && tmp[i])
		if (!(tmp[i] == '-' ? ft_isdigit(tmp[i + 1]) : ft_isdigit(tmp[i])))
			return (FALSE);
	map->top[map->height][x].z = (double)ft_atoi(tmp);
	map->top[map->height][x].c = tmp[i] ? get_color(&tmp[i + 3]) : 0xFFFFFF;
	return (1);
}

int			valid_map(char *filename, t_map *map)
{
	int		fd;
	int		x;
	char	*line;
	char	**tmp;

	map->top = (t_top **)malloc(sizeof(t_top) * get_height(filename));
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) && (tmp = ft_strsplit(line, ' ')))
	{
		x = -1;
		map->top[map->height] = (t_top *)malloc(sizeof(t_top) * get_width(tmp));
		while (tmp[++x])
			if (!parse_top(map, tmp[x], x))
				return (FALSE);
		ft_matrixdel((void **)tmp, x);
		free(line);
		if (map->width != 0 && map->width != x)
			return (FALSE);
		else
			map->width = x;
		map->height++;
	}
	close(fd);
	transf_map(map);
	return (TRUE);
}
