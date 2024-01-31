#include "../includes/game.h"

void game_init(Game* game) {
    Screen* screen = &game->screen;
    Paddle* right_paddle = &game->right_paddle;
    Paddle* left_paddle = &game->left_paddle;
    Ball* ball = &game->ball;

    screen_init(screen);
    paddle_init(right_paddle, screen_get_x(screen) - 2, screen_get_y(screen) / 2);
    paddle_init(left_paddle, 1, screen_get_y(screen) / 2);
    ball_init(ball, screen_get_x(screen) / 2, screen_get_y(screen) / 2);
    game->end = false;
}

// Game Collisions
void game_collisions(Game* game) {
    Screen* screen = &game->screen;
    Paddle* right_paddle = &game->right_paddle;
    Paddle* left_paddle = &game->left_paddle;
    Ball* ball = &game->ball;
    
    if (game_check_ball_y_collision(game)) {
        ball_change_vertical(ball);
    }

    if (!game_check_ball_x_collision(game)) { 
        return;
    }

    ball_change_horizontal(ball);      
        
    if ((ball_get_y(ball) == paddle_get_y(right_paddle) - 1) 
        || (ball_get_y(ball) == paddle_get_y(left_paddle) - 1)) {
        ball_set_vertical(ball, false);
    } else if ((ball_get_y(ball) == paddle_get_y(right_paddle) + 1) 
            || (ball_get_y(ball) == paddle_get_y(left_paddle) + 1)) {
        ball_set_vertical(ball, true);
    } else if ((ball_get_y(ball) != paddle_get_y(right_paddle)) 
            && (ball_get_y(ball) != paddle_get_y(left_paddle))) {
        (ball_get_x(ball) >= screen_get_x(screen) - 2) ? paddle_increment_score(right_paddle) 
                                                        : paddle_increment_score(left_paddle);
        game_reset_ball(game);
    }
}

bool game_check_ball_y_collision(Game* game) {
    Screen* screen = &game->screen;
    Ball* ball = &game->ball;

    return (ball_get_y(ball) == screen_get_y(screen) - 1) || (ball_get_y(ball) == 1);
}

bool game_check_ball_x_collision(Game* game) {
    Screen* screen = &game->screen;
    Ball* ball = &game->ball;

    return (ball_get_x(ball) >= screen_get_x(screen) - 2) || (ball_get_x(ball) <= 2);
}

// Game Input
void game_get_input(Game* game) {
    Paddle* right_paddle = &game->right_paddle;
    Paddle* left_paddle = &game->left_paddle;
    bool* end = &game->end;

    switch (getch()) {
            case KEY_DOWN: 
                paddle_move_down(right_paddle, 1);
                break;
            
            case KEY_UP:   
                paddle_move_up(right_paddle, 1);
                break;

            case 'q':      
                paddle_move_up(left_paddle, 1);
                break;

            case 'a':      
                paddle_move_down(left_paddle, 1);
                break;

            case 'p':      
                getchar(); 
                break;
                
            case 0x1B:    
                endwin(); 
                *end = true; 
                break;
        }
}


// Game Ball
void game_move_ball(Game* game) {
    Ball* ball = &game->ball;
    int new_x, new_y;
    
    new_x = ball_get_horizontal(ball) ? ball_get_x(ball) + 1 : ball_get_x(ball) - 1;
    new_y = ball_get_vertical(ball) ? ball_get_y(ball) + 1 : ball_get_y(ball) - 1;

    ball_set_x(ball, new_x);
    ball_set_y(ball, new_y);
}

void game_reset_ball(Game* game) {
    Screen* screen = &game->screen;
    Ball* ball = &game->ball;
    int new_x, new_y;

    new_x = screen_get_x(screen) / 2;
    new_y = screen_get_y(screen) / 2;

    ball_set_x(ball, new_x);
    ball_set_y(ball, new_y);
}