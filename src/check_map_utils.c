#include "so_long.h"

void	free_matrix(char **grid)
{
	int i;

	i = 0;
	while(grid[i])
	{
			free(grid[i]);
			i++;
	}
	free(grid);
}

void	check_rectangle(t_data *data)
{
	int	i;
	int	first_len;

	i = 1;
	first_len = (int)ft_strlen(data->map.grid[0]);
	while(data->map.grid[i])
	{
		if((int)ft_strlen(data->map.grid[i]) != first_len)
		{
			write(2, ERR_MAP_NOT_RECTANGLE, ft_strlen(ERR_MAP_NOT_RECTANGLE));
			free_matrix(data->map.grid);
			exit(1);
		}
		i++;
	}
}

int	all_ones(char *str)
{
	int offset;

	offset = 0;
	while (str[offset])
	{
		if(str[offset] != '1')
			return (0);
		offset++;
	}
	return (1);
}

void	check_surround(t_data *data)
{
	int	line_num;
	int	line_len;

	line_len = ft_strlen(data->map.grid[0]);
	line_num = 0;
		line_num++;
	line_num--;
	if(!(all_ones(data->map.grid[line_num]) || all_ones(data->map.grid[0])))
	{
			write(2, ERR_MAP_NOT_SURROUNDED, ft_strlen(ERR_MAP_NOT_SURROUNDED));
			free_matrix(data->map.grid);
			exit(1);
	}
	while (line_num-- > 0)
	{
		if(data->map.grid[line_num][line_len-1] != '1'
			 || data->map.grid[line_num][0] != '1')
		{
			write(2, ERR_MAP_NOT_SURROUNDED, ft_strlen(ERR_MAP_NOT_SURROUNDED));
			free_matrix(data->map.grid);
			exit(1);
		}
	}
}
