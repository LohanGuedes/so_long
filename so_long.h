#ifndef FRACTOL_H_
# define FRACTOL_H_

# include "./src/minilibx/mlx.h"
# include "./src/libft/src/libft.h"
# include <stdio.h>

# define EM_WRONG_NUM_ARG "So_long \033[31mERROR\e[0m: Wrong number of arguments\n"
# define UM_EXEC "\033[32mUsage: ./so_long <path_to_map>.ber\e[0m\n"

typedef struct s_window
{
	void	*ptr;
	char*	title;
	int	height;
	int	width;

} t_window;

#endif
