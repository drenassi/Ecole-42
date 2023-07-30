/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:50:41 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/20 11:55:24 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}
