/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:48:57 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/27 13:59:29 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	*range = malloc((max - min) * sizeof(int));
	if (!*range)
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	int	i;
	int	*range;

	i = 0;
	printf("%d\n", ft_ultimate_range(&range, 3, 10));
	while (i < 7)
	{
		printf("%d\n", range[i]);
		i++;
	}
	
}*/
