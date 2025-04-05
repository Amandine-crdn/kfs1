#include "screen.h"

void main() {
    const char *message = "42 nthimoni acerdan";

    screen_buffer = (unsigned short *) 0xB8000;
    // mémoire est mappée dans le segment de mémoire à l'adresse 0xB8000
    clear_screen();
    print_str(message, WHITE);
    print_new_line();
    print_str(message, RED);
    print_new_line();
    print_str(message, YELLOW);
    print_new_line();
    print_str(message, GREEN);
    print_new_line();
}
