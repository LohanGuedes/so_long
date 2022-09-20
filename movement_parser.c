#include "so_long.h"

int	movement_parser(int keycode, t_data *data)
{
	if (keycode == Up)
			data->player.y -= 64;
	else if(keycode == Down)
			data->player.y += 64;
	else if(keycode == Left)
			data->player.x -= 64;
	else if(keycode == Right)
			data->player.x += 64;
	data->player.moves++;

	ft_printf("Moves: %d\n", data->player.moves);
	mlx_clear_window(data->mlx, data->window.ptr);
	mlx_put_image_to_window(data->mlx, data->window.ptr, data->player.img, data->player.x, data->player.y);
	return 1;
}
