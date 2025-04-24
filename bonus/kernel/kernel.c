#include "screen.h"
#include "keyboard.h"
#include "ft_printf.h"

void send_message()
{
    // print_new_line();
    // print_new_line();
    // print_new_line();
    // print_new_line();
    // print_new_line();
    // print_new_line();
    // print_new_line();
    // print_str("START 1 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment /2 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment allez/ Bien le bonjour gente dame comment allezBien le bonjour gente dame comment allez/vous ? Mea culpa 42 80 ??fffffffffffffffffAAAAAAAAAAAAAAAAAAAAAAAAAAAAffffffffffffffffffAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaaffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffjattends les 80      ffffffffffffffffffffffffffffffffffffffffffffffff42fff     HEEEEYYY ffffffffff42fffaaaqq", YELLOW);
    // print_new_line();
    // print_str("coucouder\n", YELLOW);
    // print_str("10\n", GREEN);
    // print_str("  e dame comment allezBien le bonjour gente dame commen   ffffffffffffffffffffffffffffffffffffffffffffffff42fff     HEEEEYYY ffffffffff42fffaaaqq", WHITE);
    // print_new_line();
    // print_new_line();
    // print_new_line();
    // print_new_line();
    // print_str(" 10", RED);
    // print_str("10\n", GREEN);
    // print_str("coucouder", YELLOW);
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
    clear_screen();
    unsigned short tmp[ROWS_COUNT * COLUMNS_COUNT*2];
    
    stock = tmp;
}


void main()
{
    set_cursor_offset(0);
    init_screens();
    send_message();
    // keyboard_interrupt_handler();
    handle_keyboard();
    // clear_screen();
}

 // char *message = "42 nthimoni acerdan";
    // init_buffers();
    // char tmp[ROWS_COUNT * COLUMNS_COUNT*2];
    // buffer = tmp;
    // char tmp2[ROWS_COUNT * COLUMNS_COUNT*2];
    // buffer_color = tmp2;

    // buffer[50000];
// kprintf("total_row; %d", total_row);
    // update_screen();
    // char *message1 = "1 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment /";
    // print_str("1 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment /", RED);
    // print_str("1 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment /", GREEN);
    // print_str("1 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment /", YELLOW);
    // print_str("1 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment /", YELLOW);
    // print_str("42ffffffffffffff42ffff42ff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42fffaaaqq", RED);
    // kprintf("coucou %d %s %d %s", 10, "coucou", 42, "ciao");
    // print_str("START 1 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment /2 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment allez/ Bien le bonjour gente dame comment allezBien le bonjour gente dame comment allez/vous ? Mea culpa 42 80 ??fffffffffffffffffAAAAAAAAAAAAAAAAAAAAAAAAAAAAffffffffffffffffffAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaaffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffjattends les 80      ffffffffffffffffffffffffffffffffffffffffffffffff42fff     HEEEEYYY ffffffffff42fffaaaqq", YELLOW);
    // print_new_line();
    // print_str(" coucou", RED);
    
    // print_char('u', YELLOW);
    //  int nb = (COLUMNS_COUNT - (cursor_index % COLUMNS_COUNT));
    // cursor_index += COLUMNS_COUNT - ((cursor_index) % COLUMNS_COUNT);
    
// 
    // kprintf("index %d", nb);    

    // print_str(" 10", GREEN);
    // print_str("START 1 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment /2 Bien le bonjour gente dame comment allezBien le bonjour gente dame comment allez/ Bien le bonjour gente dame comment allezBien le bonjour gente dame comment allez/vous ? Mea culpa 42 80 ??fffffffffffffffffAAAAAAAAAAAAAAAAAAAAAAAAAAAAffffffffffffffffffAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaaffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffffffffffffffffffffffffffffffffffffffffffffffffff42ffjattends les 80      ffffffffffffffffffffffffffffffffffffffffffffffff42fff     HEEEEYYY ffffffffff42fffaaaqq", YELLOW);

    // print_str(" 20", YELLOW);
    // print_new_line();
    // print_str(" 20", YELLOW);



    // print_new_line();
    // print_str("coucou\n", YELLOW);
    // print_str("42\n", WHITE);
    // print_str("ciao", GREEN);

    // print_str(message, WHITE);
    // print_new_line();
    // print_str(message, RED);
    // print_new_line();
    // print_str(message, YELLOW);
    // print_new_line();
    // print_str(message, GREEN);
    // print_new_line();