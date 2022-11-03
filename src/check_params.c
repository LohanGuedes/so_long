#include "so_long.h"

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
		exit(2);
	}
	return ;
}
