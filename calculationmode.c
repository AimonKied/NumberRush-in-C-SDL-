#include "calculationmode.h"
#include "grid.h"
#include "gui.h"  // Einbindung der GUI-Datei

extern int numbers[GRID_SIZE][GRID_SIZE];  // Deklaration des externen Arrays

void handleCalculationMode(SDL_Renderer* renderer, TTF_Font* font, int* quit, int* selectedRow, int* selectedCol, int* sum) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            *quit = 1;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            int row = y / CELL_SIZE;
            int col = x / CELL_SIZE;
            if (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE) {
                if (*selectedRow == -1 && *selectedCol == -1) {
                    *selectedRow = row;
                    *selectedCol = col;
                } else {
                    // Zahlen addieren und Summe berechnen
                    *sum = numbers[*selectedRow][*selectedCol] + numbers[row][col];
                    *selectedRow = -1;
                    *selectedCol = -1;
                }
            }
        }
    }

    // Bildschirm mit grauem Hintergrund füllen
    SDL_SetRenderDrawColor(renderer, 230, 230, 230, 255); // Grau
    SDL_RenderClear(renderer);

    // Gitter mit Zahlen zeichnen
    drawGridWithNumbers(renderer, font, *selectedRow, *selectedCol);

    // Ausgabefeld zeichnen
    drawOutputField(renderer, font, *sum);

    // Bildschirm aktualisieren
    SDL_RenderPresent(renderer);
}