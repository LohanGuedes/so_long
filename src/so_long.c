#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data data;

	check_params(argc, argv);

	data = (t_data){0};

	// Init mlx and get data for it.
	data.mlx = mlx_init();

	// Generate Map Grid and populate images.
	gen_grid(&data, argv[1]);

	// Check the map
	check_map(&data);

	gen_player(&data, P_ASSET);
	gen_window(&data, (64 * data.map.width), (64 * data.map.height), "so_long");

	//Print current grid
	print_grid(&data);

	// KeyHook for printing. since there's no animation that's the simplest way to make it. since we only have to
	// update what's being displayed by the user everytime he presses a key.
	mlx_key_hook(data.window.ptr, movement_parser, &data);

	mlx_loop(data.mlx);
	/* // Put frees here and then turn then into a function: */
	/* free(data.mlx); */
	/* free(data.window.ptr); */
	/* free(data.player.img); */
	return 0;
}
