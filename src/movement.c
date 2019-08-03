/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseneca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:26:27 by sseneca           #+#    #+#             */
/*   Updated: 2019/07/30 16:26:29 by sseneca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/wolf3d.h"
#include "../inc/wolf3d_define.h"
#include <math.h>

void       movement_check(t_player *player)
{
    player->angle = player->angle == -1 ? 359 : player->angle;
    player->angle = player->angle == 360 ? 0 : player->angle; 
}

void       movement(t_data *data, t_player *player, int key)
{
    if (key == ARROW_LEFT)
        player->angle += 1;
    else if (KEY == ARROW_RIGHT)
        player->angle -= 1;
    else if (key == ARROW_UP)
    {
        player->pos[X] += cos(ft_arc_to_rad(angle)) * player->move_speed;
        player->pos[Y] += sin(ft_arc_to_rad(angle)) * player->move_speed;
    }
    else if (key == ARROW_DOWN)
    {
        player->pos[X] -= cos(ft_arc_to_rad(angle)) * player->move_speed;
        player->pos[Y] -= sin(ft_arc_to_rad(angle)) * player->move_speed;
    }
    movement_check(player);
}
