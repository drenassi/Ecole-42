/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:59:24 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/12 15:58:10 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int i, int j, int k)
{
	char	a;
	char	b;
	char	c;

	a = i + '0';
	b = j + '0';
	c = k + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (i != 7 || j != 8 || k != 9)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 9)
		{
			k = 0;
			while (k < 10)
			{
				if (k > j && j > i)
					ft_print(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
