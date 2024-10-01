/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:23:44 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/01 15:59:48 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(t_mapdata *mapdata, t_game_config *config)
{
	int	i;
	int	map_start;

	i = 0;
	map_start = find_map_start(mapdata->file, mapdata->num_lines);
	if (map_start == -1)
		return (error_code_msg(MAPSTART, 1));
	config->map_height = calculate_map_height(mapdata->file, map_start, \
		mapdata->num_lines);
	config->map = allocate_map_memory(config->map_height);
	if (!config->map)
		return (error_code_msg(MALLOC, 1));
	get_map(config, mapdata->file, map_start);
	return (0);
}

int	calculate_map_height(char **file, int map_start, int num_lines)
{
	int	map_height;
	int	i;

	i = map_start;
	map_height = 0;
	while (i < num_lines)
	{
		if (is_map_row(file[i]))
			map_height++;
		else
			break ;
		i++;
	}
	return (map_height);
}

char	**allocate_map_memory(int map_height)
{
	return ((char **)ft_calloc(map_height + 1, sizeof(char *)));
}

void	get_map(t_game_config *config, char **file, int map_start)
{
	int	i;

	i = 0;
	while (i < config->map_height)
	{
		config->map[i] = ft_strdup(file[map_start + i]);
		if (!config->map[i])
		{
			error_msg(MALLOC);
			while (i > 0)
				free(config->map[--i]);
			free(config->map);
			return ;
		}
		i++;
	}
	config->map[config->map_height] = NULL;
}
