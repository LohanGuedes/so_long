#include "so_long.h"

void	print_wall(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window.ptr,
													data->map.wall, x * 64, y * 64);
}

void	print_floor(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window.ptr,
													data->map.floor, x * 64, y * 64);
}

void	print_player(t_data *data, int x, int y)
{
	print_floor(data, x, y);
	mlx_put_image_to_window(data->mlx, data->window.ptr,
													data->player.img, x * 64, y * 64);
}

void	print_exit(t_data *data, int x, int y)
{
	print_floor(data, x, y);
	mlx_put_image_to_window(data->mlx, data->window.ptr,
													data->map.door, x * 64, y * 64);
}

void	print_coin(t_data *data, int x, int y)
{
	print_floor(data, x, y);
	mlx_put_image_to_window(data->mlx, data->window.ptr,
													data->map.coin, x * 64, y * 64);
}
