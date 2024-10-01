/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:05:53 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/01 16:13:32 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	game_data;

	(void)av;

	if (arg_check(ac, av) != 0)
		return (1);
	init_all(&game_data);
	parse_and_validate_game_data(av[1], &game_data);


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