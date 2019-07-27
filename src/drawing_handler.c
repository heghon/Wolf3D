/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:03:36 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/27 10:08:12 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void				pixel_put(t_data *data, int size, int i, unsigned int c)
{
	int	x;

	x = (size * 4) + (i * data->mlx.s_line);
	data->mlx.pic[x] = c;
	data->mlx.pic[x + 1] = c >> 8;
	data->mlx.pic[x + 2] = c >> 16;
}

static unsigned int	find_color(t_ray *ray, t_color *color)
{
	if (ray->hit_side == 1)
	{
		if ((ray->step[X] == -1 && ray->step[Y] == -1) || (ray->step[X] == 1 &&
				ray->step[Y] == -1))
			return (color->first_color);
		if ((ray->step[X] == -1 && ray->step[Y] == 1) || (ray->step[X] == 1 &&
				ray->step[Y] == 1))
			return (color->second_color);
	}
	if ((ray->step[X] == -1 && ray->step[Y] == -1) || (ray->step[X] == -1 &&
				ray->step[Y] == 1))
		return (color->third_color);
	return (color->fourth_color);
}

void				drawing_handler(int size, int start, int stop, t_data *data)
{
	unsigned int	color;
	int				i;

	color = find_color(&data->ray, &data->color);
	i = -1;
	while (++i < start + data->player.z)
		pixel_put(data, size, i, data->color.sky_color);
	i -= 1;
	while(++i <= stop + data->player.z && i < PROJ_PLANE_H)
		pixel_put(data, size, i, color);
	i -= 1;
	while (++i < PROJ_PLANE_H)
		pixel_put(data, size, i, data->color.ground_color);
}
