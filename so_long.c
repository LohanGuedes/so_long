#include "so_long.h"

void	check_params(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(2, ERR_MSG_WRONG_NUM_ARG, ft_strlen(ERR_MSG_WRONG_NUM_ARG));
		write(2, USAGE_MSG_EXEC, ft_strlen(USAGE_MSG_EXEC));
		exit(22);
	}
	if(access(argv[1], F_OK | R_OK) == -1)
	{
		perror("So_long \033[31mERROR\e[0m");
		exit(2);
	}
	return ;
}

int	idnk(int keycode, t_player *player)
{
	ft_printf("Keycode = %d", keycode);
	if(player)
			;
	return 1;
}

int	main(int argc, char *argv[])
{
	void *mlx;
	t_window window;
	t_player player;

	// Check the usage of the app
	check_params(argc, argv);

	mlx = mlx_init();
	window.width = 1024;
	window.height = 720;
	window.title = "so_long";
	window.ptr = mlx_new_window(mlx, window.width, window.height, window.title);

	// Create a function to Create Player "object" like this right there:
	player.x = 64;
	player.y = 64;
	player.img = mlx_xpm_file_to_image(mlx, "./Assets/knight/knight_idle_anim_f0.xpm", &player.x, &player.y);
	mlx_put_image_to_window(mlx, window.ptr, player.img, 00, 00);



	mlx_key_hook(window.ptr, idnk, &player);

	mlx_loop(mlx);
	return 0;
}


