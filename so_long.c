#include "so_long.h"
#include "src/libft/src/libft.h"
#include "src/minilibx/mlx.h"


int	check_file_extension(char *filename, char *extension)
{
	int ext_len;
	int file_len;
	size_t i;

	ext_len = ft_strlen(extension);
	file_len = ft_strlen(filename);
	i = 0;
	while(extension[ext_len] == filename[file_len])
	{
		if(i == ft_strlen(extension))
			return 1;
		file_len--;
		ext_len--;
		i++;
	}
	return 0;
}


void	check_params(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(2, ERR_MSG_WRONG_NUM_ARG, ft_strlen(ERR_MSG_WRONG_NUM_ARG));
		write(2, USAGE_MSG_EXEC, ft_strlen(USAGE_MSG_EXEC));
		exit(22);
	}
		// Check the extension to be a .ber
		// if it isn't
	if(access(argv[1], F_OK | R_OK) == -1)
	{
		perror("So_long \033[31mERROR\e[0m");
		exit(2);
	}
	if(!check_file_extension(argv[1], ".ber"))
	{
		write(2, ERR_MSG_FILE, ft_strlen(ERR_MSG_FILE));
	}
	return ;
}

int	movement_parser(int keycode, t_data *data)
{
	if (keycode == Up)
			data->player.y -= 64;
	else if(keycode == Down)
			data->player.y += 64;
	else if(keycode == Left)
			data->player.x -= 64;
	else if(keycode == Right)
			data->player.x += 64;
	data->player.moves++;

	ft_printf("Moves: %d\n", data->player.moves);
	mlx_clear_window(data->mlx, data->window.ptr);
	mlx_put_image_to_window(data->mlx, data->window.ptr, data->player.img, data->player.x, data->player.y);
	return 1;
}

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

void	get_player(t_data *data, char *image_path)
{
	data->player.img = mlx_xpm_file_to_image(data->mlx, image_path, &data->player.x, &data->player.y);
	data->player.x = 0;
	data->player.y = 0;
	data->player.moves = 0;

	return ;
}

void	build_grid(t_data *data, char *file_path)
{
	/* int		fd; */
	char	*line;
	/* char	**grid; */

	if(data || file_path)
			;
	line = "this is a test, which: ";
	ft_printf("%s\n", line);
	line = ft_strjoin(line, "passed ");
	ft_printf("%s\n", line);
}

int	main(int argc, char *argv[])
{
	t_data data;

	// Can I build a grid of the map and keep it for better performance?
	// If I'm able to build a image using the grid first, I won't be needing to reprint EACH tile each time.
	check_params(argc, argv);
	data.mlx = mlx_init();


	gen_window(&data, 1024, 720, "so_long");
	get_player(&data, P_ASSET);
	build_grid(&data, C_ASSET);

	mlx_put_image_to_window(data.mlx, data.window.ptr, data.player.img, data.player.x, data.player.y);
	mlx_key_hook(data.window.ptr, movement_parser, &data);

	mlx_loop(data.mlx);
	return 0;
}
