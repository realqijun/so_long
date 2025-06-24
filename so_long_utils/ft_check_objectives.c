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

void	ft_check_walls(t_game *game);
void	ft_count_objectives(t_game *game);
void	ft_check_objectives(t_game *game);
void	ft_check_map(t_game *game);

void	ft_check_walls(t_game *game)
{
	int	i;
	
	i = 0;
	while (i < game->map_data.rows)
	{
		if (game->map_data.map[i][0] != WALL || game->map_data.map[i][game->map_data.columns - 1] != WALL)
			ft_error(game, "Error: Missing a vertical wall piece.");
		i++;
	}
	i = 0;
	while (i < game->map_data.columns)
	{
		if (game->map_data.map[0][i] != WALL || game->map_data.map[game->map_data.rows - 1][i] != WALL)
			ft_error(game, "Error: Missing a horizontal wall piece.");
		i++;
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
			if (!ft_strchr("01CEPX", game->map_data.map[y][x]))
				ft_error(game, "Error: Undefined objects present in map provided.");
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
		ft_error(game, "Error: Map has no objectives.");
	else if (game->map_data.exit == 0)
		ft_error(game, "Error: Map is not exitable.");
	else if (game->map_data.players != 1)
		ft_error(game, "Error: Map does not have only 1 player.");
}

void	ft_check_map(t_game *game)
{
	ft_printf("Map information:\n");
	ft_printf("Rows:%d\n", game->map_data.rows);
	ft_printf("Cols:%d\n", game->map_data.columns);
	ft_check_walls(game);
	ft_count_objectives(game);
	ft_check_objectives(game);
}
