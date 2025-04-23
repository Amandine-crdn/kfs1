#include "screen.h"


// void update_screen(unsigned int place)
// {
//     unsigned int len_buffer = kstrlen(buffer);

//     if (len_buffer <= ROWS_COUNT * COLUMNS_COUNT) 
//     {
//         for (unsigned int i = 0; i < len_buffer; i++)
//         {
//             // screen_buffer[i] = buffer[i] | (unsigned short)WHITE << 8;
//             screen_buffer[i] = buffer[i] | (unsigned short)buffer_color[i] << 8;
//         }
//     }
//     else 
//     {
//         unsigned int start = COLUMNS_COUNT * place;
//         for (unsigned int i = start, y = 0; ( i < ( ROWS_COUNT * COLUMNS_COUNT ) - start ) || ( buffer[start] ); i++, y++)
//         {
//             screen_buffer[y] = buffer[i] | (unsigned short)GREEN << 8;
//         }
//     }
// }
