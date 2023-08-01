/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reuban <reuban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:47:05 by reuban            #+#    #+#             */
/*   Updated: 2023/07/29 20:00:16 by reuban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <stdio.h>

static int	is_in_str(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_substr(char *s, int c, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s[c];
		i++;
		c++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_count_word(char *s, char *c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (is_in_str(s[i], c) == 0)
		{
			word++;
			while (is_in_str(s[i], c) == 0 && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char *s, char *c, int i)
{
	int	size;

	size = 0;
	while (is_in_str(s[i], c) == 0 && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char *s, char *c)
{
	int		i;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	strs = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < ft_count_word(s, c))
	{
		while (is_in_str(s[i], c))
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = 0;
	return (strs);
}
