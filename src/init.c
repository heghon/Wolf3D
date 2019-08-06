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
#include "../inc/wolf3d_define.h"
#include "../libft/libft.h"
#include <math.h>
#include <time.h>
#include <mlx.h>

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
	function_problem(2);
	return (0);
}

static void	init_mlx(t_mlx *mlx)
{
	int i;

	i = 0;
	mlx->ptr = mlx_init();
	mlx->bpp = 0;
	mlx->s_line = 0;
	mlx->tex[0] = mlx_xpm_file_to_image(mlx->ptr, FILE1, &i, &i);
	mlx->texpic[0] = mlx_get_data_addr(mlx->tex[0], &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
	mlx->tex[1] = mlx_xpm_file_to_image(mlx->ptr, FILE2, &i, &i);
	mlx->texpic[1] = mlx_get_data_addr(mlx->tex[1], &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
	mlx->tex[2] = mlx_xpm_file_to_image(mlx->ptr, FILE3, &i, &i);
	mlx->texpic[2] = mlx_get_data_addr(mlx->tex[2], &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
	mlx->tex[3] = mlx_xpm_file_to_image(mlx->ptr, FILE4, &i, &i);
	mlx->texpic[3] = mlx_get_data_addr(mlx->tex[3], &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
	mlx->img = mlx_new_image(mlx->ptr, PROJ_PLANE_L, PROJ_PLANE_H);
	mlx->pic = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
}

static void	init_player(t_player *player)
{
	player->dir[X] = 1.0;
	player->dir[Y] = 0.0;
	player->plane[X] = 0;
	player->plane[Y] = 0.66;
	player->move_speed = 0.1;
	player->rot_speed = 0.05;
	player->sprint = 1;
	player->tp = 0;
}

void		init(t_data *data)
{
	init_player(&data->player);
	init_position(&data->map, &data->player);
	init_mlx(&data->mlx);
	data->color.first_color = DARK_RED;
	data->color.second_color = RED;
	data->color.third_color = ORANGE;
	data->color.fourth_color = YELLOW;
	data->color.sky_color = 0x0088FF;
	data->color.ground_color = 0xFF0000;
}
