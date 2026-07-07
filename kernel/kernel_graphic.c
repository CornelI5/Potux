#include "../include/vga.h"

void draw_line(int x0, int y0, int x1, int y1, unsigned char color) {
    int dx = (x1 > x0 ? x1 - x0 : x0 - x1);
    int dy = (y1 > y0 ? y1 - y0 : y1 - y0);
    int sx = (x0 < x1 ? 1 : -1);
    int sy = (y0 < y1 ? 1 : -1);
    int err = (dx > dy ? dx : -dy) / 2, e2;

    while (1) {
        put_pixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void clear_screen(unsigned char color) {
    for (int y = 0; y < 200; y++) {
        for (int x = 0; x < 320; x++) {
            put_pixel(x, y, color);
        }
    }
}

void draw_rect(int x, int y, int w, int h, unsigned char color) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            put_pixel(x + i, y + j, color);
        }
    }
}
