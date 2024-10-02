/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:34:38 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/02 14:21:33 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_map(t_game_config *config)
{
	if (!config->map)
		return (error_code_msg(ERR_MAP_MISSING, 1));
	if (check_map_elements(config->map) == 1)
		return (1);
	// validade player position
	// ensure the map os surrounded by walls
	// ensure there's no extraneous content after the map
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
	if (player_count == 0)
		return (error_code_msg(ERR_NO_PLAYER, 1));
	return (0);
}

int	check_row(char *row)
{
	
}


// int	validate_player_position()



/*

* read the map
* check the elements of the map
		- checks if each element in the map is a valid character (1, 0, N, S, E, W)
		- checks if there's only one player
	
* check if position is valid
	- checks if the players position is not adjacent to any invalid spaces
	
* check player position
	- confirms if player direction is valid (N S E W)
	- locates players initial position, storing it in the struct
	- converts players starting position into an empty space
	- checks if players position is valid

* check map is at the end
	- after the map is parsed, checks if there are no aditional characters or 
	that non-whitespace characters exist beyond the end of the map

* check map validity
	- checks if map exists
	- cheks if map is surrounded by walls
	- checks if map is not too small
	- checks the elements of the map
	- checks the position of the player
	checks if map is at the end

*/

