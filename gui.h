#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void drawOutputField(SDL_Renderer* renderer, TTF_Font* font, int sum);
void renderText(SDL_Renderer* renderer, const char* text, int x, int y, TTF_Font* font);

#endif // GUI_H