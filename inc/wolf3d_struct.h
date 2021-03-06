/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:22:07 by bmenant           #+#    #+#             */
/*   Updated: 2019/08/29 20:57:25 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCT_H
# define WOLF3D_STRUCT_H

typedef struct		s_color
{
	unsigned int	sky_color;
	unsigned int	ground_color;
}					t_color;

typedef	struct		s_player
{
	float			pos[2];
	float			dir[2];
	float			plane[2];
	float			rot_speed;
	float			move_speed;
	int				sprint;
	int				tp;
}					t_player;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*pic;
	void			*tex[5];
	char			*texpic[5];
	int				bpp;
	int				s_line;
	int				endian;
}					t_mlx;

typedef struct		s_ray
{
	float			camx;
	float			dir[2];
	int				map[2];
	float			first_dist[2];
	float			delta[2];
	float			final_dist;
	int				step[2];
	int				hit;
	int				side_hit;
	int				size;
	int				nbr;
	float			wall_x;
	int				tex[2];
}					t_ray;

typedef struct		s_map
{
	int				**map;
	int				width;
	int				height;
	int				t_counter;
}					t_map;

typedef struct		s_data
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_ray			ray;
	t_color			color;
}					t_data;

#endif
