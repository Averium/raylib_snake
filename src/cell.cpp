#include "cell.h"
#include "debug.h"


Cell::Cell() {
    set_state(EMPTY, 0U);
}


Cell::Cell(celltype type, unsigned int counter) {
    set_state(type, counter);
}


void Cell::set_state(celltype type, unsigned int counter) {
    this->type = type;
    this->counter = counter;
}


void Cell::update(void) {
    if (counter > 0U) {
        counter--;
    }
    else {
        counter = 0U;
        type = EMPTY;
    }
}


void Cell::render(unsigned char row, unsigned char col) {
    Vector screen_pos = grid2screen(row, col);
    
    switch (type) {

    case SNAKE_BODY:
        DrawRectangle(screen_pos.x, screen_pos.y, CELL_SIDE, CELL_SIDE, COLORS::SNAKE);
        break;
        
    case SNAKE_HEAD:
        DrawRectangle(screen_pos.x, screen_pos.y, CELL_SIDE, CELL_SIDE, COLORS::SNAKE);
        break;

    case APPLE:
        DrawRectangle(screen_pos.x, screen_pos.y, CELL_SIDE, CELL_SIDE, COLORS::APPLE);
        break;

    default:
        break;
        
    }
}


Vector Cell::grid2screen(unsigned char row, unsigned char col) {
    return Vector(col * CELL_SIZE - CELL_GAP, row * CELL_SIZE - CELL_GAP);
}