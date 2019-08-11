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

# define KEY_A 0
# define KEY_D 2
# define KEY_E 14
# define KEY_Q 12
# define KEY_S 1
# define KEY_W 13
# define ESC 53
# define L_SHIFT 257
# define SPACE 49
# define ARROW_UP 126
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125

# define WIN_L 1280
# define WIN_H 800
# define X 0
# define Y 1

# define FOV 66
# define PROJ_PLANE_L WIN_L
# define PROJ_PLANE_H WIN_H
# define WALL_H 256
# define SIZEX2 (WALL_H * 2)
# define SIZEX4 (WALL_H * 4)
# define HB 0.03
# define MAX_S (WIN_H / 2)

# define BROWN 0x825C26
# define DARK_RED 0xAA0000
# define RED 0xFF0000
# define ORANGE 0xFF8C00
# define YELLOW 0xFFDD00
# define LIGHT_YELLOW 0xFFFF00
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define PURPLE_ASSEMBLY 0x9359AF
# define BLUE_CYAN 0x0088FF

# define FILE1 "pics/brick.xpm"
# define FILE2 "pics/purplestone.xpm"
# define FILE3 "pics/eagle.xpm"
# define FILE4 "pics/wood.xpm"
# define FILE5 "pics/stone.xpm"
# define TEX_S 64
# define TEX_L (TEX_S * TEX_S * 4 - 4)
#endif
