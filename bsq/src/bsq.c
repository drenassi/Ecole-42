/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:42:31 by rbryento          #+#    #+#             */
/*   Updated: 2023/08/01 17:58:10 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

int	bsq(int ac, char *av[])
{
	char			**map;
	t_square_info	sq_info;

	if (ac != 2)
	{
		ft_putstr("args error\n");
		return (1);
	}
	map = create_map(av[1]);
	if (!map)
	{
		ft_putstr("map error\n");
		return (1);
	}
	sq_info = find_square(map);
	print_map(map, sq_info);
	free(map);
	return (0);
}
