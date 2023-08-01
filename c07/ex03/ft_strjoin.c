/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:02:45 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/31 15:44:00 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_strlen(char *str)
{
        int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

int     get_malloc_size(int size, char **strs, char *sep)
{
        int     i;
        int     res;

        if (size == 0)
                return (1);
        i = 0;
        res = 0;
        while (i < size)
                res += ft_strlen(strs[i++]);
        res += ft_strlen(sep) * (size - 1);
        return (res + 1);
}

char    *ft_strcat(char *dest, char *src)
{
        int     i;
        int     destlen;

        i = 0;
        destlen = ft_strlen(dest);
        while (src[i])
        {
                dest[destlen + i] = src[i];
                i++;
        }
        dest[destlen + i] = 0;
        return (dest);
}

char    *ft_strjoin(int size, char **strs, char *sep)
{
        char    *res;
        int             i;

        res = malloc(get_malloc_size(size, strs, sep) * sizeof(char));
        if (!res)
                return (NULL);
        res[0] = 0;
        if (size == 0)
                return (res);
        i = 0;
        while (i < size)
        {
                ft_strcat(res, strs[i]);
                if (i != size - 1)
                        ft_strcat(res, sep);
                i++;
        }
        res[ft_strlen(res)] = 0;
        return (res);
}

/*#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	(void) argc;
	printf("./ex03/output___said___this___is___a___success :\n");
	printf("%s\n", ft_strjoin(0, argv, "___"));
}*/
