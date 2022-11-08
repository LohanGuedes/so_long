#include "so_long.h"

void	gen_player(t_data *data, char *image_path)
{
	int x;
	int y;

	x = data->player.x;
	y = data->player.y;
	data->player.img = mlx_xpm_file_to_image(data->mlx, image_path, &data->player.x, &data->player.y);
	data->player.y = y;
	data->player.x = x;
	return ;
}
