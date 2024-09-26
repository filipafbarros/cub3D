/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:05:53 by fibarros          #+#    #+#             */
/*   Updated: 2024/09/25 16:31:18 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	// t_data	data;
	t_mapdata	mapdata;

	(void)av;

	if (arg_check(ac, av) != 0)
		return (1);
	parse_filedata(av[1], &mapdata);

	// initialize data
	// parsing
	// init mlx
	// render
	// mlx loops
}
/*

testing stuff:
	for (int i = 0; i < mapdata.num_lines; i++)
    {
        if (mapdata.file[i])
            printf("Line %d: %s", i, mapdata.file[i]);  // Newline is already part of the line
    }
*/