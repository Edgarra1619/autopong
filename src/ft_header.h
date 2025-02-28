#ifndef FT_HEADER_H
# define FT_HEADER_H

typedef struct s_game
{
	int	paddle_position[2];
	int	ball_pos[2];
	int	ball_vel[2];
} t_game;

void	render_game(t_game* game);

#endif
