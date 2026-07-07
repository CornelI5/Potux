#include "../include/io.h"
#include "../include/game.h" 


typedef struct {
    unsigned int ds;                                    
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; 
    unsigned int int_no, err_code;                      
    unsigned int eip, cs, eflags, useresp, ss;           

void interrupt_handler(registers_t regs) {
    
    if (regs.int_no == 32) {
        update_game_physics();
        render_game_frame();
        
        outb(0x20, 0x20);
    }
    
    else if (regs.int_no == 33) {
        unsigned char scancode = inb(0x60);
        
        handle_game_input(scancode);
        
        outb(0x20, 0x20);
    }
}
