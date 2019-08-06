/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:55:00 by bmenant           #+#    #+#             */
/*   Updated: 2019/08/03 13:35:37 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include "../inc/wolf3d_define.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <time.h>
#include <mlx.h>
#include <math.h>
#include <unistd.h>

static int		close_window(t_data *data)
{
	free(data->map.map);
	exit(0);
	return (0);
}

void			function_problem(int mode)
{
	if (mode == 0)
		ft_putendl("Usage : ./wolf3d <map_name>");
	else if (mode == 1)
		ft_putendl("An issue occured, please try again");
	else if (mode == 2)
		ft_putendl("Your map is wrong");
	exit(0);
}

int				loop_handler(t_data *data)
{
	int x;
	int y;

	x = (int)data->player.pos[X];
	y = (int)data->player.pos[Y];
	if (data->player.tp == 1 && data->map.map[x][y] != 3)
		data->player.tp = 0;
	launch_rays(data);
	if (data->map.map[x][y] == 3 && data->player.tp == 0)
		mlx_string_put(data->mlx.ptr, data->mlx.win, WIN_L / 2,
			WIN_H / 2 - 150, 0xFFFFFF, "TELEPORTATION POSSIBLE, PRESS SPACE");
	return (0);
}

int				key_handler(int key, t_data *data)
{
	int x;
	int y;

	x = (int)data->player.pos[X];
	y = (int)data->player.pos[Y];
	if (key == ESC)
	{
		free(data->map.map);
		exit(0);
	}
	if (key == L_SHIFT)
		data->player.sprint += (data->player.sprint == 1 ? 1 : -1);
	if (data->map.map[x][y] == 3 && key == SPACE)
	{
		teleportation(data, &data->player, data->map.map);
		loop_handler(data);
		mlx_string_put(data->mlx.ptr, data->mlx.win, WIN_L / 2,
			WIN_H / 2 - 50, 0xFFFFFF, "! DONE !");
		return (0);
	}
	movements(data, &data->player, key);
	loop_handler(data);
	return (0);
}

int				main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
		function_problem(0);
	map_handler(&data.map, av[1]);
	init(&data);
	data.mlx.win = mlx_new_window(data.mlx.ptr, WIN_L, WIN_H, "WOLFENSTEIN");
	loop_handler(&data);
	mlx_hook(data.mlx.win, 2, 5, key_handler, &data);
	mlx_hook(data.mlx.win, 17, 0L, close_window, &data);
	mlx_loop(data.mlx.ptr);
	return (0);
}
