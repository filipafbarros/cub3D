/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:13:39 by fibarros          #+#    #+#             */
/*   Updated: 2024/09/26 16:33:06 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' \
	|| c == '\f' || c == '\r');
}

int	find_map_start(char **file, int num_lines)
{
	int	i;

	i = 0;
	while (i < num_lines)
	{
		if (is_map_row(file[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	is_map_row(char *line)
{
	while (*line)
	{
		if (*line == '1' || *line == '0')
			return (1);
		else if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (0);
}

int	is_valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' \
		|| c == 'W');
}
