#pragma once

#include "Global.hpp"
#include <SDL2/SDL.h>

class Cell {
    public:
        Cell();
        ~Cell();
        int generation;

        int new_cell[40];
        int cells[NUM_CELLS]= {};

        void renderGeneration(SDL_Renderer *renderer);
    private:
        int rules(int a, int b, int c);
        void calculateNewGen();
};
