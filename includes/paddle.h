#ifndef PADDLE_H
#define PADDLE_H

#include "../includes/coordinates.h"
#include "../includes/movement.h"

typedef struct {
    Coordinates coordinates;
    Movement movement;
    short score;
} Paddle;

bool paddle_init(Paddle* paddle, short x, short y);

// Paddle Coordinates
short paddle_get_x(const Paddle* paddle);
short paddle_get_y(const Paddle* paddle);
void paddle_set_x(Paddle* paddle, short new_x);
void paddle_set_y(Paddle* paddle, short new_y);
void paddle_move_up(Paddle* paddle, short quantity);
void paddle_move_down(Paddle* paddle, short quantity);

// Paddle Movement
bool paddle_get_horizontal(const Paddle* paddle);
bool paddle_get_vertical(const Paddle* paddle);
void paddle_set_horizontal(Paddle* paddle, bool new_horizontal);
void paddle_set_vertical(Paddle* paddle, bool new_vertical);
void paddle_change_horizontal(Paddle* paddle);
void paddle_change_vertical(Paddle* paddle);

// Paddle Score
short paddle_get_score(const Paddle* paddle);
void paddle_set_score(Paddle* paddle, short new_score);
void paddle_increment_score(Paddle* paddle);


#endif