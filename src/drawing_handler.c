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
	data->mlx.pic[x + 2] = (float)(c >> 16) / (float)(PROJ_PLANE_H / 200 -
			((float)(i - 600) / 100));
}

static void			pixel_put_double(t_data *data, int i, unsigned int c)
{
	int		x;

	x = (i * data->mlx.s_line) + (data->ray.nbr * 4);
	data->mlx.pic[x] = (float)c;
	data->mlx.pic[x + 1] = (float)(c >> 8);
	data->mlx.pic[x + 2] = (float)(c >> 16);
}

static unsigned int	find_color(t_ray *ray, t_color *color)
{
	if (ray->dir[X] > 0 && ray->side_hit == 0)
		return (color->first_color);
	else if (ray->dir[X] <= 0 && ray->side_hit == 0)
		return (color->second_color);
	if (ray->dir[Y] > 0 && ray->side_hit == 1)
		return (color->third_color);
	else if (ray->dir[Y] <= 0 && ray->side_hit == 1)
		return (color->fourth_color);
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
		pixel_put_double(data, i, find_color(&data->ray, &data->color));
	i -= 1;
	while (++i < PROJ_PLANE_H)
		pixel_put_two(data, i, data->color.ground_color);
}
