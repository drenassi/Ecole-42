/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:48:58 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/12 16:03:56 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int i, int j)
{
	char	c;

	c = i / 10 + '0';
	write(1, &c, 1);
	c = i % 10 + '0';
	write(1, &c, 1);
	write(1, " ", 1);
	c = j / 10 + '0';
	write(1, &c, 1);
	c = j % 10 + '0';
	write(1, &c, 1);
	if (i != 98 || j != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 99)
	{
		j = 0;
		while (j < 100)
		{
			if (j > i)
				ft_print(i, j);
			j++;
		}
		i++;
	}
}
