/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:22:07 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/25 15:45:29 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCT_H
# define WOLF3D_STRUCT_H

# include <time.h>

typedef struct		camera
{
	float			pos[2];
}					t_camera;

typedef struct		s_tables
{
	float			sin[361];
	float			isin[361];
	float			cos[361];
	float			icos[361];
	float			tan[361];
	float			itan[361];
}					t_tables;

typedef struct		s_color
{
	unsigned int	first_color;
	unsigned int	second_color;
	unsigned int	third_color;
	unsigned int	fourth_color;
	unsigned int	sky_color;
	unsigned int	ground_color;
}					t_color;

typedef	struct		s_player
{
	float			pos[2];
	float			dir[2];
	float			plane[2];
	/*
	float			angle;
	int				pos[2];
	float			dir[2];
	float			plane[2];
	int				turn_speed;
	int				move_speed;
	int				jump_state;
	int				crouch_state;
	int				left_move;
	int				right_move;
	int				forward_move;
	int				backward_move;
	int				up_move;
	int				down_move;
	int				z;
	int				fov;
	int				x;
	int				y;
	*/
}					t_player;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*pic;
	int				bpp;
	int				s_line;
	int				endian;
//	clock_t			last_img;
//	clock_t			next_img;
}					t_mlx;

typedef struct		s_ray
{
	float			dir[2];
	int				map[2];
	float			first_dist[2];
	float			delta[2];
	float			final_dist;
	int				step[2];
	int				hit;
	int				side_hit;
	/*
	int			dist;//
	float			cam;
	int				hit;
	int				hit_side;
	int				map[2];
	int				step[2];
	float			dir[2];
	float			side[2];
	float			delta[2];
	float			pos[2];
	int				nbr;
	float			angle_inc;
	int				xa;
	int				ya;
	*/
}					t_ray;

typedef struct		s_map
{
	int				**map;
	int				width;
	int				height;
}					t_map;

typedef struct		s_data
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_ray			ray;
//	t_tables		tables;
	t_color			color;
//	int				start_x;
//	int				start_y;
}					t_data;

#endif
