/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:09:48 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/27 15:07:32 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include "../inc/wolf3d_define.h"
#include "../inc/wolf3d_struct.h"
#include "../libft/libft.h"
#include <math.h>

#include <stdio.h>

static void	draw_the_ray(t_data *data)
{
	int		size;
	int		start;
	int		stop;

	size = (int)(PROJ_PLANE_H / data->ray.dist + 0.0001);
	start = PROJ_PLANE_H / 2 - size / 2;
	start = (start < 0 ? 0 : start);
	stop = size / 2 + PROJ_PLANE_H / 2;
	stop = (stop > PROJ_PLANE_H ? PROJ_PLANE_H - 1 : stop);
	drawing_handler(size, start, stop, data);
}

static int	vertical_check(t_ray ray, t_player player, int **map)
{
	int	a[2];
	int angle;
	int	beta;

	angle = player.angle + (player.fov / 2) - (ray.nbr * ray.angle_inc);
	beta = ft_absolute(player.angle - angle);
	//printf("1\n");
	ray.xa = (angle > 90 && angle < 270 ? -GRID_S : GRID_S);
	ray.ya = GRID_S * tan(ft_arc_to_rad(angle));
	//printf("2\n");
	a[0] = ft_round_down(player.x, GRID_S) * GRID_S;
	a[0] += (angle > 90 && angle < 270 ? -1 : GRID_S);
	a[1] = player.y + (player.x - a[0]) * tan(ft_arc_to_rad(angle));
	if (map[ft_round_down(a[1], GRID_S)][ft_round_down(a[0], GRID_S)] == 1)
		return ((ft_absolute(player.y - a[1]) / sin(angle)) * cos(beta));
	while (!(a[0] < 0 || a[1] < 0) && (map[a[1] / GRID_S][a[0] / GRID_S] != 1))
	{
		//printf("4\n");
		a[0] += ray.xa;
		a[1] += ray.ya;
	}
	return ((ft_absolute((player.y - a[1]) / sin(ft_arc_to_rad(angle)) * cos(ft_arc_to_rad(beta)))));
}
static int	horizontal_check(t_ray ray, t_player player, int **map)
{
	int	a[2];
	int	angle;
	int	beta;

	angle = player.angle + (player.fov / 2) - (ray.nbr * ray.angle_inc);
	angle = angle == 0 ? 1 : angle;
	beta = ft_absolute(player.angle - angle);
	//printf("1\n");
	ray.ya = (angle < 180 ? -GRID_S : GRID_S);
	ray.xa = GRID_S / tan(ft_arc_to_rad(angle));
	//printf("2 xa=%d ya=%d\n", ray.xa, ray.ya);
	a[1] = ft_round_down(player.y, GRID_S) * GRID_S;
	a[1] += (angle < 180 && angle ? -1 : GRID_S);
	a[0] = player.x + (player.y - a[1]) / tan(ft_arc_to_rad(angle));
	//printf("3 a0=%d a1=%d\n", a[0], a[1]);
	//	if (map[ft_round_down(a[1], GRID_S)][ft_round_down(a[0], GRID_S)] == 1)
	//		return ((ft_absolute(player.x - a[0]) / cos(angle)) * cos(beta));
	while (!(a[0] < 0 || a[1] < 0) && (map[a[1] / GRID_S][a[0] / GRID_S] != 1))
	{
		//printf("4 div1=%d, div0=%d\n", a[1] / GRID_S, a[0] / GRID_S);
		a[0] += ray.xa;
		a[1] += ray.ya;
		//printf("PRE5 a0=%d a1=%d\n", a[0], a[1]);
		//printf("5 div1=%d, div0=%d\n", a[1] / GRID_S, a[0] / GRID_S);
		//if (a[0] < 0 || a[1] < 0)
		//	return (0);
	}
	//printf("6\n");
	return (ft_absolute((player.x - a[0]) / cos(ft_arc_to_rad(angle)) * cos(ft_arc_to_rad(beta))));
}

void		launch_rays(t_data *data)
{
	int	i;
	int	h;
	int	v;

	i = -1;
	data->ray.angle_inc = (double)data->player.fov / (double)WIN_L;
	while (++i < WIN_L)
	{
		printf("NBR RAY %d\n", i);
		data->ray.nbr = i;
		h = horizontal_check(data->ray, data->player, data->map.map);
		v = vertical_check(data->ray, data->player, data->map.map);
		data->ray.dist = (h < v ? h : v);
		draw_the_ray(data);
	}
}
