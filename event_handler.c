#include "event_handler.h"
#include "grid.h"
#include "editmode.h"
#include "calculationmode.h"
#include "gui.h"

extern int numbers[GRID_SIZE][GRID_SIZE];  // Deklaration des externen Arrays

void handleEvents(SDL_Renderer* renderer, TTF_Font* font, int* quit, Mode* mode, int* selectedRow, int* selectedCol) {
    static int sum = -1;  // Variable zur Speicherung der Summe

    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            *quit = 1;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);

            // Check if the Edit Mode button is clicked
            if (x >= 600 && x <= 700 && y >= 10 && y <= 50) {
                *mode = EDIT_MODE;
                sum = -1;  // Summe zurücksetzen, wenn der Modus gewechselt wird
            }
            // Check if the Calculation Mode button is clicked
            else if (x >= 720 && x <= 820 && y >= 10 && y <= 50) {
                *mode = CALCULATION_MODE;
                sum = -1;  // Summe zurücksetzen, wenn der Modus gewechselt wird
            }
        }

        // Bildschirm mit weißem Hintergrund füllen
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Weiß
        SDL_RenderClear(renderer);

        // Je nach Modus den entsprechenden Handler aufrufen
        if (*mode == EDIT_MODE) {
            handleEditMode(renderer, font, quit, selectedRow, selectedCol);
        } else if (*mode == CALCULATION_MODE) {
            handleCalculationMode(renderer, font, quit, selectedRow, selectedCol, &sum);
        }    

        // Buttons zeichnen
        SDL_Rect editButton = {600, 10, 100, 40};  // Position und Größe des Edit Mode Buttons
        SDL_Rect calcButton = {720, 10, 100, 40}; // Position und Größe des Calculation Mode Buttons
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rot für Edit Mode Button
        SDL_RenderFillRect(renderer, &editButton);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Grün für Calculation Mode Button
        SDL_RenderFillRect(renderer, &calcButton);

        // Text auf den Buttons rendern
        renderText(renderer, "Edit Mode", 610, 15, font);
        renderText(renderer, "Calc Mode", 730, 15, font);

        // Bildschirm aktualisieren
        SDL_RenderPresent(renderer);
    }
}

