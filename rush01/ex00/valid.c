/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:57:35 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/23 18:19:21 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/* Function which converts the input into an int array */
void	ft_input(char *str, int *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			tab[j] = str[i] - '0';
			j++;
		}
		i++;
	}
}

/* Function to print errors */
void	ft_print_error(void)
{
	write(2, "Error\n", 6);
}

/* Function which verifies if the input format is valid */
int	ft_is_valid_str(char *str)
{
	int	i;
	int	strlen;

	i = 0;
	strlen = 0;
	while (str[strlen])
		strlen++;
	if (strlen != 31)
		return (0);
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))
			return (0);
		if (i % 2 == 1 && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_visible(int *heights)
{
	int	visible;
	int	max_height;
	int	i;

	visible = 1;
	max_height = heights[0];
	i = 1;
	while (i < 4)
	{
		if (heights[i] > max_height)
		{
			max_height = heights[i];
			visible++;
		}
		i++;
	}
	return (visible);
}
