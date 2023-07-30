/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:58:17 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/23 18:07:15 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/* Main function */
int	main(int argc, char **argv)
{
	int	tab[4][4];
	int	input[16];
	int	i;

	i = 0;
	ft_init_tab(tab);
	if (argc != 2 || !ft_is_valid_str(argv[1]))
	{
		ft_print_error();
		return (-1);
	}
	ft_input(argv[1], input);
	if (!tab_gen(tab, 0, 0, input))
	{
		ft_print_error();
		return (-1);
	}
	return (0);
}
