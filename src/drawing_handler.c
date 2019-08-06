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
#include "../inc/wolf3d_define.h"
#include "../libft/libft.h"
#include <mlx.h>

#include <stdio.h>

void				pixel_put(t_data *data, int i, unsigned int c)
{
	int		x;

	x = (i * data->mlx.s_line) + (data->ray.nbr * 4);
	data->mlx.pic[x] = c;
	data->mlx.pic[x + 1] = (c >> 8);
	data->mlx.pic[x + 2] = (c >> 16);
}

static void			pixel_put_two(t_data *data, int i, unsigned int c)
{
	int		x;

	x = (i * data->mlx.s_line) + (data->ray.nbr * 4);
	data->mlx.pic[x] = c;
	data->mlx.pic[x + 1] = (c >> 8);
	data->mlx.pic[x + 2] = (float)(c >> 16) / (float)(PROJ_PLANE_H /
		(WIN_H / 4) - ((float)(i - (WIN_H / 4 * 3)) / (WIN_H / 8)));
}

static void			pixel_put_tex(t_data *data, int size, int i, unsigned int t)
{
	int d;
	int	x;

	if (size)
		;
	x = (i * data->mlx.s_line) + (data->ray.nbr * 4);
	d = i * SIZEX4 - PROJ_PLANE_H * SIZEX2 + data->ray.size * SIZEX2;
	data->ray.tex[Y] = ((d * TEX_S) / data->ray.size) / SIZEX4;
	d = data->ray.tex[Y] * TEX_S + data->ray.tex[X];
	d *= 4;
	data->mlx.pic[x] = data->mlx.texpic[t][d];
	data->mlx.pic[x + 1] = data->mlx.texpic[t][d + 1];
	data->mlx.pic[x + 2] = data->mlx.texpic[t][d + 2];
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

void				drawing_handler(int start, int stop, t_data *data)
{
	int		i;

	i = -1;
	while (++i < start)
		pixel_put(data, i, data->color.sky_color / (float)(i + 150));
	i -= 1;
	while (++i <= stop && i < PROJ_PLANE_H)
		pixel_put_tex(data, stop - start, i, choose_tex(&data->ray));
	i -= 1;
	while (++i < PROJ_PLANE_H)
		pixel_put_two(data, i, data->color.ground_color);
}
