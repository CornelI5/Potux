#include "../include/io.h"

void init_timer(uint32_t freq) {
    uint32_t divisor = 1193180 / freq;

    outb(0x43, 0x36);

    outb(0x40, (uint8_t)(divisor & 0xFF));
    outb(0x40, (uint8_t)((divisor >> 8) & 0xFF));
}
