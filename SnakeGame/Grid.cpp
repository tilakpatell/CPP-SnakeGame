#include "Grid.h"

Grid::Grid(int screenWidth, int screenHeight, int cellSize, Color color)
    : cellSize(cellSize),
    cols(screenWidth / cellSize),
    rows(screenHeight / cellSize), 
    color(color) {
}

void Grid::drawGrid() {
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < cols; ++column) {
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, color);
		}
    }
}