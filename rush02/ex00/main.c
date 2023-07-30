/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:21:39 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/30 19:37:44 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (i < ft_tablen(tab))
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_is_valid_argc(int ac)
{
	if (ac < 2)
	{
		ft_putstr_error("Error: Too few arguments... ");
		ft_putstr_error("You need to use at least one.\n");
		return (0);
	}
	if (ac > 3)
	{
		ft_putstr_error("Error: Too much arguments... ");
		ft_putstr_error("You need to use 2 arguments max.\n");
		return (0);
	}
	return (1);
}

int	ft_is_valid_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr_error("Error: Invalid input. ");
			ft_putstr_error("Make sure you entered a positive number!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**dict;

	if (!ft_is_valid_argc(ac))
		return (-1);
	if ((ac == 2 && !ft_is_valid_argv(av[1]))
		|| (ac == 3 && !ft_is_valid_argv(av[2])))
		return (-1);
	if (ac == 2)
	{
		dict = ft_get_dict_content("numbers.dict");
		if (!ft_check_dict(dict))
			return (-1);
		ft_display(av[1], dict);
	}
	if (ac == 3)
	{
		dict = ft_get_dict_content(av[1]);
		if (!ft_check_dict(dict))
			return (-1);
		ft_display(av[2], dict);
	}
	ft_free(dict);
	return (0);
}
