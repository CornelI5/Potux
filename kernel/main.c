#include "../include/io.h"
#include "../include/keyboard.h"

extern void init_idt();
extern void remap_pic();

void kmain(void) {
    const char *welcome = "Welcome to POTUX v0.1 (Unix-Linux Fusion)";
    char *vga = (char*)0xB8000;
    for(int i = 0; welcome[i] != '\0'; i++) {
        vga[i*2] = welcome[i];
        vga[i*2+1] = 0x0F;
    }

    remap_pic();
    init_idt();

    __asm__ volatile ("sti");

    while(1) {
        __asm__ volatile ("hlt"); 
    }
}
