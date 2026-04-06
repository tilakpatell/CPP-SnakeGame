#include "Grid.h"

Grid::Grid(const GameConfig& gameConfig) : gameConfig(gameConfig) {}

void Grid::drawGrid() {
    int cellSize = gameConfig.getCellSize();
    Color color = gameConfig.getBackgroundColor();

    for (int row = 0; row < gameConfig.getRows(); ++row) {
        for (int column = 0; column < gameConfig.getCols(); ++column) {
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, color);
		}
    }
}