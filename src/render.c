#include "ft_header.h"
#include <ncurses.h>

void	put_rectangle(	int ulcorner_x, int ulcorner_y,
			int drcorner_x, int drcorner_y);

void	render_game(t_game *game)
{
	erase();
	put_rectangle(	game->ball_pos[0]-250, game->ball_pos[1]-250,
			game->ball_pos[0]+250, game->ball_pos[1]+250);
	
	put_rectangle(	-15500, game->padl_pos[0]-1000,
			-15250, game->padl_pos[0]+1000);

	put_rectangle(	15250, game->padl_pos[1]-1000,
			15500, game->padl_pos[1]+1000);
	move(2, COLS/2 - 4);
	printw("%d", game->score[0]);
	move(2, COLS/2 + 4);
	printw("%d", game->score[1]);
	refresh();
}

void	put_rectangle(	int ulcorner_x, int ulcorner_y,
			int drcorner_x, int drcorner_y)
{
	int	y;
	
	ulcorner_x = (ulcorner_x / ((MAX_X * 2) / COLS)) + COLS / 2;
	ulcorner_y = (ulcorner_y / ((MAX_Y * 2) / LINES)) + LINES / 2;
	drcorner_x = (drcorner_x / ((MAX_X * 2) / COLS)) + COLS / 2;
	drcorner_y = (drcorner_y / ((MAX_Y * 2) / LINES)) + LINES / 2;
	while(ulcorner_x <= drcorner_x)
	{
		y = ulcorner_y;
		while(y <= drcorner_y)
		{
			mvaddch(y, ulcorner_x, ACS_BLOCK);
			y++;
		}
		ulcorner_x++;
	}
}
