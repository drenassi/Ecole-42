# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drenassi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 09:18:00 by rbryento          #+#    #+#              #
#    Updated: 2023/08/01 16:42:20 by drenassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	src/main.c\
		src/bsq.c\
		src/find_square.c\
		src/lib_ft/ft_split.c\
		src/lib_ft/ft_free.c\
		src/lib_ft/ft_atoi.c\
		src/lib_ft/ft_putstr.c\
		src/lib_ft/ft_strlen.c\
		src/file/file_to_str.c\
		src/map/create_map.c\
		src/map/check_map.c\
		src/map/print_map.c

 
OBJ	=	$(SRC:.c=.o)
 
NAME	=	BSQ
 
CFLAGS	=	-Wall -Wextra -Werror -I./include -fPIE -g3
 
all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

debug:
	gcc -o $(NAME) $(SRC) -I./include -g3
 
clean:
	rm -f $(OBJ)
 
fclean:	clean
	rm -f $(NAME)
 
re:	fclean all
 
.PHONY:	all clean fclean re
