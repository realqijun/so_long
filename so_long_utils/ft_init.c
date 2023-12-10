/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:31:13 by qang              #+#    #+#             */
/*   Updated: 2023/12/10 14:31:29 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_vars(t_game *game)
{
	game->map_data.coins = 0;
	game->map_data.exit = 0;
	game->map_data.players = 0;
	game->movements = 0;
	game->map_data.columns = ft_strlen(game->map_data.map[0]) - 1;
	game->plyr_facing = RIGHT;
}

void	ft_init_sprite(t_game *game)
{
	game->wall = ft_new_sprite(game, game->mlx, WALL_XPM);
	game->floor = ft_new_sprite(game, game->mlx, FLOOR_XPM);
	game->coins = ft_new_sprite(game, game->mlx, GEO_XPM);
	game->player_front = ft_new_sprite(game, game->mlx, PLAYER_FRONT);
	game->player_left = ft_new_sprite(game, game->mlx, PLAYER_LEFT);
	game->player_right = ft_new_sprite(game, game->mlx, PLAYER_RIGHT);
	game->player_back = ft_new_sprite(game, game->mlx, PLAYER_BACK);
	game->exit_open = ft_new_sprite(game, game->mlx, EXIT_OPEN);
	game->exit_close = ft_new_sprite(game, game->mlx, EXIT_CLOSE);
}

t_image	ft_new_sprite(t_game *game, void *mlx, char *path)
{
	t_image	img;

	img.img_ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	if (img.img_ptr == NULL)
		ft_error(game, "no img");
	return (img);
}
