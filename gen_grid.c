#include "so_long.h"
#include "src/libft/src/libft.h"

char *join(char *str1, char *str2)
{
	char	*final;
	int	i;
	int	j;
	int offset;

	i = 0;
	j = 0;
	if(!str1)
	{
		final =ft_strdup(str2);
		free(str2);
		return (final);
	}
	offset = 0;
	final = (char*)ft_calloc((ft_strlen(str1) + ft_strlen(str2) + 1), sizeof(char));
	while(str1[i])
		final[offset++] = str1[i++];
	while(str2[j])
		final[offset++] = str2[j++];
	free(str1);
	free(str2);
	return (final);
}

void	gen_grid(t_data *data, char *file_path)
{
	int	fd;
	char	*line;
	char	*temp;

	fd = open(file_path, O_RDONLY);
	line = NULL;
	temp = NULL;
	while(1)
	{
		temp = get_next_line(fd);
		if(!temp)
				break;
		line = join(line, temp);
	}
	data->map_assets.grid = ft_split(line, '\n');
	free(line);
}
