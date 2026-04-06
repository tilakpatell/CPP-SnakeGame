#include "Grid.h"

Grid::Grid(const GameConfig& gameConfig) : gameConfig(gameConfig) {}

void Grid::loadTextures(const char* lightFile, const char* darkFile) {
    lightTexture = LoadTexture(lightFile);
    darkTexture = LoadTexture(darkFile);
}

void Grid::drawGrid() {
    int cellSize = gameConfig.getCellSize();
    for (int row = 0; row < gameConfig.getRows(); ++row) {
        for (int column = 0; column < gameConfig.getCols(); ++column) {
            Texture2D& tex = ((row + column) % 2 == 0) ? lightTexture : darkTexture;
            Rectangle source = { 0, 0, (float)tex.width, (float)tex.height };
            Rectangle dest = {
                (float)(column * cellSize),
                (float)(row * cellSize),
                (float)cellSize,
                (float)cellSize
            };
            DrawTexturePro(tex, source, dest, { 0, 0 }, 0.0f, WHITE);
        }
    }
}

void Grid::unloadTextures() {
    UnloadTexture(lightTexture);
    UnloadTexture(darkTexture);
}