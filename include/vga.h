#ifndef _VGA_H
#define _VGA_H

void vga_init();

void put_pixel(int x, int y, unsigned char color);
void draw_rect(int x, int y, int w, int h, unsigned char color);
void clear_screen(unsigned char color);

#endif
