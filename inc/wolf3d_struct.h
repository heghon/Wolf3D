/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:22:07 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/30 16:33:40 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCT_H
# define WOLF3D_STRUCT_H

# include <time.h>

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
	float			angle;
	int				pos[2];
	float			turn_speed;
	float			move_speed;
	int				jump_state;
	int				crouch_state;
	int				left_move;
	int				right_move;
	int				forward_move;
	int				backward_move;
	int				up_move;
	int				down_move;
	int				z;
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
	clock_t			last_img;
	clock_t			next_img;
}					t_mlx;

typedef struct		s_ray
{
	float			dist;
	int				hit;
	char			side;
	int				nbr;
	float			angle_inc;
	float			x[2];
	float			y[2];
	int				h[2];
	int				v[2];

}					t_ray;

typedef struct		s_map
{
	int				**map;
	int				width;
	int				height;
}					t_map;

typedef struct		s_data
{	
	int				width;
	int				height;
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_ray			ray;
	t_color			color;
	int				start_x;
	int				start_y;
}					t_data;

#endif
