#ifndef GAME_H
#define GAME_H

#include "../includes/ball.h"
#include "../includes/paddle.h"
#include "../includes/screen.h"

typedef struct {
    Screen screen;
    Paddle right_paddle, left_paddle;
    Ball ball;
    bool end;
} Game;

void game_init(Game* game);

// Game Collisions
void game_collisions(Game* game);
bool game_check_ball_y_collision(Game* game);
bool game_check_ball_x_collision(Game* game);

// Game Input
void game_get_input(Game* game);

// Game Ball
void game_move_ball(Game* game);
void game_reset_ball(Game* game);

#endif