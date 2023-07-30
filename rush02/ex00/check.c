/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:18:22 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/30 19:23:02 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_cond1(int size, char **dict, int i, int j)
{
	if (i != size - 1 && ft_strlen(dict[j]) == (1 + (size - 1 - i) * 3))
	{
		if (dict[j + 1][0] < '0' || dict[j + 1][0] > '9')
		{
			return (1);
		}
	}
	return (0);
}

int	ft_cond2(char *number)
{
	if (number[0] != '0' || number[1] != '0' || number[2] != '0')
		return (1);
	return (0);
}

int	ft_check_dict(char **dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i])
	{
		j = 0;
		while (dict[i][j])
		{
			if (!(dict[i][j] >= '0' && dict[i][j] <= '9')
				&& !(dict[i][j] >= 'a' && dict[i][j] <= 'z')
				&& !(dict[i][j] >= 'A' && dict[i][j] <= 'Z'))
			{
				ft_putstr_error("Error: Invalid dictionary.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putstr_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}
