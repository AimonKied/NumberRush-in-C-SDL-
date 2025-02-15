#include "grid.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int numbers[GRID_SIZE][GRID_SIZE];  // Deklaration des externen Arrays

static int initialized = 0;

// Funktion zum Zeichnen des 8x8 Rasters
void drawGrid(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 169, 169, 169, 255);  // Grau

    // Gitter zeichnen
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            SDL_Rect cell = {col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            SDL_RenderFillRect(renderer, &cell);
        }
    }
}

// Funktion zum Zeichnen des Rasters mit zufälligen Zahlen zwischen 0 und 9
void drawGridWithNumbers(SDL_Renderer* renderer, TTF_Font* font, int selectedRow, int selectedCol) {
    if (!initialized) {
        // Initialisiere den Zufallszahlengenerator
        srand(time(NULL));

        // Zufällige Zahlen zwischen 0 und 9 generieren
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int col = 0; col < GRID_SIZE; col++) {
                numbers[row][col] = rand() % 10;
            }
        }
        initialized = 1;
    }

    char numStr[3];  // String für Zahlen, Größe 3 für Nullterminierung

    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (row == selectedRow && col == selectedCol) {
                SDL_SetRenderDrawColor(renderer, 130, 130, 130, 255);  // Grau für ausgewählte Zelle
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Weiß für normale Zellen
            }
            SDL_Rect cell = {col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            SDL_RenderFillRect(renderer, &cell);

            // Zahl aus dem Array holen
            snprintf(numStr, sizeof(numStr), "%d", numbers[row][col]);
            renderText(renderer, numStr, col * CELL_SIZE + 20, row * CELL_SIZE + 20, font);
        }
    }
}
