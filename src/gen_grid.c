#include "so_long.h"

char	*join(char *str1, char *str2)
{
	char	*final;
	int		i;
	int		j;
	int		offset;

	i = 0;
	j = 0;
	if (!str1)
	{
		final = ft_strdup(str2);
		free(str2);
		return (final);
	}
	offset = 0;
	final = (char *)ft_calloc((ft_strlen(str1) + ft_strlen(str2) + 1),
			sizeof(char));
	while (str1[i])
		final[offset++] = str1[i++];
	while (str2[j])
		final[offset++] = str2[j++];
	free(str1);
	free(str2);
	return (final);
}

void	get_height_width(t_data *data)
{
	int	height;

	height = 0;
	while (data->map.grid[height])
			height++;
	data->map.height = height;
	data->map.width = ft_strlen((char *)(data->map.grid[0]));
}

void	populate_map_img_ptrs(t_data *data)
{
	int	dummy[1];

	data->map.floor = mlx_xpm_file_to_image(data->mlx, F_ASSET, dummy, dummy);
	data->map.wall = mlx_xpm_file_to_image(data->mlx, W_ASSET, dummy, dummy);
	data->map.door = mlx_xpm_file_to_image(data->mlx, D_ASSET, dummy, dummy);
	data->map.coin = mlx_xpm_file_to_image(data->mlx, C_ASSET, dummy, dummy);
}

void	gen_grid(t_data *data, char *file_path)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(file_path, O_RDONLY);
	line = NULL;
	temp = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
		{
			break ;
		}
		line = join(line, temp);
	}
	data->map.grid = ft_split(line, '\n');
	data->map.grid_cpy = ft_split(line, '\n');
	get_height_width(data);
	populate_map_img_ptrs(data);
	close(fd);
	free(line);
}
