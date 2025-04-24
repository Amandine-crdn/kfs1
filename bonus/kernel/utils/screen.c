#include "screen.h"
#include "ft_printf.h"

unsigned short* screen_buffer;
unsigned short *stock;
unsigned int cursor_index = 0;
unsigned int total_row = 0;
unsigned char scancode = 0;

int print_char(char c, unsigned char color)
{
    if (c != '\n') {
        screen_buffer[cursor_index] = c | (unsigned short)color << 8;
        stock[cursor_index] = c | (unsigned short)color << 8;
        cursor_index++;
    } else {
        print_new_line();
    }
    // le premier octet est le caractère lui-même (selon le code ASCII)
    // le second octet contient des informations sur la couleur de fond et la couleur du texte.
    // Bits 0-3 : Couleur du texte (ex: 0x07 = blanc).
    // Bits 4-7 : Couleur de fond (ex: 0x00 = fond noir).

    
    if (cursor_index % COLUMNS_COUNT == 0)
    {
        total_row++;
    }
    if (total_row > ROWS_COUNT)
    {
        scroll_screen();
    }
    else
    {
        update_cursor();
    }
    
    return 0;
}



void print_str(char *s, unsigned char color)
{
    unsigned int i = 0;

    while (s[i]) 
    {
        if (s[i] == '\n')
        {
            print_new_line();
        }
        else 
        {
            print_char(s[i], color);
        }
        i++;
    }
}

int print_str_n(char *s, unsigned char color, unsigned int n)
{
    int index = 0;
    while (s[index] && index < n) 
    {
        print_char(s[index], color);
        index++;
    }
    // update_screen(1);
    return index;
}

void print_new_line()
{

    if (cursor_index % COLUMNS_COUNT == 0)
    {
        // + 80 = Ligne suivante si debut de ligne
        cursor_index += COLUMNS_COUNT;
    }
    else
    {
        cursor_index += COLUMNS_COUNT - ((cursor_index) % COLUMNS_COUNT);
    }
    total_row++;
    if (total_row > ROWS_COUNT)
    {
        scroll_screen();
    }
    else 
    {
        update_cursor();
    }
}

int clear_screen()
{
    cursor_index = 0;
    total_row = 0;
    for (unsigned int i = 0; i < (ROWS_COUNT * COLUMNS_COUNT); i++)
    {
        print_char(' ', WHITE);
    }
    cursor_index = 0;
    total_row = 0;
    update_cursor();
    return 0;
}

int kstrlen(char *s)
{
    char *new = s;
    while (*new)
    {
        new++;
    }
    return new - s;
}

static inline void outb(int port, int value) {
    // outb is a macro that writes a byte to the port
    asm volatile ("outb %%al, %%dx" : : "a"(value), "d"(port));
}


void set_cursor_offset(int offset) 
{
    outb(0x3D4, 0x0F); // LOW BYTE
    outb(0x3D5, (uint8_t)(offset & 0xFF));

    outb(0x3D4, 0x0E); // HIGH BYTE
    outb(0x3D5, (uint8_t)((offset >> 8)));
}
void update_cursor() {
    set_cursor_offset(cursor_index);
}

void set_cursor(int x, int y) 
{
    unsigned short position = y * COLUMNS_COUNT + x;
    set_cursor_offset(position);
}
