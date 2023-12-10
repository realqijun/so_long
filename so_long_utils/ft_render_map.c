/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:34:20 by qang              #+#    #+#             */
/*   Updated: 2023/12/10 14:34:27 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		ft_render_player(game, x, y);
}

void	ft_render_sprite(t_game *game, t_image img, int x, int y)
{
	mlx_put_image_to_window (game->mlx, game->win_ptr, \
	img.img_ptr, x * img.x, y * img.y);
}
