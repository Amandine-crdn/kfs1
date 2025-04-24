#include "screen.h"
#include "keyboard.h"
#include "ft_printf.h"

void send_message()
{
     char *message = "%d nthimoni acerdan\n";
    kprintf(message, 42);
    print_str("42 nthimoni acerdan\n", GREEN);
    print_str("42 nthimoni acerdan\n", RED);
    print_str("42 nthimoni acerdan\n", YELLOW);

}

void init_screens()
{
    // mémoire est mappée dans le segment de mémoire à l'adresse 0xB8000
    screen_buffer = (unsigned short *)VGA_ADDRESS;
    for (int i = 0; i < SCREEN_COUNT; i++) {
        switch_screen(i);
        clear_screen();
        print_str("Welcome ", WHITE);

        kprintf("to screen %d !\n", i + 1);
    }
    switch_screen(0);
}

void switch_screen(int new_screen_index)
{
    if (new_screen_index < 0 || new_screen_index >= SCREEN_COUNT)
        return ;

    stock_cursor_index[screen_index] = cursor_index;
    screen_index = new_screen_index;
    cursor_index = stock_cursor_index[screen_index];
    display_screen(screen_index);
}
int display_screen(int screen_index)
{
    if (screen_index < 0 || screen_index >= SCREEN_COUNT)
        return ;
    // DISPLAY SCREEN

}


void main()
{
    set_cursor_offset(0);
    init_screens();
    // send_message();
    // keyboard_interrupt_handler();
    handle_keyboard();
}