void timer_callback(registers_t regs) {
    static uint32_t tick = 0;
    tick++;

    update_game_physics();
    render_game_frame();
}
