/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:03:36 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/27 15:19:23 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include "../inc/wolf3d_define.h"
#include "../libft/libft.h"
#include <mlx.h>

#include <stdio.h>

void				pixel_put(t_data *data, int size, int i, unsigned int c)
{
	//*
	int	x;

	//x = (i * data->mlx.s_line) + data->ray.nbr * 4;
	x = ((i * WIN_L) + data->ray.nbr) * 4;
	//printf("%d\n", x);
	data->mlx.pic[x] = c;
	data->mlx.pic[x + 1] = c >> 8;
	data->mlx.pic[x + 2] = c >> 16;
	//printf("5\n");
	//*/
	
	//size = size;
	//mlx_pixel_put(data->mlx.ptr, data->mlx.win, data->ray.nbr, i, c);
}

static unsigned int	find_color(t_player *player, t_ray *ray, t_color *color)
{
	int	angle;

	angle = player->angle + (player->fov / 2) - (ray->nbr * ray->angle_inc);
	if (angle >= 0 && angle <= 180 && ray->hit == 'h')
		return (color->first_color);
	if (angle >= 180 && angle <= 360 && ray->hit == 'h')
		return (color->second_color);
	if (angle >= 270 && angle <= 90 && ray->hit == 'v')
		return (color->third_color);
	//if (angle >= 90 && angle <= 270 && ray->hit == 'v')
	return (color->fourth_color);

}

void				drawing_handler(int size, int start, int stop, t_data *data)
{
	int				i;

	i = -1;
	//printf("size = %d\n", size);
	//printf("ciel\n");
	while (++i < start)
		pixel_put(data, size, i, data->color.sky_color);
	i -= 1;
	//printf("mur a %d\n", i);
	while(++i <= stop && i < PROJ_PLANE_H)
		pixel_put(data, size, i, YELLOW/*find_color(&data->player, &data->ray, &data->color)*/);
	i -= 1;
	//printf("sola %d\n",i);
	while (++i < PROJ_PLANE_H)
		pixel_put(data, size, i, data->color.ground_color);
}
