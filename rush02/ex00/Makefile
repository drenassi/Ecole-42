# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drenassi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 20:14:55 by drenassi          #+#    #+#              #
#    Updated: 2023/07/30 20:25:57 by drenassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c check.c display.c convert.c ft_putstr.c ft_split.c ft_strlen.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
