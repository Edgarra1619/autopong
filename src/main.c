#include "ft_header.h"
#include <ncurses.h>
#include <stdlib.h>

int	main()
{
	t_game *game;
	game = start_game();
	if(!game)
		return(0);
	if(!initscr())
		goto clean;
	cbreak();
	noecho();
	wclear(stdscr);
	render_game(0);
	endwin();
clean:
	free(game);
}
