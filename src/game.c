#include "ft_header.h"
#include <stdlib.h>
#include <ncurses.h>

t_game	*start_game(t_game* game)
{
	if(!game)
		game = (t_game*) malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->ball_pos[0] = 0;
	game->ball_pos[1] = 0;
	game->ball_vel[0] = 8000;
	game->ball_vel[1] = 2000;
	game->padl_pos[0] = 0;
	game->padl_pos[1] = 0;
	return (game);
}

void	move_paddles(t_game *game, int mtime)
{
	const	int	max_speed = 6000;
	const	int	snappiness = 4;
	int	paddle_move;

	if (game->ball_vel[0] >= 0)
	{
		paddle_move = snappiness * (game->padl_pos[1] - game->ball_pos[1]);
		if(paddle_move > max_speed)
			paddle_move = max_speed;
		else if(paddle_move < -max_speed)
			paddle_move = -max_speed;
		game->padl_pos[1] -= paddle_move * mtime / 1000;
		paddle_move = game->padl_pos[0] - 0;
		if(paddle_move > max_speed)
			paddle_move = max_speed;
		else if(paddle_move < -max_speed)
			paddle_move = -max_speed;
		game->padl_pos[0] -= paddle_move * mtime / 1000;
	}
	else
	{
		paddle_move = snappiness * (game->padl_pos[0] - game->ball_pos[1]);
		if(paddle_move > max_speed)
			paddle_move = max_speed;
		else if(paddle_move < -max_speed)
			paddle_move = -max_speed;
		game->padl_pos[0] -= paddle_move * mtime / 1000;
		paddle_move = game->padl_pos[1] - 0;
		if(paddle_move > max_speed)
			paddle_move = max_speed;
		else if(paddle_move < -max_speed)
			paddle_move = -max_speed;
		game->padl_pos[1] -= paddle_move * mtime / 1000;
	}

	if(game->padl_pos[0] > (MAX_Y-1000))
		game->padl_pos[0] = (MAX_Y-1000);
	else if(game->padl_pos[0] < -(MAX_Y-1000))
		game->padl_pos[0] = -(MAX_Y-1000);

	if(game->padl_pos[1] > (MAX_Y-1000))
		game->padl_pos[1] = (MAX_Y-1000);
	else if(game->padl_pos[1] < -(MAX_Y-1000))
		game->padl_pos[1] = -(MAX_Y-1000);

}

//milliseconds
void	update_game(t_game *game, int mtime)
{
	move_paddles(game, mtime);
	game->ball_pos[0] += game->ball_vel[0] * mtime / 1000;
	game->ball_pos[1] += game->ball_vel[1] * mtime / 1000;
	if(game->ball_pos[1] >= MAX_Y && game->ball_vel[1] > 0)
	{
		game->ball_vel[1] *= -1;
		game->ball_pos[1] = MAX_Y * 2 - game->ball_pos[1];
	}
	else if(game->ball_pos[1] <= -MAX_Y && game->ball_vel[1] < 0)
	{
		game->ball_vel[1] *= -1;
		game->ball_pos[1] = MAX_Y * -2 - game->ball_pos[1];
	}
	
	if(	game->ball_pos[0] >= 15000 && game->ball_pos[0] <= 15750 &&
		game->ball_pos[1] >= game->padl_pos[1] - 1250 &&
		game->ball_pos[1] <= game->padl_pos[1] + 1250)
	{
		//game->ball_vel[0] += 2000 - abs(game->ball_pos[1] - game->padl_pos[0]);
		game->ball_vel[0] *= -1;
		//game->ball_vel[1] -= game->ball_pos[1] - game->padl_pos[0];
		game->ball_pos[0] = 15000;
	}
	if(	-game->ball_pos[0] >= 15000 && -game->ball_pos[0] <= 15750 &&
		game->ball_pos[1] >= game->padl_pos[0] - 1250 &&
		game->ball_pos[1] <= game->padl_pos[0] + 1250)
	{
		//game->ball_vel[0] -= 2000 - abs(game->ball_pos[1] - game->padl_pos[1]);
		game->ball_vel[0] *= -1;
		//game->ball_vel[1] -= game->ball_pos[1] - game->padl_pos[1];
		game->ball_pos[0] = -15000;
	}
	if (game->ball_pos[0] <= - MAX_X)
	{
		game->score[1]++;
		start_game(game);
	}
	if (game->ball_pos[0] >= MAX_X)
	{
		game->score[1]++;
		start_game(game);
	}


}
