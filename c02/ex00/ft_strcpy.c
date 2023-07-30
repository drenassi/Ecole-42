/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:54:35 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/15 20:06:08 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i])
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	(void)	ac;
	ft_strcpy(av[1], av[2]);
	printf("%s\n", av[1]);
}*/
