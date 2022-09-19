#ifndef FRACTOL_H_
# define FRACTOL_H_

# include "./src/minilibx/mlx.h"
# include "./src/libft/src/libft.h"
# include <stdio.h>

# define ERR_MSG_WRONG_NUM_ARG "So_long \033[31mERROR\e[0m: Wrong number of arguments\n"
# define USAGE_MSG_EXEC "\033[32mUsage: ./so_long <path_to_map>.ber\e[0m\n"
# define ERR_MSG_FILE "So_long \033[31mERROR\e[0m: wrong file extension. EXPECTED: .ber"

/*
** DEF ASSETS
*/
# define P_ASSET "./Assets/Knight/knight.xpm"
# define C_ASSET "./Assets/Collectable/key.xpm"



//w 119 a 97 s 115 d 100 esc 65509
enum key_pressed{
	Esc = 65509,
	Up = 119,
	Left = 97,
	Down = 115,
	Right = 100,
	A_up = 119,
	A_left = 97,
	A_down = 115,
	A_right = 100,
};

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
	int		moves;
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
	char **grid;
	void	*floor;
	void	*door[2];
	void	*wall;

} t_map_assets;

typedef struct s_coin
{
	int		x;
	int		y;
	void	*img;

} t_coin;

typedef struct s_data
{
	void *mlx;
	t_window			window;
	t_player			player;
	t_enemie			enemie;
	t_coin				coin;
	t_map_assets	map_assets;
} t_data;

#endif
