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
//#define ENEMY "assets/sprites/enemy.xpm"
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

typedef struct s_map {
	char	**map;
	int		rows;
	int		columns;
	int		coins;
	int		exit;
	int		players;
	int		plyr_x;
	int		plyr_y;
}	t_map;

typedef struct s_image {
	void	*img_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win_ptr;
	int			movements;
	int			plyr_facing;
	t_map		map_data;
	bool		mloc;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		exit_open;
	t_image		exit_close;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

void	ft_free_map(t_game *game);
void	ft_error(t_game *game, char *msg);
void	ft_check_map_input(t_game *game, char *map_str);
void	ft_read_map(t_game *game, char *map_filename);
void	ft_init_vars(t_game *game);
void	ft_init_sprite(t_game *game);
t_image	ft_new_sprite(t_game *game, void *mlx, char *path);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_print_movements(t_game *game);
int		ft_render_map(t_game *game);
void	ft_render_sprite(t_game *game, t_image img, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_move_player(t_game *game, int go_x, int go_y, int facing);
int		ft_close_game(t_game *game);
int		ft_handle_input(int key, t_game *game);
void	ft_win_game(t_game *game);
void	ft_check_rows(t_game *game);
void	ft_check_cols(t_game *game);
void	ft_count_objectives(t_game *game);
void	ft_check_objectives(t_game *game);
void	ft_check_exitable(char **map_temp, int x, int y, bool *exitable);
void	ft_free_map_temp(char **map_temp, int i);
void	ft_check_playable(t_game *game);
void	ft_check_map(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_everything(t_game *game);
int		ft_close_game(t_game *game);
void	ft_win_game(t_game *game);

#endif
