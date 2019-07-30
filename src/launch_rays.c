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

	//printf(" DTR %d", data->ray.dist);
	//usleep()	
	if (data->ray.dist == 0)
		size = PLANE_DIST;
	else
		size = (GRID_S / (float)data->ray.dist) * (PLANE_DIST / 3);
	start = PROJ_PLANE_H / 2 - size / 2;
	start = (start < 0 ? 0 : start);
	stop = size / 2 + PROJ_PLANE_H / 2;
	stop = (stop > PROJ_PLANE_H ? PROJ_PLANE_H - 1 : stop);
	//printf("  ENDDTR %d\n", size);
	drawing_handler(size, start, stop, data);
}

static int	vertical_check(t_ray ray, t_player player, t_map map)
{
	int	a[2];
	float	angle;
	float	beta;

	angle = player.angle + (player.fov / 2.0) - (ray.nbr * ray.angle_inc);
	if (angle >= 360.0)
		angle -= 360.0;
	
	beta = fabs(player.angle - angle);
	
	printf("1");
	ray.xa = angle > 90 && angle < 270 ? -GRID_S : GRID_S;
	ray.ya = GRID_S * tan(ft_arc_to_rad(angle));
	//printf("2");
	a[X] = player.pos[X] / GRID_S * GRID_S;
	//printf("1 %d %d \n", a[X], a[Y]);
	a[X] += angle > 90 && angle < 270 ? -1 : GRID_S;
	//printf("2 %d %d \n", a[X], a[Y]);
	a[Y] = player.pos[Y] + (player.pos[X] - a[X]) * tan(ft_arc_to_rad(angle));
	//if (map[ft_round_down(a[Y], GRID_S)][ft_round_down(a[X], GRID_S)] == 1)
	//	return ((abs(player.pos[Y] - a[Y]) / sin(angle)) * cos(beta));
	printf("2 %d %d \n", a[X], a[Y]);
	if (a[X] < 0 || a[Y] < 0 || a[X] > map.width * GRID_S || a[Y] > map.height * GRID_S)
		return (100000);
	printf("3");
	while (map.map[a[Y] / GRID_S][a[X] / GRID_S] != 1)
	{
		printf("4");
		a[X] += ray.xa;
		a[Y] += ray.ya;
		//printf("5 ");
		if (a[X] < 0 || a[Y] < 0 || a[X] > map.width * GRID_S || a[Y] > map.height * GRID_S)
			return (100000);
	}
	printf("5");
	//printf("6 %f %f %f\n", (sin(ft_arc_to_rad(angle)) * cos(ft_arc_to_rad(beta))), sin(ft_arc_to_rad(angle)), cos(ft_arc_to_rad(beta)));
	//printf("3 %d %d \n", a[X], a[Y]);
	return (fabs( (player.pos[X] - a[X]) / cos(ft_arc_to_rad(angle)) ) * cos(ft_arc_to_rad(beta)) );
}

static int	horizontal_check(t_ray ray, t_player player, t_map map)
{
	int	a[2];
	float	angle;
	float	beta;

	angle = player.angle + (player.fov / 2.0) - (ray.nbr * ray.angle_inc);
	if (angle >= 360.0)
		angle -= 360.0;
	//angle = fabs(angle);
	
	
	beta = fabs(player.angle - angle);
	
	//printf("1\n");
	ray.ya = angle < 180.0 ? -GRID_S : GRID_S;
	ray.xa = GRID_S / tan(ft_arc_to_rad(angle));
	//printf("2 xa=%d ya=%d\n", ray.xa, ray.ya);
	a[Y] = player.pos[Y] / GRID_S * GRID_S;
	a[Y] += angle < 180.0 ? -1 : GRID_S;
	a[X] = player.pos[X] + (player.pos[Y] - a[Y]) / tan(ft_arc_to_rad(angle));
	//printf("3 a0=%d a1=%d\n", a[X], a[Y]);
	//	if (map[ft_round_down(a[Y], GRID_S)][ft_round_down(a[X], GRID_S)] == 1)
	//		return ((ft_absolute(player.pos[X] - a[X]) / cos(angle)) * cos(beta));
	printf("6");
	if (a[X] < 0 || a[Y] < 0 || a[X] > map.width * GRID_S || a[Y] > map.height * GRID_S)
		return (100000);
	while (map.map[a[Y] / GRID_S][a[X] / GRID_S] != 1)
	{
		//printf("4 div1=%d, div0=%d\n", a[Y] / GRID_S, a[X] / GRID_S);
		a[X] += ray.xa;
		a[Y] += ray.ya;
		//printf("PRE5 a0=%d a1=%d\n", a[X], a[Y]);
		//printf("5 div1=%d, div0=%d\n", a[Y] / GRID_S, a[X] / GRID_S);
		//if (a[X] < 0 || a[Y] < 0)
		//	return (0);
		if (a[X] < 0 || a[Y] < 0 || a[X] > map.width * GRID_S || a[Y] > map.height * GRID_S)
			return (100000);
	}
	printf("7 ");
	//if (ray.nbr == WIN_L / 2)
	//	printf("\n %f", angle);
	return (fabs( (player.pos[Y] - a[Y]) / sin(ft_arc_to_rad(angle)) ) * cos(ft_arc_to_rad(beta)) );
}

void		launch_rays(t_data *data)
{
	int	i;
	float	h;
	float	v;

	i = -1;
	data->ray.angle_inc = (double)data->player.fov / (double)WIN_L;
	//printf("%d %d       ", data->player.pos[X], data->player.pos[Y]);
	while (++i < WIN_L)
	{
		//printf("NBR RAY %d\n", i);
		data->ray.nbr = i;
		h = horizontal_check(data->ray, data->player, data->map);
		v = vertical_check(data->ray, data->player, data->map);
		//printf("outVC");
		data->ray.dist = h <= v ? h : v;
		data->ray.hit = h <= v ? 'h' : 'v';
		printf(" %c", data->ray.hit);
		draw_the_ray(data);
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
}
