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

SRC_PATH = ./src/

SRC = 	$(SRC_PATH)main.c \
		$(SRC_PATH)events.c \
		$(SRC_PATH)math.c \
		$(SRC_PATH)picture.c \

OBJ = $(SRC:.c=.o)
LDLIBS = -g -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm

########## 		   COLORS 		##########

GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
BLUE_PISK	=	\033[0;34;5;199m
BLUE		=	\033[0;36m
VIOLET		=	\033[0;38;5;199m
RESET		=	\033[0m

########## 		   TARGETS 		##########

all:	$(MLX) $(NAME)
	@echo "<====== $(GREEN)$(NAME) created $(RESET) ======>"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "$(YELLOW)compiling $<...$(RESET)"
	
$(MLX):
	make -sC $(MLX_PATH)

# NO $(NAME):
#
# DÁ ME ERRO ASSIM (como tinhas): 
#       $(CC) $(OBJ) $(LDLIBS) $(MLX) -o $(NAME) 
#
# CONSIGO COMPILAR ASSIM: 
#       $(CC) $(OBJ) $(MLX) -o $(NAME) $(LDLIBS)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(LDLIBS) $(MLX) -o $(NAME) 

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)
	@echo "<====== $(RED)$(NAME) removed $(RESET) ======>"

re:	fclean all

norm:
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c
	@norminette -R CheckDefine cub3D.h

.SILENT: ${NAME} $(OBJ) clean fclean

.PHONY: all clean fclean re norm