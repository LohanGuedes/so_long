#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#  include "./minilibx-linux/mlx.h"
# else /* This is intended to run on Linux or MacOS! */
#  include "./minilibx_opengl_20191021/mlx.h"
# endif

# include "./libft/src/libft.h"
# include <stdio.h>
# include <fcntl.h>

/*
** Error messages
*/
# define USAGE_MSG_EXEC "\033[32mUsage: ./so_long <path_to_map>.ber\e[0m\n"
# define ERR_MSG_NUM_ARG "So_long \033[31mERROR\e[0m: Wrong num of arguments\n"
# define ERR_MSG_FILE "So_long \033[31mERROR\e[0m: Wrong file extension.\n"
# define ERR_MAP_NOT_REC "\033[31mError\e[0m\n Not a rectangle.\n"
# define ERR_MAP_NOT_SUR "\033[31mError\e[0m\n Not surrounded by walls.\n"
# define ERR_MAP_NO_COL "\033[31mError\e[0m\n No Collectable found.\n"
# define ERR_MAP_P_NUM "\033[31mError\e[0m\n More than 1 'P' on map.\n"
# define ERR_MAP_E_NUM "\033[31mError\e[0m\n More than 1 'E' on map.\n"
# define ERR_V_P "\033[31mError\e[0m\n There is no valid path to coin/exit.\n"

/*
** DEF ASSETS PATHS
*/
# define P_ASSET "./Assets/Knight/knight.xpm"
# define C_ASSET "./Assets/Collectable/key.xpm"
# define F_ASSET "Assets/Tiles/floor_1.xpm"
# define W_ASSET "Assets/Tiles/wall_1.xpm"
# define D_ASSET "Assets/Tiles/Exit/door_closed.xpm"
# define D_O_ASSET "Assets/Tiles/Exit/door_open.xpm"

# ifdef __linux__
#  define K_ESC 65509
#  define K_UP 119
#  define K_DOWN 115
#  define K_LEFT 97
#  define K_RIGHT 100
#  define K_A_UP 65362
#  define K_A_DOWN 65364
#  define K_A_LEFT 65361
#  define K_A_RIGHT 65363
# else
#  define K_ESC 53
#  define K_UP 13
#  define K_LEFT 0
#  define K_DOWN 1
#  define K_RIGHT 2
#  define K_A_UP 126
#  define K_A_LEFT 123
#  define K_A_DOWN 125
#  define K_A_RIGHT 124
# endif

/*
** Game Structs for t_data.
** Needed because of poorly coded minilibx.
*/
typedef struct s_window
{
	void	*ptr;
	char	*title;
	int		height;
	int		width;

}				t_window;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	void	*img;

}				t_player;

typedef struct s_enemie
{
	int		x;
	int		y;
	void	*img;

}				t_enemie;

typedef struct s_map
{
	char	**grid;
	char	**grid_cpy;
	void	*floor;
	void	*door;
	void	*wall;
	void	*coin;
	int		height;
	int		width;
	int		coin_count;

}				t_map;

typedef struct s_data
{
	void				*mlx;
	t_window			window;
	t_player			player;
	t_map				map;
}				t_data;

/*
** Utility functions
*/
int		check_file_extension(char *filename, char *extension);
int		movement_parser(int keycode, t_data *data);
void	check_params(int argc, char *argv[]);
void	gen_player(t_data *data, char *image_path);
void	gen_window(t_data *data, int width, int height, char *title);
void	gen_grid(t_data *data, char *file_path);
void	free_matrix(char **grid);
void	throw_quit(t_data *data, char *err_msg, int exit_code);

/*
** Display and graphics
*/
void	print_grid(t_data *data);
void	print_wall(t_data *data, int x, int y);
void	print_floor(t_data *data, int x, int y);
void	print_player(t_data *data, int x, int y);
void	print_exit(t_data *data, int x, int y);
void	print_coin(t_data *data, int x, int y);

void	check_map(t_data *data);
void	check_rectangle(t_data *data);
void	check_surround(t_data *data);
void	validate_content(t_data *data);
void	validate_path(t_data *data);
int		n_collectables(t_data *data);

/*
** Player Manipulation movement
*/
void	move_player_up(t_data *data);
void	move_player_down(t_data *data);
void	move_player_left(t_data *data);
void	move_player_right(t_data *data);

#endif //SO_LONG_H
