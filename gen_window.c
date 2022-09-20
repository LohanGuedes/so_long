#include "so_long.h"

void	gen_window(t_data *data, int width, int height, char *title)
{
	data->window.width = width;
	data->window.height = height;
	data->window.title = title;
	data->window.ptr = mlx_new_window(data->mlx,
																		data->window.width,
																		data->window.height,
																		data->window.title);
	return ;
}
