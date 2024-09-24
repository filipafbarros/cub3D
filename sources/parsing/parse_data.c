/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:15:17 by fibarros          #+#    #+#             */
/*   Updated: 2024/09/18 16:20:58 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



/*
Bullet-Point Summary of the Code:
get_number_of_lines:

Opens the file.
Counts the number of lines using get_next_line().
Closes the file and returns the total number of lines.
fill_tab:

Allocates memory for each row of the file 2D array.
Reads each line of the file and stores it in the file array.
Frees the lines after storing them in the array.
parse_data:

Calls get_number_of_lines() to determine the number of lines in the file.
Allocates memory for the file array.
Opens the file and calls fill_tab() to store its contents in the file array.
Closes the file after reading.

*/