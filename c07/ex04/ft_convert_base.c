/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:55:17 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/27 21:16:48 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
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

char	*ft_itoa_base(int nbr, char *base)
{
	long int	n;
	int			baselen;
	int			i;
	char		*res;

	n = (long int) nbr;
	baselen = ft_strlen(base);
	res = malloc((ft_nbrlen(nbr, base) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	i = ft_nbrlen(nbr, base);
	res[i] = 0;
	while (n / baselen > 0)
	{
		res[--i] = base[n % baselen];
		n /= baselen;
	}
	res[--i] = base[n % baselen];
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		i;

	res = "";
	i = 0;
	if (!ft_is_valid_base(base_from) || !ft_is_valid_base(base_to))
		return (res);
	i = ft_atoi_base(nbr, base_from);
	res = ft_itoa_base(i, base_to);
	return (res);
}

/*#include <stdio.h>

int	main(void)
{
	printf("ft_itoa_base = -45054 : %s\n",
		ft_itoa_base(-18988, "01234567"));
	printf("ft_atoi_base = -18988 : %d\n",
		ft_atoi_base("   ++--++-4a2c", "0123456789abcdef"));
	printf("ft_convert_base = -45054 : %s\n",
		ft_convert_base("    ++--++-4a2c", "0123456789abcdef", "01234567"));
}*/
