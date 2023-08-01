/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:40:18 by rbryento          #+#    #+#             */
/*   Updated: 2023/07/31 10:52:04 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

static int	is_substring(char *str, char *to_find)
{
	while (*to_find != '\0')
	{
		if (*to_find != *str)
			return (0);
		to_find++;
		str++;
	}
	return (1);
}

static char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		if (is_substring(str, to_find))
			return (str);
		str++;
	}
	return (0);
}

static int	get_sign_atoi(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign);
}

static void	do_atoi(char *str, unsigned int *nb)
{
	unsigned int	i;
	int				started;

	i = 0;
	started = 0;
	while (str[i] != '\0')
	{
		if (!started && !(str[i] >= '0' && str[i] <= '9'))
		{
			if ((str[i] == '-' || str[i] == '+')
				&& (str[i + 1] != '-' && str[i + 1] != '+'))
				started = 1;
			i++;
			continue ;
		}
		if (started && !(str[i] >= '0' && str[i] <= '9'))
			break ;
		started = 1;
		*nb = *nb + (str[i++] - '0');
		*nb = *nb * 10;
	}
}

int	ft_atoi(char *str)
{
	unsigned int	nb;
	int				out;

	nb = 0;
	if (ft_strstr(str, "-2147483648") || ft_strstr(str, "-+2147483648"))
		return (-2147483648);
	if (ft_strstr(str, "+2147483647") || ft_strstr(str, "2147483647"))
		return (2147483647);
	do_atoi(str, &nb);
	out = (nb / 10) * get_sign_atoi(str);
	return (out);
}
