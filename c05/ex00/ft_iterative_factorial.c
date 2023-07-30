/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:39:32 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/20 00:04:23 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (i <= nb)
	{
		res *= i;
		i++;
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_factorial(5));
}*/
