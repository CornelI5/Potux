#include "../include/game.h"
#include "../include/vga.h"

static Airplane player;
#define MAX_OBSTACLES 5
static MapObstacle obstacles[MAX_OBSTACLES];

void init_game() {
    player.x = 160; 
    player.y = 150; 
    player.speed = 4;
    player.alive = 1;

    for(int i = 0; i < MAX_OBSTACLES; i++) {
        obstacles[i].x = (i * 60) + 20;
        obstacles[i].y = -(i * 40); 
        obstacles[i].active = 1;
    }
}

void update_game_physics() {
    if (!player.alive) return;

    for(int i = 0; i < MAX_OBSTACLES; i++) {
        if (obstacles[i].active) {
            obstacles[i].y += 2;

            if (obstacles[i].y > 200) {
                obstacles[i].y = 0;
                obstacles[i].x = (obstacles[i].x + 37) % 300; 
            }

            if (obstacles[i].y >= player.y - 4 && obstacles[i].y <= player.y + 8) {
                if (obstacles[i].x >= player.x - 8 && obstacles[i].x <= player.x + 8) {
                    player.alive = 0; 
                }
            }
        }
    }
}

void render_game_frame() {
    clear_screen(0x00);

    if (player.alive) {
        draw_line(player.x, player.y - 6, player.x - 6, player.y + 6, 0x0A); 
        draw_line(player.x, player.y - 6, player.x + 6, player.y + 6, 0x0A); 
        draw_line(player.x - 6, player.y + 6, player.x + 6, player.y + 6, 0x0A); 
    } else {
        draw_line(140, 90, 180, 110, 0x04);
        draw_line(180, 90, 140, 110, 0x04);
        return;
    }

    for(int i = 0; i < MAX_OBSTACLES; i++) {
        if (obstacles[i].active) {
            draw_line(obstacles[i].x, obstacles[i].y, obstacles[i].x + 20, obstacles[i].y, 0x0E); 
        }
    }
}

void handle_game_input(unsigned char scancode) {
    if (!player.alive) {
        if (scancode == 0x13) {
            init_game();
        }
        return;
    }

)
    if (scancode == 0x1E || scancode == 0x4B) { 
        if (player.x > 10) player.x -= player.speed;
    }
    if (scancode == 0x20 || scancode == 0x4D) { 
        if (player.x < 310) player.x += player.speed;
    }
}
