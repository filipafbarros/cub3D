/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:15:17 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/09 11:14:56 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_and_validate_game_data(char *filename, t_data *game_data)
{
	if (parse_filedata(filename, &game_data->mapdata) != 0)
		return (error_code_msg(ERR_PARSING, 1));
	// Parse textures and colors
	if (parse_map(&game_data->mapdata, &game_data->game) != 0)
		return (1);
	// print_map(&game_data->game);
	if (validate_map(&game_data->game) != 0)
		return (1);
	return (0);
}

int	count_lines(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_code_msg(ERR_OPEN, -1));
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

int	parse_filedata(char *path, t_mapdata *mapdata)
{
	mapdata->path = path;
	mapdata->num_lines = count_lines(path);
	mapdata->file = ft_calloc(mapdata->num_lines + 1, sizeof(char *));
	if (!mapdata->file)
	{
		return (error_code_msg(MALLOC, 1));
	}
	mapdata->fd = open(path, O_RDONLY);
	if (mapdata->fd == -1)
	{
		free(mapdata->file);
		return (error_code_msg(ERR_OPEN, 1));
	}
	fill_mapdata(mapdata);
	close(mapdata->fd);
	return (0);
}

void	fill_mapdata(t_mapdata *mapdata)
{
	int		row;
	char	*line;

	row = 0;
	line = get_next_line(mapdata->fd);
	while (line)
	{
		mapdata->file[row++] = line;
		line = get_next_line(mapdata->fd);
	}
	mapdata->file[row] = NULL;
}

// void	fill_mapdata(t_mapdata *mapdata)
// {
// 	char	*line;
// 	int		row;
// 	int		len;

// 	row = 0;
// 	line = get_next_line(mapdata->fd);
// 	while (line != NULL)
// 	{
// 		len = ft_strlen(line);
// 		if (line[len - 1] == '\n')
// 			len--;
// 		mapdata->file[row] = ft_calloc(len + 1, sizeof(char));
// 		if (!mapdata->file[row])
// 		{
// 			error_msg(MALLOC);
// 			//free_array
// 			return ;
// 		}
// 		ft_strlcpy(mapdata->file[row], line, len + 1);
// 		free(line);
// 		row++;
// 		line = get_next_line(mapdata->fd);
// 	}
// 	mapdata->file[row] = NULL;
// }
