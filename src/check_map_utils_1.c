#include "so_long.h"

int	n_collectables(t_data *data)
{
	int	n_col;
	int	a_index;
	int	b_index;

	n_col = 0;
	a_index = 0;
	while(data->map.grid[a_index])
	{
		b_index = 0;
		while(data->map.grid[a_index][b_index])
		{
			if(data->map.grid[a_index][b_index] == 'C')
				n_col++;
			b_index++;
		}
		a_index++;
	}
	if(n_col == 0)
		throw_quit(data, ERR_MAP_NO_COL, 1);
	return (n_col);
}

void	throw_quit(t_data *data, char *err_msg, int exit_code)
{
	if(data->map.grid)
		free_matrix(data->map.grid);
	if(data->window.ptr)
		mlx_destroy_window(data->mlx, data->window.ptr);
	if(data->player.img)
		mlx_destroy_image(data->mlx, data->player.img);
	if(data->map.floor)
		mlx_destroy_image(data->mlx, data->map.floor);
	if(data->map.wall)
		mlx_destroy_image(data->mlx, data->map.wall);
	if(data->map.door[0])
		mlx_destroy_image(data->mlx, data->map.door[0]);
	if(data->map.door[1])
		mlx_destroy_image(data->mlx, data->map.door[1]);
	write(2, err_msg, ft_strlen(err_msg));
	exit(exit_code);
}

int	validate_content(t_data *data)
{
	int	a_index;
	int	b_index;
	int	player;
	int	exit;

	a_index = 0;
	player = 0;
	exit = 0;
	while(data->map.grid[a_index])
	{
		b_index = 0;
		while(data->map.grid[a_index][b_index])
		{
			if(data->map.grid[a_index][b_index] == 'P')
			{
				if(player)
					throw_quit(data, ERR_MAP_P_NUM, 1);
				player++;
			}
			if(data->map.grid[a_index][b_index] == 'E')
			{
				if(exit)
					throw_quit(data, ERR_MAP_E_NUM, 1);
				exit++;
			}
			b_index++;
		}
		a_index++;
	}
	return (1);
}
