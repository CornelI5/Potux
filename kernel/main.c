#include "../include/vga.h"
#include "../include/game.h"

extern void init_idt();
extern void remap_pic();
extern void init_timer(uint32_t freq);

void kmain(void) {
    remap_pic();
    init_idt();
    
    init_timer(30); 

    vga_init();
    init_game(); 

    __asm__ volatile ("sti");
    while(1) {
        __asm__ volatile ("hlt");
    }
}
