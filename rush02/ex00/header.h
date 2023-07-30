/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:06:30 by drenassi          #+#    #+#             */
/*   Updated: 2023/07/30 19:28:09 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

void	ft_putstr_error(char *str);
char	**ft_split(char *str, char *charset);
char	**ft_get_dict_content(char *path);
int		ft_is_valid_argc(int ac);
int		ft_is_valid_argv(char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_hundreds(char *input, char **dict);
void	ft_tens(char *input, char **dict);
void	ft_units(char *input, char **dict);
void	ft_display_100(char *input, char **dict);
void	ft_display(char *input, char **dict);
char	**ft_get_number(char *input);
int		ft_tablen(char **tab);
int		ft_cond1(int size, char **dict, int i, int j);
int		ft_cond2(char *number);
void	ft_free(char **tab);
int		ft_check_dict(char **dict);

#endif
