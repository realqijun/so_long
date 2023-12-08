#include "so_long.h"

typedef struct s_map {
	char	**map;
	int	rows;
	int	columns;
	int	coins;
	int	exit;
	int	players;
	int	plyr_x;
	int	plyr_y;
}	t_map;

typedef struct s_image {
	void	*img_ptr;
	int 	x;
	int	y;
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
void	ft_error(t_game *game, char *msg)
{
	if (game->mloc == true)
		ft_free_map(game);
	free(game);
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);	
}

void	ft_checkmap(t_game *game, char *str)
{
	int	index;
	
	if (*str == '\n')
		ft_error(game, "map no good");
	if (str[ft_strlen(str) - 1] == '\n')
		ft_error(game, "map newline at end");
	index = 1;
	while (str[index + 1])
	{
		if (str[index] == '\n' && str[index + 1] == '\n')
			ft_error(game, "map double newline");
		index++;
	}
		
}

void	ft_readmap(t_game *game, char *map_file)
{
	int	fd;
	char	*temp;
	char	*buf;	
	
	game->mloc = false;
	if (!ft_strnstr(&map_file[ft_strlen(map_file) - 4], ".ber", 4))
		ft_error(game, "map not brr");
	else
	{
		game->map_data.rows = 0;
		fd = open(map_file, O_RDONLY);
		if (fd == -1)
			ft_error(game, "map not valid");
		temp = ft_strdup("");
		while (true)
		{
			buf = get_next_line(fd);
			if (buf == NULL)
				break ;
			temp = fusion(temp, buf);
			free(buf);
			game->map_data.rows++;
		}
		close(fd);
		ft_checkmap(game, temp);
		game->map_data.map = ft_split(temp, '\n');
		game->mloc = true;
		free(temp);
	} 
}

void	ft_init_vars(t_game *game)
{
	game->map_data.coins = 0;
	game->map_data.exit = 0;
	game->map_data.players = 0;
	game->movements = 0;
	game->map_data.columns = ft_strlen(game->map_data.map[0]) - 1;
	game->plyr_facing = RIGHT;
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game);

void	ft_init_sprite(t_game *game)
{
	game->wall = ft_new_sprite(game->mlx, WALL_XPM, game);
	game->floor = ft_new_sprite(game->mlx, FLOOR_XPM, game);
	game->coins = ft_new_sprite(game->mlx, GEO_XPM, game);
	game->player_front = ft_new_sprite(game->mlx, PLAYER_FRONT, game);
	game->player_left = ft_new_sprite(game->mlx, PLAYER_LEFT, game);
	game->player_right = ft_new_sprite(game->mlx, PLAYER_RIGHT, game);
	game->player_back = ft_new_sprite(game->mlx, PLAYER_BACK, game);
	game->exit_open = ft_new_sprite(game->mlx, EXIT_OPEN, game);
	game->exit_close = ft_new_sprite(game->mlx, EXIT_CLOSE, game);
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	img;
	
	img.img_ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	if (img.img_ptr == NULL)
		ft_error(game, "no img");
	return (img);
}


void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_print_movements(t_game *game);

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_data.rows)
	{
		x = 0;
		while (x < game->map_data.columns)
			ft_identify_sprite(game, x++, y);
		y++;
	}
	ft_print_movements(game);
	return (0);
}

void	ft_render_sprite(t_game *game, t_image img, int x, int y);

void	ft_render_player(t_game *game, int x, int y)
{
	if (game->plyr_facing == LEFT)
		ft_render_sprite(game, game->player_left, x, y);
	else if (game->plyr_facing == RIGHT)
		ft_render_sprite(game, game->player_right, x, y);
	else if (game->plyr_facing == FRONT)
		ft_render_sprite(game, game->player_front, x, y);
	else if (game->plyr_facing == BACK)
		ft_render_sprite(game, game->player_back, x, y);
}	

void	ft_identify_sprite(t_game *game, int x, int y)
{
	char	item;

	item = game->map_data.map[y][x];
	if (item == WALL)
		ft_render_sprite(game, game->wall, x, y);
	else if (item == FLOOR)
		ft_render_sprite(game, game->floor, x, y);
	else if (item == GEO)
		ft_render_sprite(game, game->coins, x, y);
	else if (item == EXIT)
	{
		if (game->map_data.coins == 0)
			ft_render_sprite(game, game->exit_open, x, y);
		else
			ft_render_sprite(game, game->exit_close, x, y);
	}
	else if (item == PLAYER)
		//ft_render_sprite(game, game->player_front, x, y);
		ft_render_player(game, x, y);
}

void	ft_render_sprite(t_game *game, t_image img, int x, int y)
{
	mlx_put_image_to_window (game->mlx, game->win_ptr, \
	img.img_ptr, x * img.x, y * img.y);
}

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx, game->win_ptr, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}

void	ft_move_player(t_game *game, int go_x, int go_y, int facing);
int	ft_close_game(t_game *game);
int	ft_handle_input(int key, t_game *game)
{
	if (key == W)
		ft_move_player(game, game->map_data.plyr_x, game->map_data.plyr_y - 1, FRONT);
	if (key == A)
		ft_move_player(game, game->map_data.plyr_x - 1, game->map_data.plyr_y, LEFT);
	if (key == S)
		ft_move_player(game, game->map_data.plyr_x, game->map_data.plyr_y + 1, BACK);
	if (key == D)
		ft_move_player(game, game->map_data.plyr_x + 1, game->map_data.plyr_y, RIGHT);
	if (key == ESC)
		ft_close_game(game);
	return (0);
}
void	ft_win_game(t_game *game);
void	ft_move_player(t_game *game, int go_x, int go_y, int facing)
{
	int	curr_x;
	int	curr_y;

	curr_x = game->map_data.plyr_x;
	curr_y = game->map_data.plyr_y;
	game->plyr_facing = facing;
	if (game->map_data.map[go_y][go_x] == EXIT && game->map_data.coins == 0)
		ft_win_game(game);
	else if (game->map_data.map[go_y][go_x] == FLOOR || game->map_data.map[go_y][go_x] == GEO)
	{
		game->map_data.map[curr_y][curr_x] = FLOOR;
		if (game->map_data.map[go_y][go_x] == GEO)
			game->map_data.coins--;
		game->map_data.plyr_x = go_x;
		game->map_data.plyr_y = go_y;
		game->map_data.map[go_y][go_x] = PLAYER;
		game->movements++;
		ft_render_map(game);
	}
}



void	ft_check_rows(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_data.rows)
	{
		if (game->map_data.map[y][0] != WALL)
			ft_error(game, "no wall");
		else if (game->map_data.map[y][game->map_data.columns - 1] != WALL)
			ft_error(game, "no wall");
		y++;
	}
}

void	ft_check_cols(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map_data.columns)
	{
		if (game->map_data.map[0][x] != WALL)
			ft_error(game, "no wall");
		else if (game->map_data.map[game->map_data.rows - 1][x] != WALL)
			ft_error(game, "no wall");
		x++;
	}
}

void	ft_count_objectives(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_data.rows)
	{
		x = 0;
		while (x < game->map_data.columns)
		{
			if (!ft_strchr("01CEP", game->map_data.map[y][x]))
				ft_error(game, "extra stuff");
			else if (game->map_data.map[y][x] == PLAYER)
			{
				game->map_data.players++;
				game->map_data.plyr_y = y;
				game->map_data.plyr_x = x;
			}
			else if (game->map_data.map[y][x] == GEO)
				game->map_data.coins++;
			else if (game->map_data.map[y][x] == EXIT)
				game->map_data.exit++;
			x++;
		}
		y++;
	}
}

void	ft_check_objectives(t_game *game)
{
	if (game->map_data.coins == 0)
		ft_error(game, "no coins");
	else if (game->map_data.exit == 0)
		ft_error(game, "no exit");
	else if (game->map_data.players != 1)
		ft_error(game, "singleplayer only");
}

void	ft_check_exitable(char **map_temp, int x, int y, bool *exitable)
{
	if (map_temp[y][x] == WALL || map_temp[y][x] == '2')
		return ;
	if (map_temp[y][x] == EXIT)
		*exitable = true;
	map_temp[y][x] = '2';
	ft_check_exitable(map_temp, x + 1, y, exitable);
	ft_check_exitable(map_temp, x - 1, y, exitable);
	ft_check_exitable(map_temp, x, y + 1, exitable);
	ft_check_exitable(map_temp, x, y - 1, exitable);
}

void	ft_free_map_temp(char **map_temp, int i)
{
	while (i >= 0)
		free(map_temp[i--]);
	free(map_temp);
}

void	ft_check_playable(t_game *game)
{
	bool	exitable;
	char	**temp;
	int	i;

	exitable = false;
	temp = (char **)malloc(sizeof(char *) * (game->map_data.rows));
	if (temp == NULL)
		ft_error(game, "malloc fail");
	i = 0;
	while (i < game->map_data.rows)
	{
		temp[i] = ft_strdup(game->map_data.map[i]);
		if (temp[i] == NULL)
			ft_free_map_temp(temp, i);
		i++;
	}
	temp[i] = NULL;
	ft_check_exitable(temp, game->map_data.plyr_x, game->map_data.plyr_y, &exitable);
	if (!exitable)
	{
		ft_free_map_temp(temp, i);
		ft_error(game, "no path to exit");
	}
	ft_free_map_temp(temp, i);
}


void	ft_check_map(t_game *game)
{
	ft_check_cols(game);
	ft_check_rows(game);
	ft_count_objectives(game);
	ft_check_objectives(game);
}

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.img_ptr);
	mlx_destroy_image(game->mlx, game->floor.img_ptr);
	mlx_destroy_image(game->mlx, game->coins.img_ptr);
	mlx_destroy_image(game->mlx, game->player_front.img_ptr);
	mlx_destroy_image(game->mlx, game->player_left.img_ptr);
	mlx_destroy_image(game->mlx, game->player_right.img_ptr);
	mlx_destroy_image(game->mlx, game->player_back.img_ptr);
	mlx_destroy_image(game->mlx, game->exit_close.img_ptr);
	mlx_destroy_image(game->mlx, game->exit_open.img_ptr);
}

void	ft_free_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_data.rows)
		free(game->map_data.map[y++]);
	free(game->map_data.map);
}

void	ft_free_everything(t_game *game)
{
	ft_destroy_images(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->win_ptr);
	//mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

int	ft_close_game(t_game *game)
{
	ft_printf("Movements: %d\n", game->movements);
	ft_free_everything(game);
	ft_printf("CLOSED\n");
	exit(EXIT_FAILURE);
}

void	ft_win_game(t_game *game)
{
	ft_free_everything(game);
	ft_printf("٩(ˊᗜˋ*)و♡ you won! ♡٩(ˊᗜˋ*)و ");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return 0;
	game = (t_game *)malloc(sizeof(t_game));
	
	(void)game;
	ft_readmap(game, av[1]);
	ft_init_vars(game);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free(game->mlx);
		ft_error(game, "no mlx");
	}
	game->win_ptr = mlx_new_window(game->mlx, game->map_data.columns * IMG_WIDTH, game->map_data.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		ft_error(game, "no win");
	}
	ft_init_vars(game);
	ft_check_map(game);
	ft_check_playable(game);
	ft_init_sprite(game);
	ft_render_map(game);
	mlx_hook(game->win_ptr, 2, 0, ft_handle_input, game);
	mlx_hook(game->win_ptr, 17, 0, ft_close_game, game);
	mlx_hook(game->win_ptr, 12, 0, ft_render_map, game);
	mlx_loop(game->mlx);
	ft_free_everything(game);
}
