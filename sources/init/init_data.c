/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:17:24 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/01 15:20:42 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_all(t_data *data)
{
	init_mlx(&data->mlx);
	init_mapdata(&data->mapdata);
	init_game_config(&data->game);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win_ptr = NULL;
	mlx->img_ptr = NULL;
	mlx->img_addr = NULL;
	mlx->pixel_bits = 0;
	mlx->size_line = 0;
	mlx->endian = 0;
	mlx->win_width = 0;
	mlx->win_height = 0;
}

void	init_mapdata(t_mapdata *mapdata)
{
	mapdata->fd = -1;
	mapdata->file = NULL;
	mapdata->height = 0;
	mapdata->num_lines = 0;
	mapdata->path = NULL;
	mapdata->width = 0;
}

void	init_player(t_player *player)
{
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->start_dir = NULL;
}

void	init_game_config(t_game_config *config)
{
	config->map = NULL;
	config->map_height = 0;
	config->map_width = 0;
	config->player = NULL;
}
