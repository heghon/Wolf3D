/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:09:48 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/28 16:14:08 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include "../inc/wolf3d_define.h"
#include "../inc/wolf3d_struct.h"
#include "../libft/libft.h"
#include <math.h>
#include <unistd.h>

#include <stdio.h>

static void	draw_the_ray(t_data *data)
{
	int		size;
	int		start;
	int		stop;

	size = ((GRID_S / (data->ray.dist + 0.001)) * (PLAN_DIST / 4));
	start = PROJ_PLANE_H / 2 - size / 2;
	start = (start < 0 ? 0 : start);
	stop = size / 2 + PROJ_PLANE_H / 2;
	stop = (stop > PROJ_PLANE_H ? PROJ_PLANE_H : stop);
	drawing_handler(size, start, stop, data);
}

static int	vertical_check(t_ray ray, t_player player, int **map, t_tables t)
{
	int		a[2];
	float	angle;
	float	beta;

	angle = (float)player.angle + (float)(player.fov / 2.0) - ((float)ray.nbr * ray.angle_inc);
	beta = (float)fabs(player.angle - angle);
	//printf("angle = %f et beta = %f\n", angle, beta);
	ray.xa = (angle > 90 && angle < 270 ? -GRID_S : GRID_S);
	ray.xa = (angle == 90 || angle == 270 ? 0 : ray.xa);
	ray.ya = GRID_S * tan(ft_arc_to_rad(angle));
	ray.ya *= (angle > 0 && angle < 180 ? -1 : 1);
	ray.ya = (angle == 0 || angle == 180 ? GRID_S : ray.ya);
	ray.ya *= (angle == 0 ? 1 : -1);
	//printf(" tet = %f\n", t.tan[5]);
	a[X] = (player.pos[X] / GRID_S) * GRID_S;
	a[X] += (angle > 90 && angle < 270 ? -1 : GRID_S);
	a[Y] = player.pos[Y] + (player.pos[X] - a[X]) * tan(ft_arc_to_rad(angle));
	//printf("a0 = %d et a1 = %d\n", a[X], a[Y]);
	//if (map[ft_round_down(a[Y], GRID_S)][ft_round_down(a[X], GRID_S)] == 1)
	//	return ((ft_absolute(player.pos[Y] - a[Y]) / sin(angle)) * cos(beta));
	while (!(a[X] < 0 || a[Y] < 0) && (map[a[Y] / GRID_S][a[X] / GRID_S] != 1))
	{
		//printf("4\n");
		a[X] += ray.xa;
		a[Y] += ray.ya;
	}
	return (fabs((player.pos[Y] - a[Y]) / sin(ft_arc_to_rad(angle)) * cos(ft_arc_to_rad(beta))));
}
static int	horizontal_check(t_ray ray, t_player player, int **map, t_tables t)
{
	int		a[2];
	float	angle;
	float	beta;

	angle = (float)player.angle + (float)(player.fov / 2.0) - ((float)ray.nbr * ray.angle_inc);
	beta = (float)fabs(player.angle - angle);

	ray.ya = (angle < 180 && angle > 0 ? -GRID_S : GRID_S);
	ray.ya = (angle == 0 || angle == 180 ? 0 : ray.ya);
	ray.xa = GRID_S / tan(ft_arc_to_rad(angle));
	ray.xa *= (angle > 90 && angle < 270 ? -1 : 1);
	ray.xa = (angle == 90 || angle == 270 ? GRID_S : ray.xa);
	ray.xa *= (angle == 90 ? -1 : 1);
	//printf("2 xa=%d ya=%d\n", ray.xa, ray.ya);
	a[Y] = (player.pos[Y] / GRID_S) * GRID_S;
	a[Y] += (angle < 180 && angle > 0 ? -1 : GRID_S);
	a[X] = player.pos[X] + (player.pos[Y] - a[Y]) / tan(ft_arc_to_rad(angle));
	//printf("3 a0=%d a1=%d\n", a[X], a[Y]);
	//	if (map[ft_round_down(a[Y], GRID_S)][ft_round_down(a[X], GRID_S)] == 1)
	//		return ((ft_absolute(player.pos[X] - a[X]) / cos(angle)) * cos(beta));
	while (!(a[X] < 0 || a[Y] < 0) && (map[a[Y] / GRID_S][a[X] / GRID_S] != 1))
	{
		//printf("4 div1=%d, div0=%d\n", a[Y] / GRID_S, a[X] / GRID_S);
		a[X] += ray.xa;
		a[Y] += ray.ya;
		//printf("PRE5 a0=%d a1=%d\n", a[X], a[Y]);
		//printf("5 div1=%d, div0=%d\n", a[Y] / GRID_S, a[X] / GRID_S);
		//if (a[X] < 0 || a[Y] < 0)
		//	return (0);
	}
	//if (ray.nbr == 640)
	//	printf("\n");
	//printf("6\n");
	return (fabs((player.pos[X] - a[X]) / cos(ft_arc_to_rad(angle)) * cos(ft_arc_to_rad(beta))));
}

void		launch_rays(t_data *data)
{
	int		i;
	float	h;
	float	v;

	i = -1;
	data->ray.angle_inc = (float)data->player.fov / (float)WIN_L;
	//:printf("inc = %f\n", data->ray.angle_inc);
	while (++i < WIN_L)
	{
		//sleep(1);
		//printf("NBR RAY %d\n", i);
		data->ray.nbr = i;
		v = (float)vertical_check(data->ray, data->player, data->map.map, data->tables);
		h = (float)horizontal_check(data->ray, data->player, data->map.map, data->tables);
		data->ray.dist = (h < v ? h : v);
		data->ray.hit = (h <= v ? 'h' : 'v');
		//printf("h = %f, v = %f, dist = %f\n", h, v, data->ray.dist);
		draw_the_ray(data);
		//printf("%f\n", data->player.angle + (data->player.fov / 2) - (data->ray.nbr * data->ray.angle_inc));
	}
}
