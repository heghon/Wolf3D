/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:09:48 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/27 09:40:28 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../libft/libft.h"
#include <math.h>

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
	ray.xa = (angle > 90 && angle < 270 ? -64 : 64);
	ray.ya = GRID_S * tan(angle);
	a[0] = ft_round_down(player.x, GRID_S) * GRID_S;
	a[0] += (angle > 90 && angle < 270 ? -1 : GRID_S);
	a[1] = player.y + (player.x - a[0]) * tan(angle);
	if (map[ft_round_down(a[1], GRID_S)][ft_round_down(a[0], GRID_S)] == 1)
		return ((ft_absolute(player.y - a[1]) / sin(angle)) * cos(beta));
	while (map[ft_round_down(a[1], GRID_S)][ft_round_down(a[0], GRID_S)] != 1)
	{
		a[0] += ray.xa;
		a[1] += ray.ya;
	}
	return ((ft_absolute(player.y - a[1]) / sin(angle)) * cos(beta));
}

static int	horizontal_check(t_ray ray, t_player player, int **map)
{
	int	a[2];
	int	angle;
	int	beta;

	angle = player.angle + (player.fov / 2) - (ray.nbr * ray.angle_inc);
	beta = ft_absolute(player.angle - angle);
	ray.ya = (angle < 180 ? -64 : 64);
	ray.xa = GRID_S / tan(angle);
	a[1] = ft_round_down(player.y, GRID_S) * GRID_S;
	a[1] += (angle < 180 && angle ? -1 : GRID_S);
	a[0] = player.x + (player.y - a[1]) / tan(angle);
	if (map[ft_round_down(a[1], GRID_S)][ft_round_down(a[0], GRID_S)] == 1)
		return ((ft_absolute(player.x - a[0]) / cos(angle)) * cos(beta));
	while (map[ft_round_down(a[1], GRID_S)][ft_round_down(a[0], GRID_S)] != 1)
	{
		a[0] += ray.xa;
		a[1] += ray.ya;
	}
	return ((ft_absolute(player.x - a[0]) / cos(angle)) * cos(beta));
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
		data->ray.nbr = i;
		h = horizontal_check(data->ray, data->player, data->map.map);
		v = vertical_check(data->ray, data->player, data->map.map);
		data->ray.dist = (h < v ? h : v);
		draw_the_ray(data);
	}
}
