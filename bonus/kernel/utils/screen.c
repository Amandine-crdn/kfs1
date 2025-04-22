#include "screen.h"

unsigned short* screen_buffer;
unsigned int cursor_index = 0;
unsigned int total_row = 0;
char *buffer;

int print_char(char c, unsigned char color)
{
    // screen_buffer[cursor_index] = c | (unsigned short)color << 8;
    buffer[cursor_index] = c ;
    cursor_index++;
    if (cursor_index % COLUMNS_COUNT == 0)
    {
        total_row += 1;
    }

    // le premier octet est le caractère lui-même (selon le code ASCII)
    // le second octet contient des informations sur la couleur de fond et la couleur du texte.
    // Bits 0-3 : Couleur du texte (ex: 0x07 = blanc).
    // Bits 4-7 : Couleur de fond (ex: 0x00 = fond noir).
}


void print_str(const char *s, unsigned char color)
{
    int i = 0;
    while (s[i]) 
    {
        if (s[i] == '\n')
        {
            print_new_line();
        }
        print_char(s[i], color);
        i++;
    }
    update_screen(1);
    // print_str(row_index, WHITE);
}

void print_new_line()
{
    cursor_index += COLUMNS_COUNT - ((cursor_index) % COLUMNS_COUNT);
}

int clear_screen()
{
    for (unsigned int i = 0; i < (ROWS_COUNT * COLUMNS_COUNT); i++)
    {
        screen_buffer[i] = 0;
    }
    cursor_index = 0;
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
