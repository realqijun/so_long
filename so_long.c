#include "so_long.h"

void	ft_win_game(t_game *game)
{
	ft_free_everything(game);
	ft_printf("٩(ˊᗜˋ*)و♡ you won! ♡٩(ˊᗜˋ*)و ");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return 0;
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_error(game, "malloc fail");
	ft_read_map(game, av[1]);
	ft_init_vars(game);
	ft_init_mlx(game);
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
