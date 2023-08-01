/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:37:19 by rbryento          #+#    #+#             */
/*   Updated: 2023/08/01 17:27:22 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int is_valid(char **map, int row, int col, int size)
{
	int i = 0;
	while (i < size)
	{
		int j = 0;
		while (j < size)
		{
			if (map[row + i][col + j] == map[0][ft_strlen(map[0]) - 2])
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

void check_square(char **map, t_square_info *sq_info)
{
	int n = 1;
	while (sq_info->i + n < ft_strlen(map[1]) && sq_info->j + n < ft_strlen(map[sq_info->i + n]))
	{
		if (!is_valid(map, sq_info->i, sq_info->j, n))
			break;
		n++;
	}

	if (n - 1 > sq_info->size)
	{
		sq_info->size = n - 1;
		sq_info->x = sq_info->j;
		sq_info->y = sq_info->i;
	}
}

t_square_info find_square(char **map)
{
	t_square_info sq_info;
	sq_info.size = 0;
	sq_info.x = 0;
	sq_info.y = 0;
	sq_info.full = map[0][ft_strlen(map[0]) - 1];
	sq_info.obstacle = map[0][ft_strlen(map[0]) - 2];
	sq_info.i = 1;

	while (map[sq_info.i])
	{
		sq_info.j = 0;
		while (map[sq_info.i][sq_info.j])
		{
			if (map[sq_info.i][sq_info.j] != sq_info.obstacle)
				check_square(map, &sq_info);
			sq_info.j++;
		}
		sq_info.i++;
	}

	return sq_info;
}
