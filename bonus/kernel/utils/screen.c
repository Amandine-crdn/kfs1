#include "screen.h"

unsigned short* screen_buffer;
unsigned int cursor_index = 0;
unsigned int total_row = 0;
// char *buffer;
// char *buffer_color;


    // le premier octet est le caractère lui-même (selon le code ASCII)
    // le second octet contient des informations sur la couleur de fond et la couleur du texte.
    // Bits 0-3 : Couleur du texte (ex: 0x07 = blanc).
    // Bits 4-7 : Couleur de fond (ex: 0x00 = fond noir).

int print_char(char c, unsigned char color)
{
    
    screen_buffer[cursor_index] = c | (unsigned short)color << 8;
    cursor_index++;
}


void print_str(char *s, unsigned char color)
{
    unsigned int i = 0;
    unsigned int len_buffer = kstrlen(s);
    unsigned int temp;

    // si plus grand que lecran afficher le bas direct
    if ( len_buffer >= ROWS_COUNT * COLUMNS_COUNT )
    {
        i = len_buffer - (ROWS_COUNT * COLUMNS_COUNT);
        cursor_index = 0;
    }

    // si ecran deja plein scrolling en cours sur laffichage precedent en memoire
    else if (cursor_index >= ROWS_COUNT * COLUMNS_COUNT)
    {
        temp = len_buffer;
        cursor_index = 0;

        while (temp < (ROWS_COUNT * COLUMNS_COUNT))
        {
            screen_buffer[cursor_index] = screen_buffer[temp];
            cursor_index++; 
            temp++;
        }
    }

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
    int nb = (COLUMNS_COUNT - (cursor_index % COLUMNS_COUNT));
    // cursor_index += COLUMNS_COUNT - ((cursor_index) % COLUMNS_COUNT);
    // nb=65;
// 
    // kprintf("index %d", nb);
    while (nb > 0)
    {
        print_str(" ", WHITE);
        nb--;
    }
}

int clear_screen()
{
    for (unsigned int i = 0; i < (ROWS_COUNT * COLUMNS_COUNT); i++)
    {
        print_char(' ', WHITE);
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
