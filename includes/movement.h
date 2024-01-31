#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdbool.h>

typedef struct {
    bool horizontal;
    bool vertical;
} Movement;

void movement_init(Movement* movement);
bool movement_get_horizontal(const Movement* movement);
bool movement_get_vertical(const Movement* movement);
void movement_set_horizontal(Movement* movement, bool new_horizontal);
void movement_set_vertical(Movement* movement, bool new_vertical);
void movement_change_horizontal(Movement* movement);
void movement_change_vertical(Movement* movement);

#endif