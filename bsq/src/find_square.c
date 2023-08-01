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
#include <stdio.h>
#include <unistd.h>

int	check_square(char **map, t_square_info *sq_info)
{
	int	n;
	int	ci;
	int	cj;

	n = 0;
	while (n < ft_strlen(map[1]) - 1)
	{
		ci = sq_info->i;
		cj = sq_info->j + n + 1;
		while (ci <= n + 1 + sq_info->i)
		{
			if (!map[ci] || map[ci][cj] == sq_info->obstacle)
			{
				if (n <= sq_info->size)
					return (0);
				sq_info->x = sq_info->i;
				sq_info->y = sq_info->j;
				sq_info->size = n;
				printf("size: %d | x: %d | y: %d\n", sq_info->size, sq_info->x, sq_info->y);
			}
			ci++;
		}
		ci--;
		while (cj >= sq_info->j)
		{
			if (map[ci][cj] == sq_info->obstacle || map[ci][cj] == '\0')
			{
				if (n <= sq_info->size)
					return (0);
				sq_info->x = sq_info->i;
				sq_info->y = sq_info->j;
				sq_info->size = n;
				printf("size: %d | x: %d | y: %d\n", sq_info->size, sq_info->x, sq_info->y);
			}
			cj--;
		}
		n++;
	}
	return (0);
}

t_square_info	find_square(char **map)
{
	t_square_info	sq_info;

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
			sq_info.j = sq_info.j + 1;
		}
		sq_info.i = sq_info.i + 1;
	}
	return (sq_info);
}
