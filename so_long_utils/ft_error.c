/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:28:13 by qang              #+#    #+#             */
/*   Updated: 2023/12/10 14:29:30 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_game *game, char *msg);
void	ft_destroy_images(t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_everything(t_game *game);
int	ft_close_game(t_game *game);

void	ft_error(t_game *game, char *msg)
{
	if (game->mloc == true)
		ft_free_map(game);
	free(game);
	ft_printf("Error\n%s", msg);
	exit(EXIT_FAILURE);
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

	/*mlx_destroy_display(game->mlx);*/
void	ft_free_everything(t_game *game)
{
	ft_destroy_images(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->win_ptr);
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
