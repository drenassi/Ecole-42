/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:52:44 by drenassi          #+#    #+#             */
/*   Updated: 2023/08/01 10:43:59 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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

	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
		write(1, "-", 1);
	if (nb == -2147483648)
		write(1, "2147483648", 10);
	if (nb < 0)
		nb = -nb;
	len = ft_len(nb);
	if (nb != -2147483648 && nb != 0)
	{
		ft_print(nb, len);
	}
}

void ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}