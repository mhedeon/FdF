/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 21:00:23 by mhedeon           #+#    #+#             */
/*   Updated: 2018/07/03 16:07:31 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	valid_name(char *filename)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_strsplit(filename, '.');
	while (tmp[i])
		i++;
	if (i != 2)
	{
		ft_matrixdel((void *)tmp, i);
		return (FALSE);
	}
	else if (!ft_strcmp(tmp[1], ".fdf"))
	{
		ft_matrixdel((void *)tmp, i);
		return (FALSE);
	}
	ft_matrixdel((void *)tmp, i);
	return (TRUE);
}

int			valid_file(int ac, char **av, t_map *map)
{
	int		fd;

	if (ac != 2)
		ft_putstr("usage: ./fdf [filename]\n");
	else if ((fd = open(av[ac - 1], O_RDONLY)) == -1)
	{
		ft_putstr("The file \"");
		ft_putstr(av[ac - 1]);
		ft_putstr("\" does not exist.\n");
	}
	else if (!valid_name(av[ac - 1]))
		ft_putstr("Invalid filename: \"filename.fdf\"\n");
	else if (!valid_map(av[ac - 1], map))
	{
		ft_putstr("Invalid map in file \"");
		ft_putstr(av[ac - 1]);
		ft_putstr("\"\n");
	}
	else
	{
		close(fd);
		return (TRUE);
	}
	close(fd);
	return (FALSE);
}
