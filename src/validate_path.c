#include "so_long.h"

void	rechable_elements(t_data *data, int x, int y, int *e_count)
/*
 * This should evaluate each position that a player can move (0's)
 * to find a valid path into all C's and at least one E
 */
{
	if (data->map.grid_cpy[x][y] == '1')
		return ;
	if (data->map.grid_cpy[x][y] == 'C')
		data->map.coin_count--;
	if (data->map.grid_cpy[x][y] == 'E')
		--*e_count;
	data->map.grid_cpy[x][y] = '1'; // Changes already known place to a wall
	rechable_elements(data, (x + 1), y, e_count);
	rechable_elements(data, (x - 1), y, e_count);
	rechable_elements(data, x, (y + 1), e_count);
	rechable_elements(data, x, (y - 1), e_count);
}

void	validate_path(t_data *data)
{
	int e_cnt;
	int c_cnt;

	e_cnt = 1;
	c_cnt = data->map.coin_count;
	rechable_elements(data, data->player.x, data->player.y, &e_cnt);
	if (data->map.coin_count > 0 || e_cnt > 0)
		throw_quit(data, ERR_V_P, 1);
	data->map.coin_count = c_cnt - 1;
	free(data->map.grid_cpy);
	return ;
}
