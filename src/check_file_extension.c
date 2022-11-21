#include "so_long.h"

int	check_file_extension(char *filename, char *extension)
{
	int		ext_len;
	int		file_len;
	size_t	i;

	ext_len = ft_strlen(extension);
	file_len = ft_strlen(filename);
	i = 0;
	while (extension[ext_len] == filename[file_len])
	{
		if (i == ft_strlen(extension))
			return (1);
		file_len--;
		ext_len--;
		i++;
	}
	return (0);
}
