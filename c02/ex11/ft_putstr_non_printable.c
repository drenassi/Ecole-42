/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:10:03 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/16 15:51:13 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	if (c < ' ' || c > '~')
		return (0);
	else
		return (1);
}

void	ft_print_hexa(char c)
{
	char	a;
	char	b;

	if (c / 16 < 10)
		a = c / 16 + '0';
	else
		a = c / 16 - 10 + 'a';
	if (c % 16 < 10)
		b = c % 16 + '0';
	else
		b = c % 16 - 10 + 'a';
	ft_putchar('\\');
	ft_putchar(a);
	ft_putchar(b);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_printable(str[i]))
			ft_putchar(str[i]);
		else
		{
			ft_print_hexa(str[i]);
		}
		i++;
	}
}

/*int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	return (0);
}*/
