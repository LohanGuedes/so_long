#include "libft/src/libft.h"
#include "so_long.h"

int	n_collectables(t_data *data)
{
	int	n_col;
	int	a_index;
	int	b_index;

	n_col = 0;
	a_index = 0;
	while (data->map.grid[a_index])
	{
		b_index = 0;
		while (data->map.grid[a_index][b_index])
		{
			if (data->map.grid[a_index][b_index] == 'C')
				n_col++;
			b_index++;
		}
		a_index++;
	}
	if (n_col == 0)
		throw_quit(data, ERR_MAP_NO_COL, 1);
	return (n_col);
}

void	throw_quit(t_data *data, char *err_msg, int exit_code)
{
	if (data->map.grid)
		free_matrix(data->map.grid);
	if (data->map.grid_cpy)
		free_matrix(data->map.grid_cpy);
	if (data->window.ptr)
		mlx_destroy_window(data->mlx, data->window.ptr);
	if (data->player.img)
		mlx_destroy_image(data->mlx, data->player.img);
	if (data->map.floor)
		mlx_destroy_image(data->mlx, data->map.floor);
	if (data->map.wall)
		mlx_destroy_image(data->mlx, data->map.wall);
	if (data->map.door)
		mlx_destroy_image(data->mlx, data->map.door);
	write(2, err_msg, ft_strlen(err_msg));
	exit(exit_code);
}

void	validate_content(t_data *data)
{
	int	a_index;
	int	b_index;
	int	exit;

	a_index = 0;
	exit = 0;
	while (data->map.grid[a_index])
	{
		b_index = 0;
		while (data->map.grid[a_index][b_index])
		{
			if (data->map.grid[a_index][b_index] == 'P')
			{
				data->player.x = b_index;
				data->player.y = a_index;
				data->map.player_count++;
			}
			if (data->map.grid[a_index][b_index] == 'E')
				exit++;
			b_index++;
		}
		a_index++;
	}
}

void	check_invalid_chars(t_data *data, char *path)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
		{
			if (!ft_strchr("PEC01", data->map.grid[i][j]))
			{
				ft_printf("%s :%d:%d ", path, i, j);
				throw_quit(
					data,
					"Invalid character found when validating the map\n",
					2);
			}
			j++;
		}
		i++;
	}
	return ;
}
