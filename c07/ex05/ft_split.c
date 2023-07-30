/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:22:08 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/29 16:25:34 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	char_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_count(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (char_is_in_charset(str[i], charset))
			i++;
		if (!char_is_in_charset(str[i], charset) && str[i])
		{
			count++;
			while (!char_is_in_charset(str[i], charset) && str[i])
				i++;
		}
	}
	return (count);
}

char	*get_next_word(int *index, char *str, char *charset)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	while (char_is_in_charset(str[*index], charset))
		(*index)++;
	while (!char_is_in_charset(str[*index + len], charset) && str[*index + len])
		len++;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i++] = str[*index];
		*index = *index + 1;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = get_count(str, charset);
	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < count)
		res[i++] = get_next_word(&j, str, charset);
	res[i] = 0;
	return (res);
}

/*#include <stdio.h>

int	main(int ac, char **av)
{
	int i = 0;
	(void) ac;
	while (i < 5)
	{
		printf("%s\n", (ft_split(av[1], " ,.?"))[i]);
		i++;
	}
}*/
