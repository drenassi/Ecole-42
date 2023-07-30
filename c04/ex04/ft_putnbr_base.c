/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:47:10 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/20 17:10:11 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	while (base[i])
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < ' ' || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[j] == base[i] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	n;
	int			baselen;

	n = (long int) nbr;
	baselen = ft_strlen(base);
	if (!ft_is_valid_base(base))
		return ;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n / baselen != 0)
		ft_putnbr_base(n / baselen, base);
	ft_putchar(base[n % baselen]);
}

/*#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int		main(void)
{
	write(1, ":", 1);
	ft_putnbr_base(-2147483648, "01");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "\t0123456789abcdef");
}*/
