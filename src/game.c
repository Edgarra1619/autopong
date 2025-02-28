#include "ft_header.h"
#include <stdlib.h>

t_game	*start_game()
{
	t_game *game = (t_game*) malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->ball_pos[0] = 0;
	game->ball_pos[1] = 0;
	game->ball_vel[0] = 5;
	game->ball_vel[1] = 0;
	game->paddle_position[0] = 0;
	game->paddle_position[1] = 0;
	return (game);
}
