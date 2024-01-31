#include "../includes/movement.h"

void movement_init(Movement* movement) {
    movement_set_horizontal(movement, false);
    movement_set_vertical(movement, false);
}

bool movement_get_horizontal(const Movement* movement) {
    return movement->horizontal;
}

bool movement_get_vertical(const Movement* movement) {
    return movement->vertical;
}

void movement_set_horizontal(Movement* movement, bool new_horizontal) {
    movement->horizontal = new_horizontal;
}

void movement_set_vertical(Movement* movement, bool new_vertical) {
    movement->vertical = new_vertical;
}

void movement_change_horizontal(Movement* movement) {
    movement->horizontal = !movement->horizontal;
}

void movement_change_vertical(Movement* movement) {
    movement->vertical = !movement->vertical;
}