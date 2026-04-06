#pragma once

#include <deque>
#include "GameConfig.h"

class Food {
private:
    Vector2Int position;
    int scoreValue = 10;
    GameConfig gameConfig;
    Texture2D texture = {};

    void spawn(const std::deque<Vector2Int>& snakeBody);

public:
    Food(const GameConfig& gameConfig, const std::deque<Vector2Int>& snakeBody);
    void loadTexture(const char* fileName);
    void respawn(const std::deque<Vector2Int>& snakeBody);
    void draw();
    const Vector2Int& getPosition() const;
    int getScoreValue() const;
    void unloadTexture();
};