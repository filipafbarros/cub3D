/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:23:44 by fibarros          #+#    #+#             */
/*   Updated: 2024/09/26 15:06:24 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_mapdata *mapdata, t_game_config *config)
{
	int	i;
	int	map_start;

	i = 0;
	map_start = find_map_start(mapdata->file, mapdata->num_lines);
	if (map_start == -1)
		return (error_msg(MAPSTART));
	config->map_height = calculate_map_height(mapdata->file, map_start, \
		mapdata->num_lines);
	// validate map
}



int	calculate_map_height(char **file, int map_start, int num_lines)
{
	int	map_height;

	map_height = 0;
	while (map_height < num_lines)
	{
		if (is_map_row(file[map_height]))
			map_height++;
		else
			break ;
	}
	return (map_height);
}
