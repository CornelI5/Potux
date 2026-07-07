#include "../include/vga.h"

#define VGA_ADDRESS 0xA0000
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

void put_pixel(int x, int y, unsigned char color) {
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
        unsigned char *vga_memory = (unsigned char*)VGA_ADDRESS;
        vga_memory[(y * SCREEN_WIDTH) + x] = color;
    }
}
