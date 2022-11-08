#include "libft/src/libft.h"
#include "so_long.h"

/* void move_player_up(t_data *data) */
/* { */
/* 	// Check if the grid[X - 1][Y] == 0/C */
/* 	ft_printf("Moves: %d\n", data->player.moves); */
/* } */

int	movement_parser(int keycode, t_data *data)
{
	if (keycode == K_UP)
	{
		if (data->map.grid[data->player.y - 1][data->player.x] == 'E' && data->map.coin_count == 0)
		{
			data->map.grid[data->player.y][data->player.x] = '0';
			data->map.grid[data->player.y - 1][data->player.x] = 'P';
			throw_quit(data, "", 0);
		}
		if (data->map.grid[data->player.y - 1][data->player.x] != '1' &&
			data->map.grid[data->player.y - 1][data->player.x] != 'E')
		{
			if (data->map.grid[data->player.y - 1][data->player.x] == 'C')
				data->map.coin_count--;
			data->map.grid[data->player.y][data->player.x] = '0';
			data->map.grid[data->player.y - 1][data->player.x] = 'P';
			data->player.y--;
		}
	}
	/* else if(keycode == Down) */
	/* 	data->player.y += 64; */
	/* else if(keycode == Left) */
	/* 	data->player.x -= 64; */
	/* else if(keycode == Right) */
	/* 	data->player.x += 64; */

	if(keycode == K_ESC)
		throw_quit(data, "", 0);

	for(int y = 0; data->map.grid[y]; y++)
		for(int x = 0; data->map.grid[y][x]; x++)
		{
			if(data->map.grid[y][x] == 'P')
			{
				ft_printf("Y: %i\n", y);
				ft_printf("X: %i\n", x);
			}
		}
	mlx_clear_window(data->mlx, data->window.ptr);
	print_grid(data);
	return (1);
}

void	move_player_down(t_data *data)
{
		if (data->map.grid[data->player.y - 1][data->player.x] == 'E' && data->map.coin_count == 0)
		{
			data->map.grid[data->player.y][data->player.x] = '0';
			data->map.grid[data->player.y - 1][data->player.x] = 'P';
			throw_quit(data, "", 0);
		}
		if (data->map.grid[data->player.y - 1][data->player.x] != '1' &&
			data->map.grid[data->player.y - 1][data->player.x] != 'E')
		{
			if (data->map.grid[data->player.y - 1][data->player.x] == 'C')
				data->map.coin_count--;
			data->map.grid[data->player.y][data->player.x] = '0';
			data->map.grid[data->player.y - 1][data->player.x] = 'P';
			data->player.y--;
		}
}
