#ifndef _GAME_H
#define _GAME_H

typedef struct {
    int x, y;
    int speed;
    int alive;
} Airplane;

typedef struct {
    int x, y;
    int active;
} MapObstacle;

void init_game();
void update_game_physics();
void render_game_frame();
void handle_game_input(unsigned char scancode);

#endif
