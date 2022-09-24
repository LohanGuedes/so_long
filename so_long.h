#ifndef FRACTOL_H_
# define FRACTOL_H_

// Right mlx includers for each OS (linux and macOS)
# ifdef __linux__
#  include "./src/minilibx/mlx.h"
# else
//#  include "./src/minilibx/mlx.h"
# endif

# include "./src/libft/src/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define ERR_MSG_WRONG_NUM_ARG "So_long \033[31mERROR\e[0m: Wrong number of arguments\n"
# define USAGE_MSG_EXEC "\033[32mUsage: ./so_long <path_to_map>.ber\e[0m\n"
# define ERR_MSG_FILE "So_long \033[31mERROR\e[0m: wrong file extension. EXPECTED: .ber\n"

/*
** DEF ASSETS
**/
# define P_ASSET "./Assets/Knight/knight.xpm"
# define C_ASSET "./Assets/Collectable/key.xpm"

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

/*
** Game Structs (Needed because of poorly coded minilibx).
**/

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

/*
** Utility functions
**/
int	check_file_extension(char *filename, char *extension);
int	movement_parser(int keycode, t_data *data);
void	check_params(int argc, char *argv[]);
void	gen_player(t_data *data, char *image_path);
void	gen_window(t_data *data, int width, int height, char *title);
void	gen_grid(t_data *data, char *file_path);

#endif
