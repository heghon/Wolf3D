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

# define A 0
# define D 2
# define E 14
# define Q 12
# define S 1
# define W 13
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

# define WIN_L 1280
# define WIN_H 800
# define X 0
# define Y 1

# define FOV 66
# define PROJ_PLANE_L WIN_L
# define PROJ_PLANE_H (WIN_H)
# define PLANE_DIST ((WIN_L / 2) * tan((FOV / 2)* 0.017453292519943))
# define GRID_S 256
# define WALL_H 256
# define PLAYER_H 128
# define SIZEX2 (WALL_H * 2)
# define SIZEX4 (WALL_H * 4)
# define HB 0.03

# define BROWN 0x825C26
# define DARK_RED 0xAA0000
# define RED 0xFF0000
# define ORANGE 0xFF8C00
# define YELLOW 0xFFDD00
# define LIGHT_YELLOW 0xFFFF00
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define PURPLE_ASSEMBLY 0x9359AF

# define FILE1 "pics/brick.xpm"
# define FILE2 "pics/purplestone.xpm"
# define FILE3 "pics/eagle.xpm"
# define FILE4 "pics/wood.xpm"
# define TEX_S 64
# define SKY_S 894
#endif
