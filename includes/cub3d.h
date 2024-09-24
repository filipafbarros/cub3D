/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:47:00 by fibarros          #+#    #+#             */
/*   Updated: 2024/09/18 16:23:22 by fibarros         ###   ########.fr       */
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

/*			Macros			*/
# define ERR_ARGS "usage: ./cub3d <path/to/map>"
# define ERR_CUB_FORMAT "Ivalid map file: file extension is not .cub"


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

typedef	struct s_map
{
	int		fd;
	int		line_num;
	
	
}	t_map;

typedef struct s_data
{
	t_mlx	mlx;
	t_map	map;
}	t_data;






/*  Functions  */

/* Error Handling*/
int		error_msg(char *str, int code);

/* Arguments Check	*/
int		is_cub(char *av);
int		arg_check(int ac, char **av);

#endif