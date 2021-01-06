# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 15:20:17 by thoberth          #+#    #+#              #
#    Updated: 2021/01/05 12:00:11 by thoberth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c	\
			$(wildcard lib/*.c)

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

MLXFLAG	=	-lmlx -framework OpenGL -framework AppKit -lz

MLXPATH	=	minilibx/

HDR		=	lib/libcub.h

NAME	=	libcub.a

NAMEMLX	=	libmlx.dylib

RM		=	rm -f

ARRC	=	ar rcs ${NAME}

EXEC	=	cub3D

${EXEC} : ${NAME} ${NAMEMLX}
	${CC} -o $@ $^ ${MLXFLAG}

${NAME} : ${OBJS}
	${ARRC} ${OBJS}

${NAMEMLX} :
	cd ${MLXPATH} ; make ; cp ${NAMEMLX} ../ ; cd ..


all: ${EXEC}

%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@

clean:
	${RM} ${OBJS} ; cd ${MLXPATH} ; make clean ; cd ../

fclean: clean
	${RM} ${NAME} ${NAMEMLX} ${EXEC}

re: fclean all

.PHONY:		all		clean	fclean	re