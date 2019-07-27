/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:06:13 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/10 19:46:50 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <unistd.h>

static int	fill_map(t_map *map, char *line)
{
	static int	i = 0;
	int			j;

	j = -1;
	while (++j < map->width)
		map->map[i][j] = (line[j] == 'W' ? 1 : 0);
	i++;
	return (1);
}

void		map_handler(t_map *map, char *str)
{
	int			fd;
	char		*line;

	if ((fd = open(str, O_RDONLY)) == -1)
		function_problem(1);
	while (get_next_line(fd, &line) == 1 && ++map->height)
	{
		map->width = ft_strlen(line);
		free(line);
	}
	close(fd);
	map->map = ft_double_tab_int(map->height, map->width);
	if ((fd = open(str, O_RDONLY)) == -1)
		function_problem(1);
	while (get_next_line(fd, &line) == 1 && fill_map(map, line))
		free(line);
	close(fd);
}
