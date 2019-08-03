/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:51:41 by bmenant           #+#    #+#             */
/*   Updated: 2019/08/03 13:58:32 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "wolf3d_struct.h"

int		key_handler(int key, t_data *data);
void	init(t_data *data);
void	function_problem(int mode);
void	map_handler(t_map *map, char *str);
void	launch_rays(t_data *data);
int		loop_handler(t_data *data);
void	drawing_handler(int start, int stop, t_data *data);
void	pixel_put(t_data *data, int i, unsigned int c);
void	movements(t_data *data, t_player *player, int key);

#endif
