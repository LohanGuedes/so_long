#include "so_long.h"
#include "src/libft/src/libft.h"
#include "src/minilibx/mlx.h"

typedef struct s_player
{
	int		x;
	int		y;
	void	*player_img;

} t_player;

void	check_params(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(2, EM_WRONG_NUM_ARG, ft_strlen(EM_WRONG_NUM_ARG));
		write(2, UM_EXEC, ft_strlen(UM_EXEC));
		exit(22);
	}
	if(access(argv[1], F_OK | R_OK) == -1)
	{
		perror("So_long \033[31mERROR\e[0m");
		exit(2);
	}
	return ;
}

int	main(int argc, char *argv[])
{
	void *mlx;
	t_window window;

	check_params(argc, argv);

	mlx = mlx_init();
	window.width = 1280;
	window.height = 720;
	window.title = "so_long";
	window.ptr = mlx_new_window(mlx, window.width, window.height, window.title);

	// Create and print image (player)

	mlx_loop(mlx);
    return 0;
}
