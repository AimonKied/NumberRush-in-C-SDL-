#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "grid.h"  // Einbindung der Grid-Datei
#include "event_handler.h"  // Einbindung der Event-Handler-Datei

int numbers[GRID_SIZE][GRID_SIZE];  // Definition des externen Arrays

int main() {
    // SDL initialisieren
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL konnte nicht initialisiert werden: %s\n", SDL_GetError());
        return -1;
    }

    // TTF initialisieren
    if (TTF_Init() == -1) {
        printf("SDL_ttf konnte nicht initialisiert werden: %s\n", TTF_GetError());
        SDL_Quit();
        return -1;
    }

    // Fenster erstellen
    SDL_Window* window = SDL_CreateWindow("Number Rush", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 800, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Fenster konnte nicht erstellt werden: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    // Renderer erstellen
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer konnte nicht erstellt werden: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    // Schriftart laden
    TTF_Font* font = TTF_OpenFont("path/to/Poppins-Medium.ttf", 24);
    if (!font) {
        printf("Fehler beim Laden der Schriftart: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    // Event-Loop
    int quit = 0;
    Mode mode = EDIT_MODE;  // Start im Edit Mode
    int selectedRow = -1;
    int selectedCol = -1;
    while (!quit) {
        handleEvents(renderer, font, &quit, &mode, &selectedRow, &selectedCol);
    }

    // Aufräumen
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
