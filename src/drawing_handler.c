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

	x = (i * data->mlx.s_line) + (data->ray.nbr * 4);
	//x = ((i * WIN_L) + data->ray.nbr) * 4;
	//printf("%d\n", x);
	data->mlx.pic[x] = c + i;
	data->mlx.pic[x + 1] = (c >> 8) + i;
	data->mlx.pic[x + 2] = (c >> 16) + i;
	//printf("5\n");
	//*/
	
	//size = size;
	//mlx_pixel_put(data->mlx.ptr, data->mlx.win, data->ray.nbr, i, c);
}


static unsigned int	find_color(t_player *player, t_ray *ray, t_color *color)
{
	if (ray->dir[X] > 0 && ray->side_hit == 0)
		return (color->first_color);
	else if (ray->dir[X] <= 0 && ray->side_hit == 0)
		return (color->second_color);
	if (ray->dir[Y] > 0 && ray->side_hit == 1)
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
		pixel_put(data, size, i, find_color(&data->player, &data->ray, &data->color));
	i -= 1;
	//printf("sola %d\n",i);
	while (++i < PROJ_PLANE_H)
		pixel_put(data, size, i, data->color.ground_color);
}
