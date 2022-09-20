# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 20:21:22 by lguedes           #+#    #+#              #
#    Updated: 2022/08/24 22:18:17 by lguedes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_PATH = ./src/libft
MLX_PATH = ./src/minilibx

LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx_Linux.a

SRCS		+= so_long.c check_params.c  gen_player.c  movement_parser.c
SRCS		+= gen_grid.c gen_window.c check_file_extension.c

CC =		clang
CFLAGS =	-Wall -Wextra -Werror


# A way to make it work on both linux and macos (I hope so.)
OS = $(shell uname)
ifeq ($(OS), Linux)
MLX_FLAGS =	-L$(MLX) -lXext -lX11
else
MLX_FLAGS =	-L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
endif

all:		$(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH)

$(MLX):
		$(MAKE) -C $(MLX_PATH)

$(NAME):	$(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRCS) $(LIBFT) $(MLX) -o so_long

clean:
			@$(MAKE) -C $(LIBFT_PATH) clean
			@$(MAKE) -C $(MLX_PATH) clean

fclean:		clean
			@$(MAKE) -C $(LIBFT_PATH) fclean
			@$(MAKE) -C $(MLX_PATH) clean
			@rm -rf fractol
			@rm -rf $(MLX)

re:			fclean all

.PHONY:		all clean fclean re
