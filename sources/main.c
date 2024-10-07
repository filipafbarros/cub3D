/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:05:53 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/07 16:34:51 by fibarros         ###   ########.fr       */
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
	// print_map(&game_data.game);


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



/*

	//  if (parse_filedata(av[1], &game_data.mapdata) != 0)
    // {
    //     printf("Failed to parse file data.\n");
    //     return (1);
    // }

    // if (parse_map(&game_data.mapdata, &game_data.game) != 0)
    // {
    //     printf("Failed to parse map.\n");
    //     return (1);
    // }
	//  print_map(&game_data.game);

*/



void print_map(t_game_config *config)
{
    int i = 0;

    if (config->map == NULL)
    {
        printf("Map is empty or not initialized.\n");
        return;
    }

    printf("Parsed Map:\n");
    while (i < config->map_height)
    {
        printf("%s", config->map[i]);
        i++;
    }
}
