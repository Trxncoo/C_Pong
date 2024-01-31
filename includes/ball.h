#ifndef BALL_H
#define BALL_H

#include "../includes/coordinates.h"
#include "../includes/movement.h"

typedef struct {
    Coordinates coordinates;
    Movement movement;
} Ball;

void ball_init(Ball* ball, short x, short y);

// Ball Coordinates
short ball_get_x(const Ball* ball);
short ball_get_y(const Ball* ball);
void ball_set_x(Ball* ball, short new_x);
void ball_set_y(Ball* ball, short new_y);

// Ball Movement
bool ball_get_horizontal(const Ball* ball);
bool ball_get_vertical(const Ball* ball);
void ball_set_horizontal(Ball* ball, bool new_horizontal);
void ball_set_vertical(Ball* ball, bool new_vertical);
void ball_change_horizontal(Ball* ball);
void ball_change_vertical(Ball* ball);

#endif