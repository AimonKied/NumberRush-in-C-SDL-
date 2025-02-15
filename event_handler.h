#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef enum {
    EDIT_MODE,
    CALCULATION_MODE
} Mode;

void handleEvents(SDL_Renderer* renderer, TTF_Font* font, int* quit, Mode* mode, int* selectedRow, int* selectedCol);
void swapNumbers(int row1, int col1, int row2, int col2);  // Deklaration der Funktion swapNumbers

#endif // EVENT_HANDLER_H