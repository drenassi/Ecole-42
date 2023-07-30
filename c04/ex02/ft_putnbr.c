/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:33:05 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/17 17:34:35 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr0(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
		write(1, "-", 1);
	if (nb == -2147483648)
		write(1, "2147483648", 10);
}

int	ft_len(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_print(int nb, int len)
{
	int		n;
	int		i;
	int		j;
	char	c;

	j = 0;
	while (j < len)
	{
		n = nb;
		i = 1;
		while (i < len - j)
		{
			n = n / 10;
			i++;
		}
		c = n % 10 + '0';
		write(1, &c, 1);
		j++;
	}
}

void	ft_putnbr(int nb)
{
	int	len;

	ft_putnbr0(nb);
	if (nb < 0)
		nb = -nb;
	len = ft_len(nb);
	if (nb != -2147483648 && nb != 0)
	{
		ft_print(nb, len);
	}
}
