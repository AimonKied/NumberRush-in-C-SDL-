#ifndef CALCULATIONMODE_H
#define CALCULATIONMODE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void handleCalculationMode(SDL_Renderer* renderer, TTF_Font* font, int* quit, int* selectedRow, int* selectedCol, int* sum);

#endif // CALCULATIONMODE_H