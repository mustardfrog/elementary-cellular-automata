#include <SDL2/SDL.h>

#include <cstdio>
#include <vector>

#include "Global.hpp"
#include "Cell.hpp"

void drawGrid(SDL_Renderer *renderer) {
    for (int i = 0; i < WINDOW_WIDTH; i += CELL_SIZE) {
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 1);
        SDL_RenderDrawLine(renderer, i, 0, i, WINDOW_HEIGHT);
        SDL_RenderDrawLine(renderer, 0, i, WINDOW_WIDTH, i);
    }
}

int main(int argc, char *argv[]) {

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool quit = false;
    Cell *cell = new Cell();

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("cannot start sdl");
    }

    window = SDL_CreateWindow(
        "CELLULAR AUTOMATA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (window == NULL) {
        printf("m_Window is null");
        quit = true;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    if (renderer == NULL) {
        printf("renderer is null");
        quit = true;
    }
    quit = false;

    while (!quit) {

        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type) {
        case SDL_QUIT:
            quit = true;
            break;

        default:
            break;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        // SDL_RenderClear(renderer);

        // Renderering commandns go in here
        // drawGrid(renderer);
        cell->renderGeneration(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
