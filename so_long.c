#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data data;

	check_params(argc, argv);
	data.mlx = mlx_init();
	gen_window(&data, 1024, 720, "so_long");
	gen_player(&data, P_ASSET);
	gen_grid(&data, C_ASSET);

	mlx_put_image_to_window(data.mlx, data.window.ptr, data.player.img, data.player.x, data.player.y);
	mlx_key_hook(data.window.ptr, movement_parser, &data);

	mlx_loop(data.mlx);
	return 0;
}
