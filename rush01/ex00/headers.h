/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:00:54 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/23 18:17:57 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include <unistd.h>

void	ft_print(int tab[4][4]);
int		ft_is_solution(int tab[4][4], int *input);
int		ft_count_visible(int *heights);
int		ft_is_valid_top_view(int tab[4][4], int *input);
int		ft_is_valid_bottom_view(int tab[4][4], int *input);
int		ft_is_valid_left_view(int tab[4][4], int *input);
int		ft_is_valid_right_view(int tab[4][4], int *input); 
void	ft_putchar(char c);
void	ft_init_tab(int tab[4][4]);
int		ft_is_safe(int tab[4][4], int row, int col, int num);
int		tab_gen(int tab[4][4], int row, int col, int *input);
void	ft_input(char *str, int *tab);
void	ft_print_error(void);
int		ft_is_valid_str(char *str);

#endif
