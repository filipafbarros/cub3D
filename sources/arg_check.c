/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:14:48 by fibarros          #+#    #+#             */
/*   Updated: 2024/09/25 16:30:05 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* 
	Checks the arguments. First if it's different from 2 
	(Usage should be:  ./cub3d <path/to/map>)
	and if the second argument is of type .cub
*/

int	arg_check(int ac, char **av)
{
	if (ac != 2)
		return (error_code_msg(ERR_ARGS, 1));
	else
	{
		if (!is_cub(av[1]))
			return (error_code_msg(ERR_CUB_FORMAT, 1));
	}
	return (0);
}

int	is_cub(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (len < 4)
		return (0);
	if ((ft_strncmp(av + len - 4, ".cub", 4)))
		return (0);
	return (1);
}
