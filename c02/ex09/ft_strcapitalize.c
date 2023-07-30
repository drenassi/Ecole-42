/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:08:20 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/15 23:43:23 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_low(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_is_up(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_is_alpha(char c)
{
	if (ft_is_low(c) || ft_is_up(c))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_up(str[i]))
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
	if (ft_is_low(str[0]))
		str[0] = str[0] - 'a' + 'A';
	i = 1;
	while (str[i])
	{
		if (!ft_is_num(str[i - 1]) && !ft_is_alpha(str[i - 1]))
			if (ft_is_low(str[i]))
				str[i] = str[i] - 'a' + 'A';
		i++;
	}
	return (str);
}

/*#include <stdio.h>

int	main(int ac, char **av)
{
	(void) ac;
	printf("%s\n", ft_strcapitalize(av[1]));
}*/
