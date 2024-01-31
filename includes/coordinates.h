#ifndef COORDINATES_H
#define COORDINATES_H

#include <stdbool.h>

typedef struct {
    short x;
    short y;
} Coordinates;

void coordinates_init(Coordinates* coordinates, short x, short y);
short coordinates_get_x(const Coordinates* coordinates);
short coordinates_get_y(const Coordinates* coordinates);
void coordinates_set_x(Coordinates* coordinates, short new_x);
void coordinates_set_y(Coordinates* coordinates, short new_y);

#endif