/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:04:17 by bmenant           #+#    #+#             */
/*   Updated: 2019/08/03 13:40:05 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include <mlx.h>
#include <stdlib.h>

static int	init_position(t_map *map, t_player *player)
{
	int i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == 0)
			{
				player->pos[X] = j + 0.5;
				player->pos[Y] = i + 0.5;
				return (0);
			}
		}
	}
	free_map(map->map, map->height);
	function_problem(2);
	return (0);
}

static void	init_img(t_mlx *mlx)
{
	mlx->bpp = 0;
	mlx->s_line = 0;
	mlx->img = mlx_new_image(mlx->ptr, PROJ_PLANE_L, PROJ_PLANE_H);
	mlx->pic = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
}

static void	init_tex(t_mlx *mlx)
{
	int i;

	i = 0;
	if ((mlx->tex[0] = mlx_xpm_file_to_image(mlx->ptr, FILE1, &i, &i)) == NULL)
		function_problem(3);
	mlx->texpic[0] = mlx_get_data_addr(mlx->tex[0], &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
	if ((mlx->tex[1] = mlx_xpm_file_to_image(mlx->ptr, FILE2, &i, &i)) == NULL)
		function_problem(3);
	mlx->texpic[1] = mlx_get_data_addr(mlx->tex[1], &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
	if ((mlx->tex[2] = mlx_xpm_file_to_image(mlx->ptr, FILE3, &i, &i)) == NULL)
		function_problem(3);
	mlx->texpic[2] = mlx_get_data_addr(mlx->tex[2], &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
	if ((mlx->tex[3] = mlx_xpm_file_to_image(mlx->ptr, FILE4, &i, &i)) == NULL)
		function_problem(3);
	mlx->texpic[3] = mlx_get_data_addr(mlx->tex[3], &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
	if ((mlx->tex[4] = mlx_xpm_file_to_image(mlx->ptr, FILE5, &i, &i)) == NULL)
		function_problem(4);
	mlx->texpic[4] = mlx_get_data_addr(mlx->tex[4], &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
}

static void	init_player(t_player *player)
{
	player->dir[X] = 1.0;
	player->dir[Y] = 0.0;
	player->plane[X] = 0;
	player->plane[Y] = (FOV / 100.0);
	player->move_speed = 0.1;
	player->rot_speed = 0.05;
	player->sprint = 1;
	player->tp = 0;
}

void		init(t_data *data)
{
	init_player(&data->player);
	init_position(&data->map, &data->player);
	data->mlx.ptr = mlx_init();
	init_tex(&data->mlx);
	init_img(&data->mlx);
	data->color.sky_color = BLUE_CYAN;
	data->color.ground_color = RED;
}
