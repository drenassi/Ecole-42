/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:56:38 by rbryento          #+#    #+#             */
/*   Updated: 2023/08/01 18:04:59 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	check_lines(char *map)
{
	int	i;
	int	tmp;
	int	line_len;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	if (!map[i])
		return (1);
	i++;
	line_len = ft_linelen(map + i);
	while (map[i])
	{
		tmp = 0;
		while (map[i] && map[i] != '\n')
		{
			i++;
			tmp++;
		}
		if (tmp != line_len && map[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	check_params(char *map, int *char_pos, int *nlines)
{
	int	i;
	int	tmp;

	i = 0;
	*nlines = ft_atoi(map);
	while (map[i] >= '0' && map[i] <= '9')
		i++;
	if (i == 0 || map[i] == '\0' || map[i] == '\n')
		return (1);
	tmp = i;
	while (map[i] && map[i] != '\n')
	{
		if (map[i] < 32 || map[i] > 126)
			return (1);
		if (i == tmp)
			if (map[i] == map[i + 1] || map[i] == map[i + 2]
				|| map[i + 1] == map[i + 2])
				return (1);
		i++;
	}
	if (i - tmp != 3 || map[i] == '\0')
		return (1);
	*char_pos = tmp;
	return (0);
}

static int	check_chars_and_lines(char *map, int char_pos, int nlines)
{
	int	i;

	i = char_pos + 3;
	while (map[i])
	{
		if (map[i] != '\n' && map[i] != map[char_pos]
			&& map[i] != map[char_pos + 1] && map[i] != map[char_pos + 2])
			return (1);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] != '\0')
			nlines--;
		i++;
	}
	if (nlines != 0)
		return (1);
	return (0);
}

int	check_map(char *map)
{
	int	nlines;
	int	char_pos;

	if (!map || map[0] == '\0')
		return (1);
	if (check_lines(map) == 1)
		return (1);
	if (check_params(map, &char_pos, &nlines) == 1)
		return (1);
	if (check_chars_and_lines(map, char_pos, nlines) == 1)
		return (1);
	return (0);
}
