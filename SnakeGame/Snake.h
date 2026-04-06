#pragma once

#include <deque>
#include "raylib.h"
#include "Gameconfig.h"
#include "EventBus.h"
#include "SpriteSheet.h"

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
private:
    GameConfig gameConfig;
    EventBus& bus;
    std::deque<Vector2Int> snake_body;
    Direction current_direction = Direction::UP;
    const SnakeTextures* textures = nullptr;

    void drawHead(int cellSize);
    void drawTail(int cellSize);
    void drawBody(size_t index, int cellSize);

public:
    Snake(const GameConfig& gameConfig, EventBus& bus);

    void setTextures(const SnakeTextures* tex);
    void draw();
    void move();
    void grow();

    const Vector2Int& getHeadPosition() const;
    const std::deque<Vector2Int>& getBody() const;
};