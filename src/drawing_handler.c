/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:03:36 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/27 11:33:30 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include "../inc/wolf3d_struct.h"
#include "../inc/wolf3d_define.h"
#include "../libft/libft.h"


void				pixel_put(t_data *data, int size, int i, unsigned int c)
{
	int	x;

	x = (size * 4) + (i * data->mlx.s_line);
	data->mlx.pic[x] = c;
	data->mlx.pic[x + 1] = c >> 8;
	data->mlx.pic[x + 2] = c >> 16;
}

static unsigned int	find_color(t_player *player, t_ray *ray, t_color *color)
{
	int	angle;

	angle = player.angle + (player.fov / 2) - (ray.nbr * ray.angle_inc);
	if (angle >= 0 && angle <= 180 && ray->hit == 'h')
		return (color->first_color);
	if (angle >= 180 && angle <= 360 && ray->hit == 'h')
		return (color->second_color);
	if (angle >= 270 && angle <= 90 && ray->hit == 'v')
		return (color->third_color);
	if (angle >= 90 && angle <= 270 && ray->hit == 'v')
		return (color->fourth_color);
}

void				drawing_handler(int size, int start, int stop, t_data *data)
{
	int				i;

	i = -1;
	while (++i < start + data->player.z)
		pixel_put(data, size, i, data->color.sky_color);
	i -= 1;
	while(++i <= stop + data->player.z && i < PROJ_PLANE_H)
		pixel_put(data, size, i,
				find_color(&data->player, &data->ray, &data->color));
	i -= 1;
	while (++i < PROJ_PLANE_H)
		pixel_put(data, size, i, data->color.ground_color);
}
