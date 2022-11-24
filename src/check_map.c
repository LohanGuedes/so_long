#include "so_long.h"

void	check_map(t_data *data)
{
	check_rectangle(data);
	check_surround(data);
	data->map.coin_count = n_collectables(data);
	validate_content(data);
	if (data->map.player_count != 1)
		throw_quit(data, "Error: Map error. Please enter only 1 'P'.\n", 2);
	validate_path(data);
}
