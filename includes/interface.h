#ifndef INTERFACE_H
#define INTERFACE_H

#include <ncurses.h>
#include "../includes/game.h"

void interface_init();
void interface_draw(Game* game);

#endif