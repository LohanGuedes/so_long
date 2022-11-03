#include "so_long.h"

void	gen_player(t_data *data, char *image_path)
{
	data->player.img = mlx_xpm_file_to_image(data->mlx, image_path, &data->player.x, &data->player.y);
	data->player.x = 0;
	data->player.y = 0;
	data->player.moves = 0;
	return ;
}
