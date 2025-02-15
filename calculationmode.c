#include "calculationmode.h"
#include "grid.h"

extern int numbers[GRID_SIZE][GRID_SIZE];  // Deklaration des externen Arrays

void handleCalculationMode(SDL_Renderer* renderer, TTF_Font* font, int* quit) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            *quit = 1;
        }
    }

    // Bildschirm mit weißem Hintergrund füllen
    SDL_SetRenderDrawColor(renderer, 230, 230, 230, 255); // Grau
    SDL_RenderClear(renderer);

    // Gitter mit Zahlen zeichnen
    drawGridWithNumbers(renderer, font, -1, -1);
}