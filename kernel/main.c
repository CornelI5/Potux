#include "../include/vga.h"

extern void init_idt();
extern void remap_pic();
extern void draw_line(int x0, int y0, int x1, int y1, unsigned char color);
extern void clear_screen(unsigned char color);

void kmain(void) {
    remap_pic();
    init_idt();
    
    vga_init();
    clear_screen(0x00);
    
    draw_line(0, 0, 319, 0, 0x0F); 
    draw_line(0, 0, 0, 199, 0x0F); 
    draw_line(319, 0, 319, 199, 0x0F); 
    draw_line(0, 199, 319, 199, 0x0F); 

    __asm__ volatile ("sti");
    while(1) {
        __asm__ volatile ("hlt");
    }
}
