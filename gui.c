#include "gui.h"

void drawOutputField(SDL_Renderer* renderer, TTF_Font* font, int sum) {
    // Ausgabefeld zeichnen
    SDL_Rect outputField = {800, 100, 180, 50};  // Position und Größe des Ausgabefelds
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Weiß für das Ausgabefeld
    SDL_RenderFillRect(renderer, &outputField);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Schwarz für den Rahmen
    SDL_RenderDrawRect(renderer, &outputField);

    // Summe anzeigen
    if (sum != -1) {
        char sumStr[10];
        snprintf(sumStr, sizeof(sumStr), "Sum: %d", sum);
        renderText(renderer, sumStr, 810, 110, font);  // Position der Summe im Ausgabefeld
    }
}

void renderText(SDL_Renderer* renderer, const char* text, int x, int y, TTF_Font* font) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, (SDL_Color){0, 0, 0, 255});
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    
    SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}