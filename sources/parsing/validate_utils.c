/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:56:57 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/14 15:36:04 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**copy_map(char **map, int height)
{
	char	**new_map;
	int		i;

	new_map = allocate_map_memory(height);
	if (!new_map)
	{
		error_msg(MALLOC);
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			error_msg(MALLOC);
			while (i > 0)
				free(new_map[--i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	check_top_and_bottom(char **map, int i, int j)
{
	if (!map || !map[i] || !map[i][j])
		return (error_code_msg(ERR_MAP_MISSING, 1));
	while (ft_isspace(map[i][j]))
		j++;
	while (map[i][j])
	{
		if (!(map[i][j] == '1'))
			return (error_code_msg(ERR_MAP_LIMIT, 1));
		j++;
	}
	return (0);
}

int	check_if_map_is_enclosed(t_game_config *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_top_and_bottom(game->map, 0, 0))
		return (1);
	i = 1;
	while (i < game->map_height - 1)
	{
		j = 0;
		while (ft_isspace(game->map[i][j]))
			j++;
		if (!(game->map[i][j] == '1'))
			return (error_code_msg(ERR_MAP_SIDES, 1));
		j = ft_strlen(game->map[i]) - 1;
		if (!(game->map[i][j] == '1'))
			return (error_code_msg(ERR_MAP_SIDES, 1));
		i++;
	}
	if (check_top_and_bottom(game->map, i, 0))
		return (1);
	return (0);
}

int	check_walkable_path(char **map_copy, t_game_config *game)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (ft_strchr("NSEW", map_copy[i][j]))
			{
				if (flood_fill(j, i, map_copy, game))
				{
					//free array
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	new_print_map(map_copy);
	return (0);
}

void    new_print_map(char **map)
{
    int i = 0;
    
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
}
