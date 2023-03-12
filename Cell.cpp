#include "Cell.hpp"
#include "Global.hpp"

Cell::Cell() {
    generation = 0;
    cells[NUM_CELLS/2] = 1;
}

int Cell::rules(int a, int b, int c) { 
    int ruleset[] = {1,1,0,1,1,1,0,0};
    if      (a == 1 && b == 1 && c == 1) return ruleset[0];
    else if (a == 1 && b == 1 && c == 0) return ruleset[1];
    else if (a == 1 && b == 0 && c == 1) return ruleset[2];
    else if (a == 1 && b == 0 && c == 0) return ruleset[3];
    else if (a == 0 && b == 1 && c == 1) return ruleset[4];
    else if (a == 0 && b == 1 && c == 0) return ruleset[5];
    else if (a == 0 && b == 0 && c == 1) return ruleset[6];
    else if (a == 0 && b == 0 && c == 0) return ruleset[7];

    return 0;
}

void Cell::calculateNewGen() {
    int *newCell = new int[NUM_CELLS];

    for (int i = 1; i < NUM_CELLS  - 1; i++) {
        int left   = cells[i-1];
        int middle = cells[i];
        int right = cells[i + 1];
        int newstate = rules(left, middle, right);

        newCell[i] = newstate;
    }
    for (int i = 1; i < NUM_CELLS  - 1; i++) {
        cells[i] = newCell[i];
    }
}

void Cell::renderGeneration(SDL_Renderer *renderer) {

    SDL_Delay(50);

    // printf("GENERATION:: %d\n", generation);
    calculateNewGen();
    for (int i = 0; i <= NUM_CELLS; ++i) {
        if (generation >= NUM_CELLS  ) break;
        SDL_Rect cell_rect = {i * CELL_SIZE,  generation * CELL_SIZE, CELL_SIZE, CELL_SIZE};
        if (cells[i] == 1) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        }
        SDL_RenderFillRect(renderer, &cell_rect);
    }
     generation += 1;
}

