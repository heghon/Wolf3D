/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:09:48 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/31 17:08:14 by bmenant          ###   ########.fr       */
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

	if (data->ray.dist == 0)
		size = PLANE_DIST;
	else
		size = (GRID_S / (float)data->ray.dist) * (PLANE_DIST / 3);
	start = PROJ_PLANE_H / 2 - size / 2;
	start = (start < 0 ? 0 : start);
	stop = size / 2 + PROJ_PLANE_H / 2;
	stop = (stop > PROJ_PLANE_H ? PROJ_PLANE_H - 1 : stop);
	drawing_handler(size, start, stop, data);
}

static float	vertical_check(t_ray *ray, t_player player, int **map, float angle)
{
	int		a[2];
	float	beta;

	beta = (float)fabs(player.angle - angle);
	if (map[ray->v[Y] / GRID_S][ray->v[X] / GRID_S] == 1)
		ray->hit = 1;
	else
	{
		ray->v[X] += ray->x[V];
		ray->v[Y] += ray->y[V];
	}
	return (sqrt((player.pos[X] - ray->v[X]) * (player.pos[X] - ray->v[X]) + (player.pos[Y] - ray->v[Y]) * (player.pos[Y] - ray->v[Y])) * fabs(cos(RAD(beta))));
}

static float	horizontal_check(t_ray *ray, t_player player, int **map, float angle)
{
	float	beta;

	//printf("dans hcheck, posx = %d et hx = %f\n", player.pos[X], ray->h[X]);
	beta = (float)fabs(player.angle - angle);
	if (map[ray->h[Y] / GRID_S][ray->h[X] / GRID_S] == 1)
		ray->hit = 1;
	else
	{
		ray->h[X] += ray->x[H];
		ray->h[Y] += ray->y[H];
	}
	return (sqrt((player.pos[X] - ray->h[X]) * (player.pos[X] - ray->h[X]) + (player.pos[Y] - ray->h[Y]) * (player.pos[Y] - ray->h[Y])) * fabs(cos(RAD(beta))));
}

static void	init_ray(t_data *data, t_player player, float angle)
{
	data->ray.hit = 0;
	data->ray.x[H] = GRID_S / tan(RAD(angle));
	data->ray.y[H] = (angle < 180.0 && angle > 0.0 ? -GRID_S : GRID_S);
	data->ray.x[V] = (angle > 90 && angle < 270 ? -GRID_S : GRID_S);
	data->ray.y[V] = GRID_S * tan(RAD(angle));
	data->ray.h[Y] = (player.pos[Y] / GRID_S) * GRID_S;
	data->ray.h[Y] += (angle < 180.0 ? -1 : GRID_S);
	data->ray.h[X] = player.pos[X] + (player.pos[Y] - data->ray.h[Y]) / tan(RAD(angle));
	data->ray.v[X] = (player.pos[Y] / GRID_S) * GRID_S;
	data->ray.v[X] += (angle > 90 && angle < 270 ? -1 : GRID_S);
	data->ray.v[Y] = player.pos[Y] + (player.pos[X] - data->ray.v[X]) * tan(RAD(angle));
	//printf("ray.x[H] = %f, ray.y[H] = %f, ray.x[V] = %f, ray.y[V] = %f\n", data->ray.x[H], data->ray.y[H], data->ray.x[V], data->ray.y[V]);
	//printf("h[X] = %d, h[Y] = %d, v[X] = %d, v[Y] = %d\n", data->ray.h[X] / GRID_S, data->ray.h[Y] / GRID_S, data->ray.v[X] / GRID_S, data->ray.v[Y] / GRID_S);
}

void		launch_rays(t_data *data)
{
	int		i;
	float	h;
	float	v;
	float	angle;

	i = -1;
	while (++i < 1280)
	{
		angle = data->player.angle + (FOV / 2.0) - (i * ANGLE_INC);
		angle -= (angle >= 360.0 ? 360.0 : 0);
		angle += (angle < 0.0 ? 360.0 : 0);
		printf("angle = %f\n", angle);
		data->ray.nbr = i;
		init_ray(data, data->player, angle);
		while (data->ray.hit == 0)
		{
			if (data->ray.h[X] > 0 && data->ray.h[Y] > 0)
				h = horizontal_check(&data->ray, data->player, data->map.map, angle);
			if (data->ray.v[X] > 0 && data->ray.v[Y] > 0)
				v = vertical_check(&data->ray, data->player, data->map.map, angle);
		}
		data->ray.dist = (h <= v ? h : v);
		//printf("h = %f, v = %f et dist = %f\n", h, v,  data->ray.dist);
		data->ray.side = (h <= v ? 'h' : 'v');
		draw_the_ray(data);
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
}
