#include "so_long.h"
#include "src/libft/src/libft.h"

/*
** 0 = Floor (Any amount)
** 1 = Wall (Any amount)
** C = Collectable (At last 1)
** E = Exit (At least 1) // Even though I guess it's only 1
** P = Player (1 only)
**
** Rules of the map:
** Be surrounded by 1's
** All lines must have the same lenght [X]
** Has to have a path to both all the coins, and the exit.
** Has to print an Error followd by a explicit message of your choice.
*/

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
			exit(1);
		}
		i++;
	}
}

void	check_surround(t_data *data)
{
	int	line_num;
	int	offset;
	int	line_len;

	line_len = ft_strlen(data->map.grid[0]);
	line_num = 0;
	offset = 0;
	while(data->map.grid[line_num])
			line_num++;

	// Check for the last line
	line_num--;
	while (data->map.grid[line_num][offset])
	{
		if(data->map.grid[line_num][offset] != '1')
		{
			write(2, ERR_MAP_NOT_SURROUNDED, ft_strlen(ERR_MAP_NOT_SURROUNDED));
			exit(1);
		}
		offset++;
	}

	while (line_num-- > 0)
	{
		if(data->map.grid[line_num][line_len] != '1' || data->map.grid[line_num][0] != '1')
		{
			write(2, ERR_MAP_NOT_SURROUNDED, ft_strlen(ERR_MAP_NOT_SURROUNDED));
			exit(1);
		}
	}

	offset = 0;
	while (data->map.grid[0][offset++])
	{
		if(data->map.grid[0][offset] != '1')
		{
			write(2, ERR_MAP_NOT_SURROUNDED, ft_strlen(ERR_MAP_NOT_SURROUNDED));
			exit(1);
		}
	}
}

void	check_map(t_data *data)
{
	check_rectangle(data);
	check_surround(data);
}
