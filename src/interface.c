#include "../includes/interface.h"

void interface_init() {
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
}

void interface_draw(Game* game) {
    Screen* screen = &game->screen;
    Paddle* right_paddle = &game->right_paddle;
    Paddle* left_paddle = &game->left_paddle;
    Ball* ball = &game->ball;

    erase();
    mvprintw(2, screen_get_x(screen) / 2 - 2, "%i | %i", paddle_get_score(right_paddle), paddle_get_score(left_paddle));
    mvvline(0, screen_get_x(screen) / 2, ACS_VLINE, screen_get_y(screen));
    attron(COLOR_PAIR(1));
    mvprintw(ball_get_y(ball), ball_get_x(ball), "O");
    
    for(int i = -1; i < 2; ++i){
        mvprintw(paddle_get_y(right_paddle) + i, paddle_get_x(right_paddle), "|");
        mvprintw(paddle_get_y(left_paddle) + i, paddle_get_x(left_paddle), "|");
    }

    attroff(COLOR_PAIR(1));
}