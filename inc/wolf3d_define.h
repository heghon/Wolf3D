/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:20:50 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/11 12:18:00 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINE_H
# define WOLF3D_DEFINE_H

# include <math.h>

# define A 0
# define B 11
# define C 8
# define D 2
# define E 14
# define F 3
# define G 5
# define H 4
# define I 34
# define J 38
# define K 40
# define L 37
# define M 46
# define N 45
# define O 31
# define P 35
# define Q 12
# define R 15
# define S 1
# define T 17
# define U 32
# define V 9
# define W 13
# define Z 6
# define ESC 53
# define TAB 48
# define RETURN 36
# define L_SHIFT 257
# define R_SHIFT 258
# define SPACE 49
# define ARROW_UP 126
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define MOUSE_UP 5
# define MOUSE_DOWN 4
# define PAGE_UP 116
# define PAGE_DOWN 121
# define PLUS 69
# define MINUS 78
# define CLR 71

# define WIN_L 320
# define WIN_H 200
# define X 0
# define Y 1

# define FOV 66
# define PROJ_PLANE_L WIN_L
# define PROJ_PLANE_H (WIN_H)
# define PLANE_DIST ((WIN_L / 2) * tan((FOV / 2)* 0.017453292519943))
# define GRID_S 256
# define WALL_H 256
# define PLAYER_H 128

# define ANGLE0 0
# define ANGLE5 107
# define ANGLE10 213
# define ANGLE15 320
# define ANGLE30 640
# define ANGLE60 1280
# define ANGLE90 1920
# define ANGLE180 3840
# define ANGLE270 5760
# define ANGLE360 7680

# define THREAD_NUMBER 10

# define BROWN 0x825C26
# define DARK_RED 0xAA0000
# define RED 0xFF0000
# define ORANGE 0xFF8C00
# define YELLOW 0xFFDD00
# define LIGHT_YELLOW 0xFFFF00
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define PURPLE_ASSEMBLY 0x9359AF

#endif
