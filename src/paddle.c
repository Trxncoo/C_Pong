#include "../includes/paddle.h"

bool paddle_init(Paddle* paddle, short x, short y) {
    coordinates_init(&paddle->coordinates, x, y);
    movement_init(&paddle->movement);
    paddle_set_score(paddle, 0);
    return true;
}

// Paddle Coordinates
short paddle_get_x(const Paddle* paddle) {
    return coordinates_get_x(&paddle->coordinates);
}

short paddle_get_y(const Paddle* paddle) {
    return coordinates_get_y(&paddle->coordinates);
}

void paddle_set_x(Paddle* paddle, short new_x) {
    coordinates_set_x(&paddle->coordinates, new_x);
}

void paddle_set_y(Paddle* paddle, short new_y) {
    coordinates_set_y(&paddle->coordinates, new_y);
}

void paddle_move_up(Paddle* paddle, short quantity) {
    short new_y = paddle_get_y(paddle) - quantity;
    paddle_set_y(paddle, new_y);
}

void paddle_move_down(Paddle* paddle, short quantity) {
    short new_y = paddle_get_y(paddle) + quantity;
    paddle_set_y(paddle, new_y);
}

// Paddle Movement
bool paddle_get_horizontal(const Paddle* paddle) {
    return movement_get_horizontal(&paddle->movement);
}

bool paddle_get_vertical(const Paddle* paddle) {
    return movement_get_vertical(&paddle->movement);
}

void paddle_set_horizontal(Paddle* paddle, bool new_horizontal) {
    movement_set_horizontal(&paddle->movement, new_horizontal);
}

void paddle_set_vertical(Paddle* paddle, bool new_vertical) {
    movement_set_vertical(&paddle->movement, new_vertical);
}

void paddle_change_horizontal(Paddle* paddle) {
    movement_change_horizontal(&paddle->movement);
}

void paddle_change_vertical(Paddle* paddle) {
    movement_change_vertical(&paddle->movement);
}

// Paddle Score
short paddle_get_score(const Paddle* paddle) {
    return paddle->score;
}

void paddle_set_score(Paddle* paddle, short new_score) {
    paddle->score = new_score;
}

void paddle_increment_score(Paddle* paddle) {
    short new_score = paddle_get_score(paddle) + 1;
    paddle_set_score(paddle, new_score);
}

