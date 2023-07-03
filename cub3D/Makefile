# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:41:51 by mvicente          #+#    #+#              #
#    Updated: 2023/06/29 15:26:07 by mvicente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## 		   NAMES 		##########

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MLX_PATH	= ./inc/minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

SRC = ./src/main.c ./src/events.c ./src/math.c ./src/picture.c
OBJ = $(SRC:.c=.o)
LDLIBS = -g -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm

########## 		   TARGETS 		##########

all:	$(MLX) $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
	
$(MLX):
	make -sC $(MLX_PATH)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(LDLIBS) $(MLX) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

norm:
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c
	@norminette -R CheckDefine cub3D.h

.SILENT: ${OBJ} clean fclean

.PHONY: all clean fclean re norm

########## 		   COLORS 		##########

GREEN		=	\033[0;32m
YELLOW	=	\033[0;33m
RED		=	\033[0;31m
BLUE_PISK		=	\033[0;34;5;199m
BLUE		=	\033[0;36m
VIOLET	=	\033[0;38;5;199m
RESET		=	\033[0m