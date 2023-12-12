/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_playable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:23:05 by qang              #+#    #+#             */
/*   Updated: 2023/12/10 14:27:54 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static void	ft_copy_map(t_game *game, char **temp)
{
	int	i;

	i = 0;
	while (i < game->map_data.rows)
	{
		temp[i] = ft_strdup(game->map_data.map[i]);
		if (temp[i] == NULL)
			ft_free_map_temp(temp, i);
		i++;
	}
	temp[i] = NULL;
}

void	ft_check_playable(t_game *game)
{
	bool	exitable;
	char	**temp;

	exitable = false;
	temp = (char **)malloc(sizeof(char *) * (game->map_data.rows + 1));
	if (temp == NULL)
		ft_error(game, "malloc fail");
	ft_copy_map(game, temp);
	ft_check_exitable(temp, game->map_data.plyr_x, \
			game->map_data.plyr_y, &exitable);
	if (!exitable)
	{
		ft_free_map_temp(temp, game->map_data.rows);
		ft_error(game, "no path to exit");
	}
	ft_free_map_temp(temp, game->map_data.rows);
}
