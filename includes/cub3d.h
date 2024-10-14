/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:47:00 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/14 12:15:38 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "structs.h"
# include "fcntl.h"

/*			Macros			*/
# define ERR_ARGS "usage: ./cub3d <path/to/map>"
# define ERR_CUB_FORMAT "Ivalid map file: file extension is not .cub"
# define ERR_OPEN "Error opening file descriptor"
# define MALLOC "Memory allocation failed"
# define MAPSTART "Map start not found"
# define ERR_MAP_MISSING "Map is missing"
# define ERR_INV_LETTER "Invalid characters in the map. Should just be 10NSEW "
# define ERR_NUM_PLAYER "Too many players found. Only one player allowed"
# define ERR_NO_PLAYER "No player found"
# define ERR_PARSING "There's an error with the file parsing"
# define ERR_MAP_INV "Invalid map"
# define ERR_MAP_BOUNDS "Invalid map: out of bounds"
# define ERR_MAP_GAP "Invalid map: there's a gap in the map"
# define ERR_MAP_LIMIT "Invalid map: top or bottom not enclosed by walls"
# define ERR_MAP_SIDES "Invalid map: map side walls not enclosed by walls"


/*  Functions  */


/*  Init    */
void		init_all(t_data *data);
void		init_mlx(t_mlx *mlx);
void		init_mapdata(t_mapdata *mapdata);
void		init_player(t_player *player);
void		init_game_config(t_game_config *config);


/* Error Handling*/
int			error_code_msg(char *str, int code);
void		error_msg(char *str);

/* Arguments Check	*/
int			is_cub(char *av);
int			arg_check(int ac, char **av);

/* Parsing */
int			parse_and_validate_game_data(char *filename, t_data *game_data);
void		fill_mapdata(t_mapdata *mapdata);
int			parse_filedata(char *path, t_mapdata *mapdata);
int			count_lines(char *path);
int			parse_map(t_mapdata *mapdata, t_game_config *config);
int			calculate_map_height(char **file, int map_start, int num_lines);
char		**allocate_map_memory(int map_height);
void		get_map(t_game_config *config, char **file, int map_start);
int			validate_map(t_game_config *config);
int			check_map_elements(char **map);

/*	Validating Map*/
int			validate_map_char(char c, int *player_count);
int			validate_map(t_game_config *config);
int			check_map_elements(char **map);
int			flood_fill(int x, int y, char **grid, t_game_config *game);
int			validate_walls(t_game_config *config);



/*	Utils	*/
int			ft_isspace(char c);
int			find_map_start(char **file, int num_lines);
int			is_map_row(char *line);
int			is_valid_map_char(char c);
char		**copy_map(char **map, int height);
int			check_top_and_bottom(char **map, int i, int j);
int			check_if_map_is_enclosed(t_game_config *game);
int			check_walkable_path(char **map_copy, t_game_config *game);


/* Test */
void print_map(t_game_config *config);


#endif