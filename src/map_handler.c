/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:06:13 by bmenant           #+#    #+#             */
/*   Updated: 2019/08/03 13:40:30 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"

void		free_map(int **map, int height)
{
	int i;

	i = -1;
	while (++i < height)
		free(map[i]);
	free(map);
}

static void	map_check(int **map, int width, int height)
{
	int	i;

	i = -1;
	while (++i < height)
	{
		if (map[i][0] != 1 || map[i][width - 1] != 1)
		{
			free_map(map, height);
			function_problem(2);
		}
	}
	i = -1;
	while (++i < width)
	{
		if (map[0][i] != 1 || map[height - 1][i] != 1)
		{
			free_map(map, height);
			function_problem(2);
		}
	}
}

static int	fill_map(t_map *map, char *line)
{
	static int	i = 0;
	int			j;

	j = -1;
	while (++j < map->width)
	{
		if (!(line[j] == 'W' || line[j] == ' '
			|| line[j] == 'S' || line[j] == 'T'))
		{
			free_map(map->map, map->height);
			function_problem(2);
		}
		map->map[i][j] = (line[j] == 'W' ? 1 : 0);
		map->map[i][j] = (line[j] == 'S' ? 2 : map->map[i][j]);
		map->map[i][j] = (line[j] == 'T' ? 3 : map->map[i][j]);
	}
	i++;
	return (1);
}

void		map_handler(t_map *map, char *str)
{
	int			fd;
	char		*line;

	if ((fd = open(str, O_RDONLY)) == -1)
		function_problem(1);
	map->height = 0;
	while (get_next_line(fd, &line) == 1 && ++map->height)
	{
		if (map->height > 1 && map->width != (int)ft_strlen(line))
		{
			free(line);
			function_problem(2);
		}
		map->width = ft_strlen(line);
		free(line);
	}
	close(fd);
	if (map->height == 0)
	{
		free(line);
		function_problem(2);
	}
	map->map = ft_double_tab_int(map->height, map->width);
	if ((fd = open(str, O_RDONLY)) == -1)
		function_problem(1);
	while (get_next_line(fd, &line) == 1 && fill_map(map, line))
		free(line);
	close(fd);
	map_check(map->map, map->width, map->height);
}
