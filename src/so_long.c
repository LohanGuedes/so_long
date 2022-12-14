#include "so_long.h"

int	x_quit_game(t_data *data)
/* Quits the game if the X button is pressed. */
{
	if (data)
		throw_quit(data, "", 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	check_params(argc, argv);
	data = (t_data){0};
	data.mlx = mlx_init();
	gen_grid(&data, argv[1]);
	check_map(&data);
	check_invalid_chars(&data, argv[1]);
	gen_player(&data, P_ASSET);
	gen_window(&data, (64 * data.map.width), (64 * data.map.height), "so_long");
	print_grid(&data);
	mlx_hook(data.window.ptr, 17, 0, x_quit_game, &data);
	mlx_key_hook(data.window.ptr, movement_parser, &data);
	mlx_loop(data.mlx);
	return (0);
}
