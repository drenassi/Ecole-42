/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:44:10 by rbryento          #+#    #+#             */
/*   Updated: 2023/08/01 17:59:45 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

char	**create_map(char *filename)
{
	char	**map;

	map = file_to_str(filename);
	if (!map)
		return (NULL);
	return (map);
}
