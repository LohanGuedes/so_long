#include "so_long.h"
#include "src/libft/src/libft.h"
#include "src/minilibx/mlx.h"

void	print_wall(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window.ptr, data->map.wall, x * 64, y * 64);
}

void	print_floor(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window.ptr, data->map.floor, x * 64, y * 64);
}

void	print_player(t_data *data, int x, int y)
{
	print_floor(data, x, y);
	mlx_put_image_to_window(data->mlx, data->window.ptr, data->player.img, x * 64, y * 64);
}

void	print_exit(t_data *data, int x, int y)
{
	print_floor(data, x, y);
	mlx_put_image_to_window(data->mlx, data->window.ptr, data->map.door[0], x * 64, y * 64);
}

void	print_coin(t_data *data, int x, int y)
{
	print_floor(data, x, y);
	mlx_put_image_to_window(data->mlx, data->window.ptr, data->map.coin, x * 64, y * 64);
}

void	print_grid(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(data->map.grid[x])
	{
		y = 0;
		while(data->map.grid[x][y])
		{
			if (data->map.grid[x][y] == '1')
				print_wall(data, y, x);
			else if (data->map.grid[x][y] == '0')
				print_floor(data, y, x);
			else if (data->map.grid[x][y] == 'P')
				print_player(data, y, x);
			else if (data->map.grid[x][y] == 'C')
				print_coin(data, y, x);
			else if (data->map.grid[x][y] == 'E')// Print floor and exit
				print_exit(data, y, x);
			y++;
		}
		x++;
	}
}
