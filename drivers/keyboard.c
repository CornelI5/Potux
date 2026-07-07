#include "../include/keyboard.h"
#include "../include/io.h"

static char *video_memory = (char*)0xB8000;
static int cursor_pos = 0;

void keyboard_handler() {
    uint8_t scancode = inb(KBD_DATA_PORT);

    if (scancode < 0x80) {
        
        if (scancode == KBD_BACKSPACE) {
            if (cursor_pos > 0) {
                cursor_pos--;
                video_memory[cursor_pos * 2] = ' ';
            }
        } 
        else if (scancode == KBD_ENTER) {
            cursor_pos = (cursor_pos / 80 + 1) * 80;
        }
        else {
            char c = scancode_map[scancode];
            if (c != 0) {
                video_memory[cursor_pos * 2] = c;
                video_memory[cursor_pos * 2 + 1] = 0x07; )
                cursor_pos++;
            }
        }
    }

    outb(0x20, 0x20);
}
