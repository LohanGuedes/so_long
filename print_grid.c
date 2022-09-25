#include "so_long.h"

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
			else if (data->map.grid[x][y] == 'E')
				print_exit(data, y, x);
			y++;
		}
		x++;
	}
}
