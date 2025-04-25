#include "screen.h"

void main() {
    const char *message = "42";
    // const char *message = "42 nthimoni acerdan";

    screen_buffer = (unsigned short *)VGA_ADDRESS;
    // mémoire est mappée dans le segment de mémoire à l'adresse 0xB8000
    print_str(message, WHITE);
    // clear_screen();
    // print_new_line();
    // print_str(message, RED);
    // print_new_line();
    // print_str(message, YELLOW);
    // print_new_line();
    // print_str(message, GREEN);
    // print_new_line();
}
