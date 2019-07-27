/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:29:44 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/10 17:59:33 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/wolf3d.h"

void	forward_move(t_data *data)
{
	if (data->map.map[(int)(data->player.pos[X] + data->player.dir[X] *
			data->player.move_speed)][(int)(data->player.pos[Y])] == 0)
		data->player.pos[X] += data->player.dir[X] * data->player.move_speed;
	if (data->map.map[(int)(data->player.pos[X])][(int)(data->player.pos[Y] +
			data->player.dir[Y] * data->player.move_speed)] == 0)
		data->player.pos[Y] += data->player.dir[Y] * data->player.move_speed;
}

void	backward_move(t_data *data)
{
	if (data->map.map[(int)(data->player.pos[X] + data->player.dir[X] *
			data->player.move_speed)][(int)(data->player.pos[Y])] == 0)
		data->player.pos[X] -= data->player.dir[X] * data->player.move_speed;
	if (data->map.map[(int)(data->player.pos[X])][(int)(data->player.pos[Y] +
			data->player.dir[Y] * data->player.move_speed)] == 0)
		data->player.pos[Y] -= data->player.dir[Y] * data->player.move_speed;
}

void	right_move(t_data *data)
{
	float	tmp;
	float	speed;

	tmp = data->player.dir[X];
	speed = data->player.turn_speed;
	data->player.dir[X] = data->player.dir[X] * cos(-speed) -
		data->player.dir[Y] * sin(-speed);
	data->player.dir[Y] = tmp * sin(-speed) + data->player.dir[Y] *
		cos(-speed);
	tmp = data->player.plane[X];
	data->player.plane[X] = data->player.plane[X] * cos(-speed) -
		data->player.plane[Y] * sin(-speed);
	data->player.plane[Y] = tmp * sin(-speed) - data->player.plane[Y] *
		cos(-speed);
}

void	left_move(t_data *data)
{
	float	tmp;
	float	speed;

	tmp = data->player.dir[X];
	speed = data->player.turn_speed;
	data->player.dir[X] = data->player.dir[X] * cos(speed) -
		data->player.dir[Y] * sin(speed);
	data->player.dir[Y] = tmp * sin(speed) + data->player.dir[Y] *
		cos(speed);
	tmp = data->player.plane[X];
	data->player.plane[X] = data->player.plane[X] * cos(speed) -
		data->player.plane[Y] * sin(speed);
	data->player.plane[Y] = tmp * sin(speed) - data->player.plane[Y] *
		cos(speed);
}
