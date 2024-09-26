/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:34:38 by fibarros          #+#    #+#             */
/*   Updated: 2024/09/26 16:42:33 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_elements(char **file, int map_start, int map_height)
{
	int		i;
	int		j;

	i = map_start;
	while (i < map_height + map_start)
	{
		j = 0;
		while (file[i][j])
		{
			while (ft_isspace(file[i][j]))
				j++;
			
		}
	}
}



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

