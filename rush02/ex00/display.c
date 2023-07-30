/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:16:28 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/30 19:26:28 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* Display the full number */
void	ft_display(char *input, char **dict)
{
	char	**number;
	int		size;
	int		i;
	int		j;

	number = ft_get_number(input);
	size = ft_tablen(number);
	i = -1;
	while (++i < size)
	{
		ft_display_100(number[i], dict);
		if (i != size - 1 && ft_cond2(number[i]))
			ft_putstr(" ");
		j = -1;
		while (dict[++j])
		{
			if (ft_cond1(size, dict, i, j) && ft_cond2(number[i]))
			{
				ft_putstr(dict[j + 1]);
				ft_putstr(" ");
			}
		}
	}
	ft_free(number);
	ft_putstr("\n");
}

/* Convert input into arrays[4] */
char	**ft_get_number(char *input)
{
	char	**number;
	int		i;
	int		j;
	int		n;
	int		len;

	len = ft_strlen(input);
	n = len / 3;
	if (len % 3)
		n++;
	number = malloc((n + 1) * sizeof(char *));
	i = n;
	number[i] = NULL;
	while (--i >= 0)
	{
		number[i] = malloc(4 * sizeof(char));
		j = 3;
		number[i][3] = 0;
		while (--j >= 0 && input[--len])
			number[i][j] = input[len];
		while (j > 0)
			number[i][j--] = '0';
	}
	return (number);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_get_dict_content(char *path)
{
	int		fd;
	int		size;
	char	readbuffer[1];
	char	*buffer;

	size = 0;
	fd = open(path, O_RDONLY);
	readbuffer[0] = 0;
	if (fd == -1)
	{
		ft_putstr_error("Error: Can't read dictionary file. ");
		ft_putstr_error("Make sure you have a correct file!\n");
		return (NULL);
	}
	while (read(fd, readbuffer, 1))
		size++;
	close(fd);
	fd = open(path, O_RDONLY);
	buffer = malloc((size + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read(fd, buffer, size);
	close(fd);
	buffer[size] = 0;
	return (ft_split(buffer, " :\n"));
}
