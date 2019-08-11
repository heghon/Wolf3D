/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:03:36 by bmenant           #+#    #+#             */
/*   Updated: 2019/08/03 13:57:37 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void				pixel_put(t_data *data, int i, unsigned int c)
{
	int		x;

	x = (i * data->mlx.s_line) + (data->ray.nbr * 4);
	data->mlx.pic[x] = c;
	data->mlx.pic[x + 1] = (c >> 8);
	data->mlx.pic[x + 2] = (c >> 16);
}

static void			pixel_put_tex(t_data *data, int i, int side)
{
	int d;
	int	x;

	x = (i * data->mlx.s_line) + (data->ray.nbr * 4);
	d = i * SIZEX4 - PROJ_PLANE_H * SIZEX2 + data->ray.size * SIZEX2;
	data->ray.tex[Y] = ((d * TEX_S) / data->ray.size) / SIZEX4;
	d = data->ray.tex[Y] * TEX_S + data->ray.tex[X];
	d *= 4;
	if (d > TEX_L)
		d = TEX_L;
	data->mlx.pic[x] = data->mlx.texpic[side][d];
	data->mlx.pic[x + 1] = data->mlx.texpic[side][d + 1];
	data->mlx.pic[x + 2] = data->mlx.texpic[side][d + 2];
}

static unsigned int	choose_tex(t_ray *ray)
{
	if (ray->dir[X] > 0 && ray->side_hit == 0)
		return (0);
	if (ray->dir[X] <= 0 && ray->side_hit == 0)
		return (1);
	if (ray->dir[Y] > 0 && ray->side_hit == 1)
		return (2);
	if (ray->dir[Y] <= 0 && ray->side_hit == 1)
		return (3);
	return (0);
}

static void			pixel_put_floor(t_data *data, int i, int side, float fdist)
{
	float	floor[2];
	int		floort[2];
	float	w;
	int		x;
	int		d;

	x = (i * data->mlx.s_line) + (data->ray.nbr * 4);
	floor[X] = data->ray.map[X];
	floor[Y] = data->ray.map[Y];
	floor[X] += side > 1 ? data->ray.wall_x : 0;
	floor[X] += side == 1 ? 1 : 0;
	floor[Y] += side < 2 ? data->ray.wall_x : 0;
	floor[Y] += side == 3 ? 1 : 0;
	w = fdist / data->ray.final_dist;
	floort[X] = (int)((w * floor[X] + (1.0 - w) * data->player.pos[X])
		* TEX_S) % TEX_S;
	floort[Y] = (int)((w * floor[Y] + (1.0 - w) * data->player.pos[Y])
		* TEX_S) % TEX_S;
	d = (floort[Y] * TEX_S + floort[X]) * 4;
	data->mlx.pic[x] = data->mlx.texpic[4][d];
	data->mlx.pic[x + 1] = data->mlx.texpic[4][d + 1];
	data->mlx.pic[x + 2] = data->mlx.texpic[4][d + 2];
}

void				drawing_handler(int start, int stop, t_data *data)
{
	int		i;
	int		side;

	side = choose_tex(&data->ray);
	i = -1;
	while (++i < start)
		pixel_put(data, i, data->color.sky_color / (float)(i + 150));
	i -= 1;
	while (++i <= stop && i < PROJ_PLANE_H)
		pixel_put_tex(data, i, side);
	i -= 1;
	while (++i < PROJ_PLANE_H)
		pixel_put_floor(data, i, side, PROJ_PLANE_H / (2.0 * i - PROJ_PLANE_H));
}
