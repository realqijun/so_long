/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:02:54 by qang              #+#    #+#             */
/*   Updated: 2023/12/10 14:56:18 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map_name(t_game *game, char *map_filename);
void	ft_check_map_nl(t_game *game, char *map_str);
void	ft_read_map(t_game *game, char *map_filename);

void	ft_check_map_nl(t_game *game, char *map_str)
{
	int	index;

	if (*map_str == '\n')
		ft_error(game, "Error: Map has newline at the beginning.");
	if (map_str[ft_strlen(map_str) - 1] == '\n')
		ft_error(game, "Error: Map has newline at the end.");
	index = 1;
	while (map_str[index + 1])
	{
		if (map_str[index] == '\n' && map_str[index + 1] == '\n')
			ft_error(game, "Error: Map has double newline characters.");
		index++;
	}
}

void	ft_check_map_name(t_game *game, char *map_filename)
{
	if (!ft_strnstr(&map_filename[ft_strlen(map_filename) - 4], ".ber", 4))
		ft_error(game, "Error: Invalid map file type.");
}

void	ft_read_map(t_game *game, char *map_filename)
{
	int		fd;
	char	*temp;
	char	*buf;	

	game->mloc = false;
	game->map_data.rows = 0;
	ft_check_map_name(game, map_filename);
	fd = open(map_filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "Error: Could not open map file.");
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
	ft_check_map_nl(game, temp);
	game->map_data.map = ft_split(temp, '\n');
	game->mloc = true;
	free(temp);
}
