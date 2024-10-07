/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:34:38 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/07 16:57:26 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_map(t_game_config *game)
{
	if (!game->map)
		return (error_code_msg(ERR_MAP_MISSING, 1));
	if (check_map_elements(game->map) == 1)
		return (1);
	if (validate_walls(game) != 0)
		return (1);
	return (0);
}

int	check_map_elements(char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (validate_map_char(map[i][j], &player_count) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(int x, int y, char **tiles, t_game_config *game)
{
	if (x < 0 || y < 0 || y >= game->map_height || x >= \
		(int)ft_strlen(tiles[y]))
	{
		//free array
		error_msg(ERR_MAP_INV);
	}
	if (tiles[x][y] == ' ')
	{
		if ((x > 0 && tiles[y][x - 1] == '0') || (x < (int)ft_strlen(tiles[y]) \
			- 1 && tiles[y][x + 1] == '0') || (y > 0 && tiles[y - 1][x] == '0') \
			|| (y < game->map_height - 1 && tiles[y + 1][x] == '0'))
		{
			// free array
			error_msg(ERR_MAP_GAP);
		}
		return ;
	}
	if (tiles[y][x] == 'H' || tiles[y][x] == -1)
		return ;
	tiles[y][x] = 'H';
	flood_fill(x + 1, y, tiles, game);
	flood_fill(x - 1, y, tiles, game);
	flood_fill(x, y + 1, tiles, game);
	flood_fill(x, y - 1, tiles, game);
}

int	validate_walls(t_game_config *game)
{
	int		i;
	int		j;
	char	**map_copy;

	map_copy = copy_map(game->map, game->map_height);
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (ft_strchr("NSEW", map_copy[i][j]))
				flood_fill(j, i, map_copy, game);
			j++;
		}
		i++;
	}
	//free array
	return (0);
}
