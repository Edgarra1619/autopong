#include "ft_header.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

int	main()
{
	t_game *game;
	WINDOW *wind;
	int	count;

	game = start_game(NULL);
	if(!game)
		return(0);
	game->score[0] = 0;
	game->score[1] = 0;
	wind = initscr();
	if(!wind)
		goto clean;
	cbreak();
	curs_set(0);
	noecho();
	count = 1000;
	while(count--){
		update_game(game, 100);
		render_game(game);
		clear();
		usleep(100000);
	}
	endwin();
	delwin(wind);
clean:
	free(game);
}
