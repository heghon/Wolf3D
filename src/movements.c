/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 13:27:10 by bmenant           #+#    #+#             */
/*   Updated: 2019/08/03 13:41:42 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include "../inc/wolf3d_define.h"
#include "../inc/wolf3d_struct.h"
#include <math.h>

static void	up_and_down(t_data *data, t_player *player, int key)
{
	if (key == ARROW_UP)
	{
		if (data->map.map[(int)(player->pos[X] + player->dir[X] *
					player->move_speed)][(int)(player->pos[Y])] == 0)
			player->pos[X] += player->dir[X] * player->move_speed;
		if (data->map.map[(int)player->pos[X]][(int)(player->pos[Y] +
					player->dir[Y] * player->move_speed)] == 0)
			player->pos[Y] += player->dir[Y] * player->move_speed;
	}
	if (key == ARROW_DOWN)
	{
		if (data->map.map[(int)(player->pos[X] - player->dir[X] *
					player->move_speed)][(int)player->pos[Y]] == 0)
			player->pos[X] -= player->dir[X] * player->move_speed;
		if (data->map.map[(int)player->pos[X]][(int)(player->pos[Y] -
					player->dir[Y] * player->move_speed)] == 0)
			player->pos[Y] -= player->dir[Y] * player->move_speed;
	}
}

static void	turn(t_player *player, int key)
{
	float	rs;
	float	nrs;
	float	old_dirx;
	float	old_planex;

	old_dirx = player->dir[X];
	old_planex = player->plane[X];
	if (key == ARROW_LEFT)
	{
		nrs = player->rot_speed * -1;
		player->dir[X] = player->dir[X] * cos(nrs) - player->dir[Y] * sin(nrs);
		player->dir[Y] = old_dirx * sin(nrs) + player->dir[Y] * cos(nrs);
		player->plane[X] = player->plane[X] * cos(nrs) -
			player->plane[Y] * sin(nrs);
		player->plane[Y] = old_planex * sin(nrs) + player->plane[Y] * cos(nrs);
	}
	if (key == ARROW_RIGHT)
	{
		rs = player->rot_speed;
		player->dir[X] = player->dir[X] * cos(rs) - player->dir[Y] * sin(rs);
		player->dir[Y] = old_dirx * sin(rs) + player->dir[Y] * cos(rs);
		player->plane[X] = player->plane[X] * cos(rs) -
			player->plane[Y] * sin(rs);
		player->plane[Y] = old_planex * sin(rs) + player->plane[Y] * cos(rs);
	}
}

void		movements(t_data *data, t_player *player, int key)
{
	if (key == ARROW_UP || key == ARROW_DOWN)
		up_and_down(data, player, key);
	if (key == ARROW_LEFT || key == ARROW_RIGHT)
		turn(player, key);
}
