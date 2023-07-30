/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:52:44 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/16 17:19:39 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int x, int y)
{
	int	l;
	int	c;

	l = 1;
	while (l <= y)
	{
		c = 1;
		while (c <= x)
		{
			if ((l == 1 && c == 1) || (l == y && c == 1))
				ft_putchar('A');
			else if ((l == 1 && c == x) || (l == y && c == x))
				ft_putchar('C');
			else if ((l == 1 || l == y) && c > 1 && c < x)
				ft_putchar('B');
			else if ((c == 1 || c == x) && l > 1 && l < y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
		ft_print(x, y);
	else
		write(1, "Error: Negative or null parameters!\n", 36);
}
