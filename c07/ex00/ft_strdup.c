/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:12:41 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/25 12:42:20 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

char *ft_strdup(char *src);

int	main(void)
{
	printf("%s\n", strcmp(strdup(""), ft_strdup("")) == 0 ?
			"OK" :
			"Fail");
	printf("%s\n", strcmp(strdup("484df41"), ft_strdup("484df41")) == 0 ?
			"OK" :
			"Fail");
}*/
