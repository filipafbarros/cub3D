/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:27:20 by fibarros          #+#    #+#             */
/*   Updated: 2024/09/26 14:22:05 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* Structs */

typedef struct s_mlx
{
	void	*mlx;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
	int		win_width;
	int		win_height;
}	t_mlx;

typedef struct s_mapdata
{
	int		fd;
	int		num_lines;
	int		height;
	int		width;
	char	*path;
	char	**file;
}	t_mapdata;

typedef struct s_game_config
{
	char	**map;
	int		map_height;
	int		map_width;
}	t_game_config;

typedef struct s_player
{
	char		dir;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
}	t_player;

typedef struct s_data
{
	t_mlx			mlx;
	t_mapdata		mapdata;
	t_game_config	game;
}	t_data;


#endif