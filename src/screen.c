#include "../includes/screen.h"

void screen_init(Screen* screen) {
    short x, y;
    getmaxyx(stdscr, y, x);
    screen_set_x(screen, x);
    screen_set_y(screen, y);
}

// Screen Coordinates
short screen_get_x(const Screen* screen) {
    coordinates_get_x(&screen->coordinates);
}

short screen_get_y(const Screen* screen) {
    coordinates_get_y(&screen->coordinates);
}

void screen_set_x(Screen* screen, short new_x) {
    coordinates_set_x(&screen->coordinates, new_x);
}

void screen_set_y(Screen* screen, short new_y) {
    coordinates_set_y(&screen->coordinates, new_y);
}
