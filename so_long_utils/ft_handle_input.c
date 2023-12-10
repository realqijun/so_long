/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:29:45 by qang              #+#    #+#             */
/*   Updated: 2023/12/10 14:30:47 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	ft_handle_input(int key, t_game *game)
{
	if (key == W)
		ft_move_player(game, game->map_data.plyr_x, \
				game->map_data.plyr_y - 1, FRONT);
	if (key == A)
		ft_move_player(game, game->map_data.plyr_x - 1, \
				game->map_data.plyr_y, LEFT);
	if (key == S)
		ft_move_player(game, game->map_data.plyr_x, \
				game->map_data.plyr_y + 1, BACK);
	if (key == D)
		ft_move_player(game, game->map_data.plyr_x + 1, \
				game->map_data.plyr_y, RIGHT);
	if (key == ESC)
		ft_close_game(game);
	return (0);
}

void	ft_move_player(t_game *game, int go_x, int go_y, int facing)
{
	int	curr_x;
	int	curr_y;

	curr_x = game->map_data.plyr_x;
	curr_y = game->map_data.plyr_y;
	game->plyr_facing = facing;
	if (game->map_data.map[go_y][go_x] == EXIT && game->map_data.coins == 0)
		ft_win_game(game);
	else if (game->map_data.map[go_y][go_x] == FLOOR ||
			game->map_data.map[go_y][go_x] == GEO)
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
