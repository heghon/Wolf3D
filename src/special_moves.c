/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:54:38 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/05 15:12:07 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	jump_handler(t_data *data)
{
	if (data->player.z >= 100)
		data->player.jump_state = 1;
	data->player.z += (data->player.jump_state ? -10 : 10);
	if (data->player.jump_state && data->player.z == 0)
	{
		data->player.jump_state = 0;
		data->player.up_move = 0;
	}
}

void	crouch_handler(t_data *data)
{
	if (data->player.z <= -50)
		data->player.crouch_state = 1;
	data->player.z += (data->player.crouch_state ? -5 : 5);
	if (data->player.crouch_state && data->player.z == 0)
	{
		data->player.crouch_state = 0;
		data->player.down_move = 0;
	}
}
