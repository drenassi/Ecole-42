/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:20:59 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/23 18:24:21 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/* Function which returns 1 if tab is a valid solution, and 0 if not */
int	ft_is_solution(int tab[4][4], int *input)
{
	if (ft_is_valid_top_view(tab, input))
	{
		if (ft_is_valid_bottom_view(tab, input))
		{
			if (ft_is_valid_left_view(tab, input))
			{
				if (ft_is_valid_right_view(tab, input))
					return (1);
			}
		}
	}
	return (0);
}

/* Function to check if the top view is valid */
int	ft_is_valid_top_view(int tab[4][4], int *input)
{
	int	i;
	int	j;
	int	col_heights[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			col_heights[j] = tab[j][i];
			j++;
		}
		if (ft_count_visible(col_heights) != input[i])
			return (0);
		i++;
	}
	return (1);
}

/* Function to check if the bottom view is valid */
int	ft_is_valid_bottom_view(int tab[4][4], int *input)
{
	int	i;
	int	j;
	int	col_heights[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			col_heights[j] = tab[3 - j][i];
			j++;
		}
		if (ft_count_visible(col_heights) != input[i + 4])
			return (0);
		i++;
	}
	return (1);
}

/* Function to check if the left view is valid */
int	ft_is_valid_left_view(int tab[4][4], int *input)
{
	int	i;
	int	j;
	int	row_heights[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			row_heights[j] = tab[i][j];
			j++;
		}
		if (ft_count_visible(row_heights) != input[i + 8])
			return (0);
		i++;
	}
	return (1);
}

/* Function to check if the right view is valid */
int	ft_is_valid_right_view(int tab[4][4], int *input)
{
	int	i;
	int	j;
	int	row_heights[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			row_heights[j] = tab[i][3 - j];
			j++;
		}
		if (ft_count_visible(row_heights) != input[i + 12])
			return (0);
		i++;
	}
	return (1);
}
