#include "../includes/coordinates.h"

void coordinates_init(Coordinates* coordinates, short x, short y) {
    coordinates_set_x(coordinates, x);
    coordinates_set_y(coordinates, y);
}

short coordinates_get_x(const Coordinates* coordinates) {
    return coordinates->x;
}

short coordinates_get_y(const Coordinates* coordinates) {
    return coordinates->y;
}

void coordinates_set_x(Coordinates* coordinates, short new_x) {
    coordinates->x = new_x;
}

void coordinates_set_y(Coordinates* coordinates, short new_y) {
    coordinates->y = new_y;
}