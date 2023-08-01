/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:45:05 by rbryento          #+#    #+#             */
/*   Updated: 2023/08/01 18:07:10 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	get_file_size(char *filename)
{
	int		fd;
	char	readbuffer[1];
	int		size;

	size = 0;
	fd = open(filename, O_RDONLY);
	readbuffer[0] = 0;
	if (fd == -1)
		return (-1);
	while (read(fd, readbuffer, 1))
		size++;
	close(fd);
	return (size);
}

char	**file_to_str(char *filename)
{
	int		fd;
	int		size;
	char	*buffer;

	size = get_file_size(filename);
	if (size == -1)
		return (NULL);
	fd = open(filename, O_RDONLY);
	buffer = malloc((size + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read(fd, buffer, size);
	close(fd);
	buffer[size] = 0;
	if (check_map(buffer) == 1)
		return (NULL);
	return (ft_split(buffer, "\n"));
}
