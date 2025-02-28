#include "ft_header.h"
#include <ncurses.h>
#include <stdlib.h>

int	main()
{
	t_game *game;
	WINDOW *wind;
	game = start_game();
	if(!game)
		return(0);
	wind = initscr();
	if(!wind)
		goto clean;
	cbreak();
	curs_set(0);
	noecho();
	render_game(game);
	getch();
	endwin();
	delwin(wind);
clean:
	free(game);
}
