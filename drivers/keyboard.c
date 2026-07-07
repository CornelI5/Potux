#include "../include/keyboard.h"
#include "../include/io.h"

void keyboard_handler() {
    uint8_t scancode = inb(0x60);

    if (scancode == 0x0E) {
    } else if (scancode < 0x80) {
    }

    outb(0x20, 0x20); 
}
