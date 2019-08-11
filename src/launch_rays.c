/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:09:48 by bmenant           #+#    #+#             */
/*   Updated: 2019/08/03 13:52:40 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include <mlx.h>
#include <math.h>

static void	draw_the_ray(t_data *data)
{
	int		start;
	int		stop;

	start = PROJ_PLANE_H / 2 - data->ray.size / 2;
	start = (start < 0 ? 0 : start);
	stop = data->ray.size / 2 + PROJ_PLANE_H / 2;
	stop = (stop >= PROJ_PLANE_H ? PROJ_PLANE_H - 1 : stop);
	drawing_handler(start, stop, data);
}

static void	init_ray(t_ray *ray, t_player *p)
{
	ray->camx = 2 * ray->nbr / (float)WIN_L - 1;
	ray->dir[X] = p->dir[X] + p->plane[X] * ray->camx;
	ray->dir[Y] = p->dir[Y] + p->plane[Y] * ray->camx;
	ray->map[X] = (int)p->pos[X];
	ray->map[Y] = (int)p->pos[Y];
	ray->delta[X] = fabs(1 / ray->dir[X]);
	ray->delta[Y] = fabs(1 / ray->dir[Y]);
	ray->hit = 0;
	ray->step[X] = (ray->dir[X] < 0 ? -1 : 1);
	ray->step[Y] = (ray->dir[Y] < 0 ? -1 : 1);
	ray->first_dist[X] = (ray->dir[X] < 0 ? (p->pos[X] - ray->map[X])
		* ray->delta[X] : (ray->map[X] + 1.0 - p->pos[X]) * ray->delta[X]);
	ray->first_dist[Y] = (ray->dir[Y] < 0 ? (p->pos[Y] - ray->map[Y])
		* ray->delta[Y] : (ray->map[Y] + 1.0 - p->pos[Y]) * ray->delta[Y]);
}

static void	first_while(t_data *data, int j)
{
	int	x;
	int y;

	while (data->ray.hit == 0 && ++j >= 0)
	{
		if (data->ray.first_dist[X] < data->ray.first_dist[Y])
		{
			data->ray.first_dist[X] += data->ray.delta[X];
			data->ray.map[X] += data->ray.step[X];
			data->ray.side_hit = 0;
		}
		else
		{
			data->ray.first_dist[Y] += data->ray.delta[Y];
			data->ray.map[Y] += data->ray.step[Y];
			data->ray.side_hit = 1;
		}
		x = data->ray.map[X];
		y = data->ray.map[Y];
		data->ray.hit = (data->map.map[x][y] != 0
			&& data->map.map[x][y] != 3 ? 1 : 0);
	}
}

static void	value_calc(t_player *player, t_ray *ray)
{
	if (ray->side_hit == 0)
		ray->wall_x = player->pos[Y] + ray->final_dist * ray->dir[Y];
	else
		ray->wall_x = player->pos[X] + ray->final_dist * ray->dir[X];
	ray->wall_x -= (int)ray->wall_x;
	ray->tex[X] = (int)(ray->wall_x * TEX_S);
	if ((ray->side_hit == 0 && ray->dir[X] > 0)
		|| (ray->side_hit == 1 && ray->dir[Y] < 0))
		ray->tex[X] = TEX_S - ray->tex[X] - 1;
}

void		launch_rays(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_L)
	{
		j = -1;
		data->ray.nbr = i;
		init_ray(&data->ray, &data->player);
		first_while(data, j);
		if (data->ray.side_hit == 0)
		{
			data->ray.final_dist = (data->ray.map[X] - data->player.pos[X]
				+ (1 - data->ray.step[X]) / 2) / data->ray.dir[X];
		}
		else
			data->ray.final_dist = (data->ray.map[Y] - data->player.pos[Y]
				+ (1 - data->ray.step[Y]) / 2) / data->ray.dir[Y];
		data->ray.size = (int)(PROJ_PLANE_H / data->ray.final_dist);
		value_calc(&data->player, &data->ray);
		draw_the_ray(data);
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
}
