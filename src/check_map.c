#include "so_long.h"

/*
** 0 = Floor (Any amount)
** 1 = Wall (Any amount)
** C = Collectable (At last 1)
** E = Exit (At least 1) // Even though I guess it's only 1
** P = Player (1 only)
*
** Rules of the map:
** Be surrounded by 1's [X]
** All lines must have the same lenght [X]
** Has to have a path to both all the coins, and the exit.
** Has to print an Error followd by a explicit message of your choice.
*/
void check_contents(t_data *data)
{

}

void	check_map(t_data *data)
{
	check_rectangle(data);
	check_surround(data);
}
