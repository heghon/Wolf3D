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
#include <mlx.h>

#include <stdio.h>
#include <unistd.h>

static void	draw_the_ray(t_data *data)
{
	int		size;
	int		start;
	int		stop;

	printf(" DTR %d", data->ray.dist);
	//usleep()	
	if (data->ray.dist == 0)
		size = PLANE_DIST;
	else
		size = (GRID_S / (float)data->ray.dist) * (PLANE_DIST / 3);
	start = PROJ_PLANE_H / 2 - size / 2;
	start = (start < 0 ? 0 : start);
	stop = size / 2 + PROJ_PLANE_H / 2;
	stop = (stop > PROJ_PLANE_H ? PROJ_PLANE_H - 1 : stop);
	printf("  ENDDTR %d\n", size);
	drawing_handler(size, start, stop, data);
}

static int	vertical_check(t_ray ray, t_player player, t_map map)
{
	int	a[2];
	float angle;
	float	beta;
//	float test;

//	test = player.fov - (ray.nbr * ray.angle_inc);
	angle = player.angle + (player.fov / 2.0) - (ray.nbr * ray.angle_inc);
	if (angle > 360.0)
		angle -= 360.0;
	//angle = fabs(angle);
	beta = fabs(player.angle - angle);
	printf("1");
	ray.xa = (angle > 90 && angle < 270 ? -GRID_S : GRID_S);
	ray.ya = GRID_S * tan(ft_arc_to_rad(angle));
	printf("2");
	a[0] = player.pos[X] / GRID_S * GRID_S;
	a[0] += angle > 90 && angle < 270 ? -1 : GRID_S;
	a[1] = player.pos[Y] + (player.pos[X] - a[0]) * tan(ft_arc_to_rad(angle));
	//if (map[ft_round_down(a[1], GRID_S)][ft_round_down(a[0], GRID_S)] == 1)
	//	return ((abs(player.pos[Y] - a[1]) / sin(angle)) * cos(beta));
	while (!(a[0] < 0 || a[1] < 0) && !(a[0] > map.width || a[1] > map.height) && (map.map[a[1] / GRID_S][a[0] / GRID_S] != 1))
	{
		printf("4");
		a[0] += ray.xa;
		a[1] += ray.ya;
		printf("5 ");
	}
	printf("6 %f %f %f\n", (sin(ft_arc_to_rad(angle)) * cos(ft_arc_to_rad(beta))), sin(ft_arc_to_rad(angle)), cos(ft_arc_to_rad(beta)));
	return (fabs( (player.pos[X] - a[0]) / cos(ft_arc_to_rad(angle)) ) * cos(ft_arc_to_rad(beta)) );
}

static int	horizontal_check(t_ray ray, t_player player, t_map map)
{
	int	a[2];
	float	angle;
	float	beta;
//	float test;

//	test = player.fov - (ray.nbr * ray.angle_inc) + 60;
	angle = player.angle + (player.fov / 2.0) - (ray.nbr * ray.angle_inc);
	if (angle > 360.0)
		angle -= 360.0;
	angle = fabs(angle);
	//angle = angle == 0 ? 1 : angle;//temp
	beta = fabs(player.angle - angle);
	//printf("1\n");
	ray.ya = (angle < 180 ? -GRID_S : GRID_S);
	ray.xa = GRID_S / tan(ft_arc_to_rad(angle));
	//printf("2 xa=%d ya=%d\n", ray.xa, ray.ya);
	a[1] = player.pos[Y] / GRID_S * GRID_S;
	a[1] += angle < 180 ? -1 : GRID_S;
	a[0] = player.pos[X] + (player.pos[Y] - a[1]) / tan(ft_arc_to_rad(angle));
	//printf("3 a0=%d a1=%d\n", a[0], a[1]);
	//	if (map[ft_round_down(a[1], GRID_S)][ft_round_down(a[0], GRID_S)] == 1)
	//		return ((ft_absolute(player.pos[X] - a[0]) / cos(angle)) * cos(beta));
	while (!(a[0] < 0 || a[1] < 0) && !(a[0] > map.width || a[1] > map.height) && (map.map[a[1] / GRID_S][a[0] / GRID_S] != 1))
	{
		//printf("4 div1=%d, div0=%d\n", a[1] / GRID_S, a[0] / GRID_S);
		a[0] += ray.xa;
		a[1] += ray.ya;
		//printf("PRE5 a0=%d a1=%d\n", a[0], a[1]);
		//printf("5 div1=%d, div0=%d\n", a[1] / GRID_S, a[0] / GRID_S);
		//if (a[0] < 0 || a[1] < 0)
		//	return (0);
	}
	printf("7");
	return (fabs( (player.pos[X] - a[0]) / cos(ft_arc_to_rad(angle)) ) * cos(ft_arc_to_rad(beta)) );
}

void		launch_rays(t_data *data)
{
	int	i;
	float	h;
	float	v;

	i = -1;
	data->ray.angle_inc = (double)data->player.fov / (double)WIN_L;
	printf("%d %d       ", data->player.pos[X], data->player.pos[Y]);
	while (++i < WIN_L)
	{
		//printf("NBR RAY %d\n", i);
		data->ray.nbr = i;
		h = horizontal_check(data->ray, data->player, data->map);
		v = vertical_check(data->ray, data->player, data->map);
		printf("outVC");
		data->ray.dist = (h <= v ? h : v);
		data->ray.hit = (h <= v ? 'h' : 'v');
		//printf("%f")
		draw_the_ray(data);
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
}
