#include "screen.h"

// unsigned int cursor_index;
unsigned int place = 1;

// Fonction pour lire un octet depuis un port d'entrée/sortie
unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

// Fonction pour lire une touche du clavier
unsigned char read_keyboard() {
    // Lire le port de statut du clavier (0x64)
    while (!(inb(0x64) & 0x01)) {
        // Attendre jusqu'à ce qu'une touche soit disponible
    }
    // Lire le port de données du clavier (0x60)
    return inb(0x60);
}

// Fonction pour capturer les événements de touche
void handle_keypress() {
    unsigned char key;
    while (1) {
        key = read_keyboard();
        if (key == 0x48) { // Code de la touche flèche haut
            place += 1;
            // screen_buffer[0] = 'Q' | (unsigned short)WHITE << 8;
            update_screen(1);
             // scroll up
        } else if (key == 0x50) { // Code de la touche flèche bas
            update_screen(2);
            // screen_buffer[0] = 'T' | (unsigned short)YELLOW << 8;
            if (place > 1) // scroll down
            {
                place -= 1;

            }
        }
        // update_screen(5);
    }
}

void update_screen(unsigned int place)
{
    unsigned int len_buffer = kstrlen(buffer);

    if (len_buffer <= ROWS_COUNT * COLUMNS_COUNT) 
    {
        for (unsigned int i = 0; i <= len_buffer; i++)
        {
            screen_buffer[i] = buffer[i] | (unsigned short)GREEN << 8;
        }
    }
    else 
    {
        unsigned int start = COLUMNS_COUNT * place;
        for (unsigned int i = start, y = 0; (i < (ROWS_COUNT * COLUMNS_COUNT) - start) || (buffer[start]); i++, y++)
        {
            screen_buffer[y] = buffer[i] | (unsigned short)RED << 8;
        }
    }
}
