#include "libft/src/libft.h"
#include "so_long.h"

int	movement_parser(int keycode, t_data *data)
{
	ft_printf("%i\n", keycode);
	if (keycode == K_UP || keycode == K_A_UP)
		move_player_up(data);
	else if(keycode == K_DOWN || keycode == K_A_DOWN)
		move_player_down(data);
	else if(keycode == K_LEFT || keycode == K_A_LEFT)
		move_player_left(data);
	else if(keycode == K_RIGHT || keycode == K_A_RIGHT)
		move_player_right(data);

	if(keycode == K_ESC)
		throw_quit(data, "", 0);
	mlx_clear_window(data->mlx, data->window.ptr);
	print_grid(data);
	return (1);
}

void	move_player_up(t_data *data)
{
	if (data->map.grid[data->player.y - 1][data->player.x]
		== 'E' && data->map.coin_count == 0)
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
		data->player.moves++;
		ft_printf("Moves: %i\n", data->player.moves);
	}
}

void	move_player_down(t_data *data)
{
	if (data->map.grid[data->player.y + 1][data->player.x]
		== 'E' && data->map.coin_count == 0)
	{
		data->map.grid[data->player.y][data->player.x] = '0';
		data->map.grid[data->player.y + 1][data->player.x] = 'P';
		throw_quit(data, "", 0);
	}
	if (data->map.grid[data->player.y + 1][data->player.x] != '1' &&
		data->map.grid[data->player.y + 1][data->player.x] != 'E')
	{
		if (data->map.grid[data->player.y + 1][data->player.x] == 'C')
			data->map.coin_count--;
		data->map.grid[data->player.y][data->player.x] = '0';
		data->map.grid[data->player.y + 1][data->player.x] = 'P';
		data->player.y++;
		data->player.moves++;
		ft_printf("Moves: %i\n", data->player.moves);
	}
}

void	move_player_left(t_data *data)
{
	if (data->map.grid[data->player.y][data->player.x - 1]
		== 'E' && data->map.coin_count == 0)
	{
		data->map.grid[data->player.y][data->player.x] = '0';
		data->map.grid[data->player.y][data->player.x - 1] = 'P';
		throw_quit(data, "", 0);
	}
	if (data->map.grid[data->player.y][data->player.x - 1] != '1' &&
		data->map.grid[data->player.y][data->player.x - 1] != 'E')
	{
		if (data->map.grid[data->player.y][data->player.x - 1] == 'C')
			data->map.coin_count--;
		data->map.grid[data->player.y][data->player.x] = '0';
		data->map.grid[data->player.y][data->player.x - 1] = 'P';
		data->player.x--;
		data->player.moves++;
		ft_printf("Moves: %i\n", data->player.moves);
	}
}

void	move_player_right(t_data *data)
{
	if (data->map.grid[data->player.y][data->player.x + 1]
		== 'E' && data->map.coin_count == 0)
	{
		data->map.grid[data->player.y][data->player.x] = '0';
		data->map.grid[data->player.y][data->player.x + 1] = 'P';
		throw_quit(data, "", 0);
	}
	if (data->map.grid[data->player.y][data->player.x + 1] != '1' &&
		data->map.grid[data->player.y][data->player.x + 1] != 'E')
	{
		if (data->map.grid[data->player.y][data->player.x - 1] == 'C')
			data->map.coin_count--;
		data->map.grid[data->player.y][data->player.x] = '0';
		data->map.grid[data->player.y][data->player.x + 1] = 'P';
		data->player.x++;
		data->player.moves++;
		ft_printf("Moves: %i\n", data->player.moves);
	}
}
