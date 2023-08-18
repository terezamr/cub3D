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
		$(SRC_PATH)moves.c \
		$(SRC_PATH)math.c \
		$(SRC_PATH)distance.c \
		$(SRC_PATH)picture.c \
		$(SRC_PATH)picture_aux.c \
		$(SRC_PATH)error_msg.c \
		$(SRC_PATH)parse.c \
		$(SRC_PATH)check.c \
		$(SRC_PATH)check_map.c \
		$(SRC_PATH)utils.c

OBJ = $(SRC:.c=.o)
LDLIBS = -g -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
LEAKS_FLAG = -g -fsanitize=address
C_FLAGS = -Wall -Wextra -Werror

########## 		   LIBFT 		##########

LIBFT = libft

LIBFT_PATH = ./inc/libft/

MAKE_LIBFT = cd ${LIBFT_PATH} && make all

CLEAN_LIBFT = cd ${LIBFT_PATH} && make clean

FCLEAN_LIBFT = cd ${LIBFT_PATH} && make fclean

########## 		   MESSAGES 		##########

NORM_LIBFT_MSG = @echo "\n[ $(YELLOW)Norm $(LIBFT)$(RESET) ]\n"

NORM_PROJ_MSG = @echo "\n[ $(YELLOW)Norm $(NAME)$(RESET) ]\n"

NORM_CORRECT = @echo "\nNorminette: [$(GREEN)OK$(RESET)]\n"

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
	$(CC) $(C_FLAGS) $(LEAKS_FLAG) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "$(YELLOW)compiling $<...$(RESET)"
	
$(MLX):
	make -sC $(MLX_PATH)

$(NAME):	$(OBJ)
			${MAKE_LIBFT} -s
			$(CC) $(OBJ) $(MLX) $(LEAKS_FLAG) -o $(NAME) -L $(LIBFT_PATH) -lft $(LDLIBS) 

clean:	
	${CLEAN_LIBFT} -s
	$(RM) $(OBJ)

fclean:	clean
	${FCLEAN_LIBFT} -s
	$(RM) $(NAME)
	@echo "<====== $(RED)$(NAME) removed $(RESET) ======>"

re:	fclean all

norm:
	${NORM_LIBFT_MSG}
	@cd ${LIBFT_PATH} && make norm
	${NORM_PROJ_MSG}
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c
	@cd ./inc && norminette -R CheckDefine *.h
	${NORM_CORRECT}

.SILENT: ${NAME} $(OBJ) clean fclean

.PHONY: all clean fclean re norm