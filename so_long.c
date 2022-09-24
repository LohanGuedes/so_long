#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data data;

	data = (t_data){0}; // This will assign 0 to each thing inside data
	check_params(argc, argv);
	data.mlx = mlx_init();
	gen_window(&data, 1024, 720, "so_long");
	gen_player(&data, P_ASSET);
	gen_grid(&data, argv[1]);
	for(int  i = 0; data.map_assets.grid[i]; i++)
			free(data.map_assets.grid[i]);
	free(data.map_assets.grid);

	mlx_put_image_to_window(data.mlx, data.window.ptr, data.player.img, data.player.x, data.player.y);
	mlx_key_hook(data.window.ptr, movement_parser, &data);

	mlx_loop(data.mlx);

	free(data.mlx);
	free(data.window.ptr);
	free(data.player.img);
	return 0;
}
