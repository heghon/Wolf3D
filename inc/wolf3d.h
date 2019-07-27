/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:51:41 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/25 13:57:50 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

int		key_handler(int key, void *param);
void	init(t_data *data);
void	function_problem(int mode);
void	map_handler(t_map *map, char *str);
void	launch_rays(t_data *data);
int		loop_handler(t_data *data);
void	drawing_handler(int size, int start, int stop, t_data *data);
void	pixel_put(t_data *data, int size, int i, unsigned int c);
void	forward_move(t_data *data);
void	backward_move(t_data *data);
void	right_move(t_data *data);
void	left_move(t_data *data);
void	jump_handler(t_data *data);
void	crouch_handler(t_data *data);

#endif
