/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:47:00 by fibarros          #+#    #+#             */
/*   Updated: 2024/09/26 14:48:22 by fibarros         ###   ########.fr       */
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

/*  Functions  */

/* Error Handling*/
int		error_code_msg(char *str, int code);
void	error_msg(char *str);

/* Arguments Check	*/
int		is_cub(char *av);
int		arg_check(int ac, char **av);

/* Parsing */
void	fill_mapdata(t_mapdata *mapdata);
void	parse_filedata(char *path, t_mapdata *mapdata);
int		count_lines(char *path);


#endif