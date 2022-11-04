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

NAME = so_long

LIBFT_PATH = ./src/libft

SRCS		+= $(addprefix src/, so_long.c check_params.c  gen_player.c  movement_parser.c)
SRCS		+= $(addprefix src/, gen_grid.c gen_window.c check_file_extension.c print_grid.c)
SRCS		+= $(addprefix src/, check_map.c print_utils.c)

CC =		clang
CFLAGS =	-Wall -Wextra -Werror
DB_CFLAGS =	-Wall -Wextra -Werror -g


# A way to make it work on both linux and macos (I hope so.)
OS = $(shell uname)
ifeq ($(OS), Linux)
    #----------------------------------------------------#
    #--------------------$(LINUX)------------------------#
    #----------------------------------------------------#
    MLX_PATH = ./src/minilibx-linux
    #====================================================#
    #===-================DOWNLOADLIB=====================#
    #====================================================#
    ifeq (, $(shell ls ./src/minilibx-linux 2>/dev/null))   # Checks if libfiles already exists for not downloading multiple times, and supress the error message
        $(shell curl https://projects.intra.42.fr/uploads/document/document/12389/minilibx-linux.tgz -o ./src/minilibx.tgz 2>/dev/null)     # Download the lib + Supress
        $(shell tar -xf ./src/minilibx.tgz -C ./src/ )                                                                                      # Extract it
        $(shell rm -f ./src/minilibx.tgz)                                                                                      # Extract it
    endif
    #---------------------------------------------------#
    #--------------------MACOS-FLAGS--------------------#
    #---------------------------------------------------#
    LIBFT = $(LIBFT_PATH)/libft.a
    MLX = $(MLX_PATH)/libmlx.a
    MLX_FLAGS = -L$(MLX) -lXext -lX11

    else # MacOS... If you run this on windows it's your own problem. At least use wsl you c*nt
    #----------------------------------------------------#
    #--------------------$(MACOS)------------------------#
    #----------------------------------------------------#
    MLX_PATH = ./src/minilibx
    #====================================================#
    #===-================DOWNLOADLIB=====================#
    #====================================================#
    ifeq (, $(shell ls ./src/minilibx_opengl_20191021 2>/dev/null))   ## Checks if file already exist for not downloading multiple times, and supress the error message.
        $(shell curl https://projects.intra.42.fr/uploads/document/document/12390/minilibx_opengl.tgz ./src/minilibx.tgz )      # Download the lib + Supress
        $(shell tar -xf ./src/minilibx.tgz -C ./src/ )                                                                          # Extract it
        $(shell rm -f ./src/minilibx.tgz)                                                                                      # Extract it
    endif

    #---------------------------------------------------#
    #--------------------MACOS-FLAGS--------------------#
    #---------------------------------------------------#
    LIBFT = $(LIBFT_PATH)/libft.a
    MLX = $(MLX_PATH)/libmlx.a
    MLX_FLAGS = -L$(MLX) -lmlx -framework OpenGL -framework AppKit
endif
#----------------------------------------------------#
#---------------Alright, good to go.-----------------#
#----------------------------------------------------#

all:		$(NAME)

debug:
	$(CC) $(DB_CFLAGS) $(MLX_FLAGS) $(SRCS) $(LIBFT) $(MLX) -o so_long

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

run: $(NAME)
	./so_long map.ber

.PHONY:		all clean fclean re
