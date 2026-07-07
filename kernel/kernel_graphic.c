#include "../include/vga.h"

void draw_rect(int x, int y, int w, int h, unsigned char color) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            put_pixel(x + i, y + j, color);
        }
    }
}

void clear_screen(unsigned char color) {
    for (int y = 0; y < 200; y++) {
        for (int x = 0; x < 320; x++) {
            put_pixel(x, y, color);
        }
    }
}
