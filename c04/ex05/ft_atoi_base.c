/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:00:33 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/19 16:37:06 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
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

int	ft_pos_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (!ft_is_valid_base(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_pos_in_base(str[i], base) >= 0)
	{
		res = res * ft_strlen(base) + ft_pos_in_base(str[i], base);
		i++;
	}
	return (res * sign);
}

/*#include <stdio.h>

int	main(void)
{
	printf("-30:%d\n", ft_atoi_base("    ++--+-1E", "0123456789ABCDEF"));
}*/
