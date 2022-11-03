#include "so_long.h"

/* void move_player_up(t_data *data) */
/* { */
/* 	// Check if the grid[X - 1][Y] == 0/C */
/* 	ft_printf("Moves: %d\n", data->player.moves); */
/* } */

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


	mlx_put_image_to_window(data->mlx, data->window.ptr, data->player.img, data->player.x, data->player.y);
	mlx_clear_window(data->mlx, data->window.ptr);
	return 1;
}
