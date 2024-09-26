/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:15:17 by fibarros          #+#    #+#             */
/*   Updated: 2024/09/26 14:23:06 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	parse_filedata(char *path, t_mapdata *mapdata)
{
	mapdata->path = path;
	mapdata->num_lines = count_lines(path);
	mapdata->file = ft_calloc(mapdata->num_lines + 1, sizeof(char *));
	if (!mapdata->file)
	{
		error_msg(MALLOC);
		return ;
	}
	mapdata->fd = open(path, O_RDONLY);
	if (mapdata->fd == -1)
	{
		error_msg(ERR_OPEN);
		free(mapdata->file);
		return ;
	}
	fill_mapdata(mapdata);
	close(mapdata->fd);
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
