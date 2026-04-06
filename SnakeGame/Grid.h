#pragma once

#include "raylib.h"
#include "GameConfig.h"

class Grid {
private:
    GameConfig gameConfig;
    Texture2D lightTexture = {};
    Texture2D darkTexture = {};
public:
    Grid(const GameConfig& gameConfig);
    void loadTextures(const char* lightFile, const char* darkFile);
    void drawGrid();
    void unloadTextures();
};