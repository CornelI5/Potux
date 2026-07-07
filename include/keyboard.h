#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "io.h" 

#define KBD_DATA_PORT 0x60
#define KBD_CTRL_PORT 0x64

#define KBD_BACKSPACE 0x0E
#define KBD_ENTER     0x1C

void init_keyboard();
void keyboard_handler();

static const char scancode_map[] = {
    0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0,
    0, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 0,
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, 0, 0, ' '
};

#endif
