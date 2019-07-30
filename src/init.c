/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:04:17 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/25 15:09:52 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include "../inc/wolf3d_define.h"
#include "../libft/libft.h"
#include <math.h>
#include <time.h>
#include <mlx.h>

static void	init_tables(t_tables *tables)
{
	int		i;
	float	rad;

	i = -1;
	while (++i < 361)
	{
		rad = ft_arc_to_rad((float)i) + (float)0.0001;
		tables->sin[i] = (float)sin(rad);
		tables->isin[i] = (1.0F / tables->sin[i]);
		tables->cos[i] = (float)cos(rad);
		tables->icos[i] = (1.0F / tables->cos[i]);
		tables->tan[i] = (float)tan(rad);
		tables->itan[i] = (1.0F / tables->tan[i]);
	}
}

static void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->bpp = 0;
	mlx->s_line = 0;
	mlx->img = mlx_new_image(mlx->ptr, PROJ_PLANE_L, PROJ_PLANE_H);
	mlx->pic = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->s_line),
			&(mlx->endian));
	mlx->last_img = clock();
	mlx->next_img = 0;
}

static void	init_player(t_player *player)
{
	player->angle = 0;
	player->pos[X] = 5 * 256;//1792;//384;//32767;//32767;
	player->pos[Y] = 5 * 256;//384;//640;//1;//1;
	player->dir[X] = -1;
	player->dir[Y] = 0;
	player->z = PLAYER_H;
	player->plane[X] = 0;
	player->plane[Y] = 0.66;
	player->turn_speed = 0.1;
	player->move_speed = 0.05;
	player->left_move = 0;
	player->right_move = 0;
	player->forward_move = 0;
	player->backward_move = 0;
	player->up_move = 0;
	player->down_move = 0;
	player->jump_state = 0;
	player->crouch_state = 0;
	player->fov = 60;
}

void		init(t_data *data)
{
	init_player(&data->player);
	init_mlx(&data->mlx);
	data->width = WIN_L;
	data->height = WIN_H;
	data->color.first_color = DARK_RED;
	data->color.second_color = RED;
	data->color.third_color = ORANGE;
	data->color.fourth_color = YELLOW;
	data->color.sky_color = 0x0088FF;
	data->color.ground_color = 0xFF8800;
}
