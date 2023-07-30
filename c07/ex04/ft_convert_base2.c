/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:06:56 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/27 21:07:34 by drenassi         ###   ########.fr       */
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

int	ft_nbrlen(int nbr, char *base)
{
	int	i;
	int	baselen;

	i = 0;
	baselen = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr / baselen > 0)
	{
		nbr /= baselen;
		i++;
	}
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
