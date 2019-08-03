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
	int		start;
	int		stop;

	start = PROJ_PLANE_H / 2 - data->ray.size / 2;
	start = (start < 0 ? 0 : start);
	stop = data->ray.size / 2 + PROJ_PLANE_H / 2;
	stop = (stop >= PROJ_PLANE_H ? PROJ_PLANE_H - 1 : stop);
	drawing_handler(data->ray.size, start, stop, data);
}

static void	init_ray(t_ray *ray, t_camera *cam, t_player *player)
{
	//printf("\ndebut init\n");
	cam->pos[X] = 2 * ray->nbr / (float)WIN_L - 1;
	ray->dir[X] = player->dir[X] + player->plane[X] * cam->pos[X];
	ray->dir[Y] = player->dir[Y] + player->plane[Y] * cam->pos[X];
	ray->map[X] = (int)player->pos[X];
	ray->map[Y] = (int)player->pos[Y];
	ray->delta[X] = fabs(1 / ray->dir[X]);
	ray->delta[Y] = fabs(1 / ray->dir[Y]);
	ray->hit = 0;
	ray->step[X] = (ray->dir[X] < 0 ? -1 : 1);
	ray->step[Y] = (ray->dir[Y] < 0 ? -1 : 1);
	ray->first_dist[X] = (ray->dir[X] < 0 ? (player->pos[X] - ray->map[X]) * ray->delta[X] : (ray->map[X] + 1.0 - player->pos[X]) * ray->delta[X]);
	ray->first_dist[Y] = (ray->dir[Y] < 0 ? (player->pos[Y] - ray->map[Y]) * ray->delta[Y] : (ray->map[Y] + 1.0 - player->pos[Y]) * ray->delta[Y]);
	/*printf("fin init : cam->pos[X] = %f\n", cam->pos[X]);
	printf("fin init : ray->dir[X] = %f\n", ray->dir[X]);
	printf("fin init : ray->dir[Y] = %f\n", ray->dir[Y]);
	printf("fin init : ray->map[X] = %d\n", ray->map[X]);
	printf("fin init : ray->map[Y] = %d\n", ray->map[Y]);
	printf("fin init : ray->delta[X] = %f\n", ray->delta[X]);
	printf("fin init : ray->delta[Y] = %f\n", ray->delta[Y]);
	printf("fin init : ray->step[X] = %d\n", ray->step[X]);
	printf("fin init : ray->step[Y] = %d\n", ray->step[Y]);
	printf("fin init : ray->first_dist[X] = %f\n", ray->first_dist[X]);
	printf("fin init : ray->first_dist[Y] = %f\n\n", ray->first_dist[Y]);*/
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
		init_ray(&data->ray, &data->camera, &data->player);
		while (data->ray.hit == 0 && ++j >= 0)
			{
				if (data->ray.first_dist[X] < data->ray.first_dist[Y])
				{
					//printf("passage en x\n");
					data->ray.first_dist[X] += data->ray.delta[X];
					data->ray.map[X] += data->ray.step[X];
					data->ray.side_hit = 0;
				}
				else
				{
					//printf("passage en y\n");	
					data->ray.first_dist[Y] += data->ray.delta[Y];
					data->ray.map[Y] += data->ray.step[Y];
					data->ray.side_hit = 1;
				}
				data->ray.hit = (data->map.map[data->ray.map[X]][data->ray.map[Y]] != 0 ? 1 : 0);
			}
				/*printf("fin boucle : ray->dir[X] = %f\n", data->ray.dir[X]);
				printf("fin boucle : ray->dir[Y] = %f\n", data->ray.dir[Y]);
				printf("fin boucle : ray->map[X] = %d\n", data->ray.map[X]);
				printf("fin boucle : ray->map[Y] = %d\n", data->ray.map[Y]);
				printf("fin boucle : player->pos[X] = %f\n", data->player.pos[X]);
				printf("fin boucle : player->pos[Y] = %f\n", data->player.pos[Y]);
				printf("fin boucle : ray->step[X] = %d\n", data->ray.step[X]);
				printf("fin boucle : ray->step[Y] = %d\n", data->ray.step[Y]);*/
		if (data->ray.side_hit == 0)
		{
			//printf("\nici ");
			data->ray.final_dist = (float)(data->ray.map[X] - data->player.pos[X] + (1 - data->ray.step[X]) / 2) / data->ray.dir[X];
		}
		else
			data->ray.final_dist = (float)(data->ray.map[Y] - data->player.pos[Y] + (1 - data->ray.step[Y]) / 2) / data->ray.dir[Y];
		data->ray.size = (int)(PROJ_PLANE_H / data->ray.final_dist);
		//printf("fin boucle : final_dist = %f et size = %d\n", data->ray.final_dist, data->ray.size);
		draw_the_ray(data);
	}
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
}