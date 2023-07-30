/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:21:29 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/15 22:23:14 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= ' ' && str[i] <= '~')
			i++;
		else
			return (0);
	}
	return (1);
}

/*#include <stdio.h>

int	main(void)
{
	printf("Result : %d", ft_str_is_printable(""));
}*/
