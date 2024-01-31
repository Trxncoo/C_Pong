#ifndef SCREEN_H
#define SCREEN_H

#include "../includes/coordinates.h"
#include <ncurses.h>

typedef struct {
    Coordinates coordinates;
} Screen;

void screen_init(Screen* screen);

// Screen Coordinates
short screen_get_x(const Screen* screen);
short screen_get_y(const Screen* screen);
void screen_set_x(Screen* screen, short new_x);
void screen_set_y(Screen* screen, short new_y);

#endif