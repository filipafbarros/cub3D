/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:34:38 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/14 14:41:20 by fibarros         ###   ########.fr       */
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

int	flood_fill(int x, int y, char **grid, t_game_config *game)
{
	if (x < 0 || y < 0 || y >= game->map_height || x >= \
		(int)ft_strlen(grid[y]))
	{
		//free array
		return (error_code_msg(ERR_MAP_BOUNDS, 1));
	}
	if (grid[y][x] == 'H' || grid[y][x] == '1')
		return (0);
	grid[y][x] = 'H';
	if (flood_fill(x + 1, y, grid, game) || flood_fill(x - 1, y, grid, game) \
	|| flood_fill(x, y + 1, grid, game) || flood_fill(x, y - 1, grid, game))
		return (1);
	return (0);
}


// void	flood_fill(int x, int y, char **grid, t_game_config *game)
// {
// 	if (x < 0 || y < 0 || y >= game->map_height || x >= \
// 		(int)ft_strlen(grid[y]))
// 	{
// 		//free array
// 		error_msg(ERR_MAP_INV);
// 		return ;
// 	}
// 	if (grid[y][x] == 'H' || grid[y][x] == "1")
// 		return ;
// 	if (grid[y][x] == ' ')
// 	{
// 		if ((x > 0 && grid[y][x - 1] == '0') || (x < (int)ft_strlen(grid[y]) \
// 			- 1 && grid[y][x + 1] == '0') || (y > 0 && grid[y - 1][x] == '0') \
// 			|| (y < game->map_height - 1 && grid[y + 1][x] == '0'))
// 		{
// 			// free array
// 			error_msg(ERR_MAP_GAP);
// 			return ;
// 		}
// 		return ;
// 	}
// 	grid[y][x] = 'H';
// 	flood_fill(x + 1, y, grid, game);
// 	flood_fill(x - 1, y, grid, game);
// 	flood_fill(x, y + 1, grid, game);
// 	flood_fill(x, y - 1, grid, game);
// }

int	validate_walls(t_game_config *game)
{
	char	**map_copy;

	map_copy = copy_map(game->map, game->map_height);
	if (!map_copy)
		return (error_code_msg(MALLOC, 1));
	if (check_if_map_is_enclosed(game))
	{
		//free map
		return (1);
	}
	if (check_walkable_path(map_copy, game))
	{
		// free map
		return (1);
	}
	//free map
	return (0);
}
