/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:57:26 by bmenant           #+#    #+#             */
/*   Updated: 2019/08/04 12:57:40 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"
#include "../inc/wolf3d_define.h"
#include "../inc/wolf3d_struct.h"
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>

void        teleportation(t_data *data, t_player *player, int **map)
{
    int x;
    int y;

    x = (int)player->pos[X] - 1;
    while (++x < data->map.height)
    {
        y = (x == (int)player->pos[X] ? player->pos[Y] : -1);
        while (++y < data->map.width)
        {
            if (x == (int)player->pos[X] && y == (int)player->pos[Y])
                y += 1;
            if (map[x][y] == 3)
            {
                player->pos[X] = x + 0.5;
                player->pos[Y] = y + 0.5;
                player->tp = 1;
                return ;
            }
        }
    }
    init(data);
    teleportation(data, player, map);
    return ;
}