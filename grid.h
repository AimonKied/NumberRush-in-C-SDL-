#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define GRID_SIZE 8
#define CELL_SIZE 70

void drawGrid(SDL_Renderer* renderer);
void drawGridWithNumbers(SDL_Renderer* renderer, TTF_Font* font, int selectedRow, int selectedCol);
void renderText(SDL_Renderer* renderer, const char* text, int x, int y, TTF_Font* font);  // Deklaration der Funktion renderText

#endif // GRID_H
