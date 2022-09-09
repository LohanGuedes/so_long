#ifndef FRACTOL_H_
# define FRACTOL_H_

# include "./src/minilibx/mlx.h"
# include "./src/libft/src/libft.h"
# include <stdio.h>

# define ERR_MSG_WRONG_NUM_ARG "So_long \033[31mERROR\e[0m: Wrong number of arguments\n"
# define USAGE_MSG_EXEC "\033[32mUsage: ./so_long <path_to_map>.ber\e[0m\n"

//w 119 a 97 s 115 d 100 esc 65509
enum {
	UP = 119 | 188,
	DOWN =
}

typedef struct s_window
{
	void	*ptr;
	char*	title;
	int	height;
	int	width;

} t_window;

typedef struct s_player
{
	int		x;
	int		y;
	void	*img;

} t_player;

typedef struct s_enemie
{
	int		x;
	int		y;
	void	*img;

} t_enemie;

typedef struct s_map_assets
{
	void	*floor;
	void	*door[2];
	void	*wall;

} t_map_assets;

#endif
