#include "../includes/interface.h"
#include <unistd.h>

int main() {
    Game game;
    int i = 0, cont = 0; 
    
    interface_init();
    game_init(&game);
    
    for (nodelay(stdscr, 1); !game.end; usleep(4000)) {
        if (++cont % 16 == 0) {
            game_collisions(&game);
            game_move_ball(&game);
        }

        game_get_input(&game);
        interface_draw(&game);
    }

    return 0;
}