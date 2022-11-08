#include "libft/src/libft.h"
#include "so_long.h"

void	check_map(t_data *data)
{
	check_rectangle(data);
	check_surround(data);
	data->map.coin_count = n_collectables(data);
	validate_content(data);
	// TODO Validate PATH
}
