/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:09:48 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/27 15:07:32 by bmenant          ###   ########.fr       */
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

static void	init_ray()
{

}	

void		lanch_rays(t_data *data)
{
	int	i;

	i = -1;
	while (++i < WIN_L)
	{
		
	}
}