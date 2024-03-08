#include <iostream>

#include "const.hpp"
#include "game/grid.hpp"


Grid::Grid(void) {}


Grid::Grid(Vector position) {
    this->position = position;

    for (unsigned char row = UINT_ZERO; row < GRID_ROWS; row++) {
        for (unsigned char col = UINT_ZERO; col < GRID_COLUMNS; col++) {      
            grid[row][col] = Cell(Vector(col, row), EMPTY, UINT_ZERO);
        }
    }
}


Cell* Grid::cell_at(Vector position) {
    return &grid[position.y][position.x];
}


void Grid::update(void) {
    Cell* cell;

    for (unsigned char row = UINT_ZERO; row < GRID_ROWS; row++) {
        for (unsigned char col = UINT_ZERO; col < GRID_COLUMNS; col++) {
            
            cell = &grid[row][col];
            cell->update();
        }
    }
}


void Grid::render_background(void) {
    DrawRectangle(position.x, position.y, GRID_COLUMNS * CELL_SIZE, GRID_ROWS * CELL_SIZE, COLORS("GRID"));
}


void Grid::render_cells(Vector snake_direction) {
    Cell* cell;

    for (unsigned char row = UINT_ZERO; row < GRID_ROWS; row++) {
        for (unsigned char col = UINT_ZERO; col < GRID_COLUMNS; col++) {
            
            cell = &grid[row][col];
            cell->render(position, snake_direction);
        }
    }
}