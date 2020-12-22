# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 15:20:17 by thoberth          #+#    #+#              #
#    Updated: 2020/12/22 17:12:30 by thoberth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c	\
			$(wildcard lib/*.c)

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

MLXFLAG	=	-lmlx -framework OpenGL -framework AppKit

MLXPATH	=	minilibx/

HDR		=	lib/libcub.h

NAME	=	libcub.a

NAMEMLX	=	libmlx.dylib

RM		=	rm -f

ARRC	=	ar rcs ${NAME}

EXEC	=	Cub3d

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