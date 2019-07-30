/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:55:00 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/25 14:30:29 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include "../inc/wolf3d_define.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <time.h>
#include <mlx.h>

#include <stdio.h>

static int		close_window(void *param)
{
	(void)param;
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
	/*
	if (data->player.forward_move)
		forward_move(data);
	if (data->player.backward_move)
		backward_move(data);
	if (data->player.right_move)
		right_move(data);
	if (data->player.left_move)
		left_move(data);
	if (data->player.up_move)
		jump_handler(data);
	if (data->player.down_move)
		crouch_handler(data);
		*/
		data->mlx.last_img = clock();
	if (data->mlx.next_img > data->mlx.last_img)
		return (0);
	data->mlx.next_img = data->mlx.last_img + (CLOCKS_PER_SEC / 100);
		launch_rays(data);
	return (0);
}

int key_handler(int key, t_data *data)
{
	if (key == M)
		data->player.angle -= 1.0;
	else if (key == N)
		data->player.angle += 1.0;
	else if (key == ARROW_LEFT)
		data->player.pos[Y] -= 64;
	else if (key == ARROW_RIGHT)
		data->player.pos[Y] += 64;
	else if (key == ARROW_UP)
		data->player.pos[X] -= 64;
	else if (key == ARROW_DOWN)
		data->player.pos[X] += 64;
	data->player.angle = data->player.angle == -1 ? 359 : data->player.angle;
	data->player.angle = data->player.angle == 360 ? 0 : data->player.angle;
	//printf ("%f\n", data->player.angle);
	loop_handler(data);
	printf("\n\n\n");
	return (0);
}
int				main(int ac, char **av)
{
	t_data		data;
	int i;
	int j;

	if (ac != 2)
		function_problem(0);
	map_handler(&data.map, av[1]);
	
	i = -1;
	while (++i < data.map.height)
	{
		j = -1;
		while (++j < data.map.width)
			printf("%d ", data.map.map[i][j]);
		printf("\n");
	}



	init(&data);
	data.mlx.win = mlx_new_window(data.mlx.ptr, WIN_L, WIN_H, "WOLFENSTEIN");
	loop_handler(&data);
	mlx_hook(data.mlx.win, 2, 5, key_handler, &data);
	mlx_hook(data.mlx.win, 17, 0L, close_window, (void*)0);
	//mlx_loop_hook(data.mlx.win, loop_handler, &data);
	mlx_loop(data.mlx.ptr);
	return (0);
}
