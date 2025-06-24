#include "so_long.h"
#include <stdlib.h>

void	ft_end_game(t_game *game, bool win)
{
	ft_free_everything(game);
	if (win) 
		ft_printf("٩(ˊᗜˋ*)و♡ you won! ♡٩(ˊᗜˋ*)و \n");
	else
		ft_printf("૮(˶ㅠ︿ㅠ)ა you lost! ˙◠˙ \n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_printf("Invalid usage, try again with: %s <map>\n", av[0]);
		return (0);
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_error(game, "Failed to allocate memory for game instance.");
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
	return (EXIT_SUCCESS);
}
