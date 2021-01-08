# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 15:20:17 by thoberth          #+#    #+#              #
#    Updated: 2020/12/28 13:20:04 by thoberth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c	\
			$(wildcard lib/*.c)

OBJS	=	${SRCS:.c=.o}  

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

MLXFLAG	=	-lm -lbsd -L minilibx/ -lmlx -lXext -lX11

MLXPATH	=	minilibx

HDR		=	lib/libcub.h

NAME	=	libcub.a

NAMEMLX	=	libmlx.a

RM		=	rm -f

ARRC	=	ar rcs ${NAME}

EXEC	=	cub3D

${EXEC} : ${NAME} ${NAMEMLX}
	${CC} -o $@ $^ ${MLXFLAG}

${NAME} : ${OBJS}
	${ARRC} ${OBJS}

${NAMEMLX} :
	cd ${MLXPATH} ; make ; cp ${NAMEMLX} ../ ; cd ..

%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@

all: ${EXEC}

clean:
	${RM} ${OBJS} ${NAME} ${NAMEMLX} ; cd ${MLXPATH} ; make clean ; cd ..

fclean: clean
	${RM} ${EXEC}

re: fclean all

.PHONY:		all		clean	fclean	re