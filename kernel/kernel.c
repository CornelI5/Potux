void kmain(void) {
    const char *str = "POTUX: Unix-Linux Fusion Booting...";
    char *vga = (char*)0xB8000;
    for(int i = 0; str[i] != '\0'; i++) {
        vga[i*2] = str[i];
        vga[i*2+1] = 0x0F; 
    }
    while(1);
}
