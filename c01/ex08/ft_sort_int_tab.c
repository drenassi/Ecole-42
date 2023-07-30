/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:40:15 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/18 11:37:16 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	count;

	count = 0;
	while (count < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i + 1] < tab[i])
				ft_swap(&tab[i + 1], &tab[i]);
			i++;
		}
		count++;
	}
}

/*#include <stdio.h>

int	main(void)
{
	int	i;
	int	tab[11] = {12, -57, 42, 11, -2, 6, -88, 1, 13, 29, 64};
	ft_sort_int_tab(tab, 11);

	i = 0;
	while (i < 11)
	{
		printf("%d\n", tab[i++]);
	}
}*/
