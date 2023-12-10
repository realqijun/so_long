/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_objectives.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:22:30 by qang              #+#    #+#             */
/*   Updated: 2023/12/10 14:22:31 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	ft_check_map(t_game *game)
{
	ft_check_cols(game);
	ft_check_rows(game);
	ft_count_objectives(game);
	ft_check_objectives(game);
}
