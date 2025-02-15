#include "editmode.h"
#include "grid.h"
#include "event_handler.h"  // Einbindung der Event-Handler-Datei

extern int numbers[GRID_SIZE][GRID_SIZE];  // Deklaration des externen Arrays

// Funktion zum Austauschen von Zahlen
void swapNumbers(int row1, int col1, int row2, int col2) 
{
    printf("Swapping numbers at (%d, %d) and (%d, %d)\n", row1, col1, row2, col2);
    int temp = numbers[row1][col1];
    numbers[row1][col1] = numbers[row2][col2];
    numbers[row2][col2] = temp;
}

void handleEditMode(SDL_Renderer* renderer, TTF_Font* font, int* quit, int* selectedRow, int* selectedCol) {
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
                    // Zahlen tauschen, unabhängig davon, ob sie benachbart sind
                    swapNumbers(*selectedRow, *selectedCol, row, col);
                    *selectedRow = -1;
                    *selectedCol = -1;
                }
            }
        }
    }

    // Bildschirm mit weißem Hintergrund füllen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Weiß
    SDL_RenderClear(renderer);

    // Gitter mit Zahlen zeichnen und ausgewählte Zelle hervorheben
    drawGridWithNumbers(renderer, font, *selectedRow, *selectedCol);
}
