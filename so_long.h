#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "./includes/ft_printf/ft_printf.h"
#include "./includes/get_next_line/get_next_line_bonus.h"
#include "./includes/libft/libft.h"

#define PLAYER_RIGHT "assets/sprites/player_right.xpm"
#define PLAYER_FRONT "assets/sprites/player_front.xpm"
#define PLAYER_LEFT "assets/sprites/player_left.xpm"
#define PLAYER_BACK "assets/sprites/player_back.xpm"
#define ENEMY "assets/sprites/enemy.xpm"
#define GEO_XPM "assets/sprites/coin.xpm"
#define EXIT_OPEN "assets/sprites/exit_open.xpm"
#define EXIT_CLOSE "assets/sprites/exit_close.xpm"	
#define WALL_XPM "assets/sprites/wall.xpm"
#define FLOOR_XPM "assets/sprites/floor.xpm"

#define WALL '1'
#define FLOOR '0'
#define GEO 'C'
#define EXIT 'E'
#define PLAYER 'P'

#define RIGHT 214
#define LEFT 213
#define FRONT 212
#define BACK 211

#define IMG_WIDTH 32
#define IMG_HEIGHT 32
#define W 13
#define A 0
#define S 1
#define D 2
#define ESC 53

#endif
