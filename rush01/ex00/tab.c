/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:59:46 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/23 18:46:41 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* Function that creates a double array of int and fills it with 0 */
void	ft_init_tab(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

/* Function which checks each line and each column to keep 1 number of each */
int	ft_is_safe(int tab[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[row][i] == num || tab[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

/* Function that generates 4x4 latin squares, then tries the solutions */
int	tab_gen(int tab[4][4], int row, int col, int *input)
{
	int	num;

	num = 1;
	if (row == 4)
	{
		if (ft_is_solution(tab, input))
		{
			ft_print(tab);
			return (1);
		}
	}
	if (col == 4)
		return (tab_gen(tab, row + 1, 0, input));
	while (num <= 4)
	{
		if (ft_is_safe(tab, row, col, num))
		{
			tab[row][col] = num;
			if (tab_gen(tab, row, col + 1, input))
				return (1);
			tab[row][col] = 0;
		}
		num++;
	}
	return (0);
}

/* Function to print a double array of int */
void	ft_print(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(tab[i][j] + '0');
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
