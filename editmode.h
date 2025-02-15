#ifndef EDITMODE_H
#define EDITMODE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void handleEditMode(SDL_Renderer* renderer, TTF_Font* font, int* quit, int* selectedRow, int* selectedCol);
void swapNumbers(int row1, int col1, int row2, int col2);  // Deklaration der Funktion swapNumbers

#endif // EDITMODE_H