/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:45:09 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/18 15:20:52 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	dlen = 0;
	slen = 0;
	while (dest[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (dlen >= size)
		return (slen + size);
	while (src[i] && i + dlen < size - 1)
	{
		dest[i + dlen] = src[i];
		i++;
	}
	dest[i + dlen] = 0;
	return (dlen + slen);
}
