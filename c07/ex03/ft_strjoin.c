/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:02:45 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/27 18:37:01 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)

{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		full_len;
	char	*res;

	i = 0;
	full_len = 0;
	while (i < size)
		full_len += ft_strlen(strs[i++]);
	full_len += (size - 1) * ft_strlen(sep);
	res = malloc((full_len + 1) * sizeof(char));
	res[0] = 0;
	if (size == 0)
		return (res);
	i = 0;
	while (i < size)
	{
		res = ft_strcat(res, strs[i]);
		if (i != size - 1)
			res = ft_strcat(res, sep);
		i++;
	}
	res[full_len] = 0;
	return (res);
}

/*#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	printf("./ex03/output___said___this___is___a___success :\n");
	printf("%s\n", ft_strjoin(argc, argv, "___"));
}*/
