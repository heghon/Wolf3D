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
	data->mlx.last_img = clock();
	if (data->mlx.next_img > data->mlx.last_img)
		return (0);
	data->mlx.next_img = data->mlx.last_img + (CLOCKS_PER_SEC / 100);
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
	launch_rays(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
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
	//mlx_loop_hook(data.mlx.win, loop_handler, &data);
	//mlx_hook(data.mlx.win, 2, 5, key_handler, (void*)0);
	//mlx_hook(data.mlx.win, 17, 0L, close_window, (void*)0);
	mlx_loop(data.mlx.ptr);
	close_window(NULL);
	return (0);
}
