/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:40:28 by rbryento          #+#    #+#             */
/*   Updated: 2023/08/01 17:14:23 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdio.h>

static void	replace_square(char **map, t_square_info sq_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < sq_info.size)
	{
		j = 0;
		while (j < sq_info.size)
		{
			if (map[sq_info.y + i][sq_info.x + j])
				map[sq_info.y + i][sq_info.x + j] = sq_info.full;
			j++;
		}
		i++;
	}
}

void	print_map(char **map, t_square_info sq_info)
{
	int	i;

	i = 1;
	replace_square(map, sq_info);
	while (map[i])
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		i++;
	}
}
