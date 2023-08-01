/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:39:11 by rbryento          #+#    #+#             */
/*   Updated: 2023/08/01 18:05:32 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_square_info
{
	int		x;
	int		y;
	int		size;
	int		i;
	int		j;
	char	full;
	char	obstacle;
}	t_square_info;

/* LIB_FT */

char			**ft_split(char *s, char *c);
int				ft_atoi(char *str);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_linelen(char *str);
void			ft_free(char **strs, int j);

/* FILE MANAGEMENT */

char			**file_to_str(char *filename);

/* BSQ FUNCTIONS */

int				bsq(int ac, char *av[]);
t_square_info	find_square(char **map);
char			**create_map(char *filename);
int				check_map(char *map);
void			print_map(char **map, t_square_info sq_info);

#endif /* BSQ_H */