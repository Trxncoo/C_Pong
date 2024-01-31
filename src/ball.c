#include "../includes/ball.h"

void ball_init(Ball* ball, short x, short y) {
    coordinates_init(&ball->coordinates, x, y);
    movement_init(&ball->movement);
}

// Ball Coordinates
short ball_get_x(const Ball* ball) {
    return coordinates_get_x(&ball->coordinates);
}

short ball_get_y(const Ball* ball) {
    return coordinates_get_y(&ball->coordinates);
}

void ball_set_x(Ball* ball, short new_x) {
    coordinates_set_x(&ball->coordinates, new_x);
}

void ball_set_y(Ball* ball, short new_y) {
    coordinates_set_y(&ball->coordinates, new_y);
}

// Ball Movement
bool ball_get_horizontal(const Ball* ball) {
    return movement_get_horizontal(&ball->movement);
}

bool ball_get_vertical(const Ball* ball) {
    return movement_get_vertical(&ball->movement);
}

void ball_set_horizontal(Ball* ball, bool new_horizontal) {
    movement_set_horizontal(&ball->movement, new_horizontal);
}

void ball_set_vertical(Ball* ball, bool new_vertical) {
    movement_set_vertical(&ball->movement, new_vertical);
}

void ball_change_horizontal(Ball* ball) {
    movement_change_horizontal(&ball->movement);
}

void ball_change_vertical(Ball* ball) {
    movement_change_vertical(&ball->movement);
}