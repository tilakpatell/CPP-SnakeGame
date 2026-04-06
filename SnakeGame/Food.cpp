#include "Food.h"

Food::Food(const GameConfig& gameConfig, const std::deque<Vector2Int>& snakeBody)
    : gameConfig(gameConfig) {
    spawn(snakeBody);
}

void Food::loadTexture(const char* fileName) {
    texture = LoadTexture(fileName);
}

void Food::spawn(const std::deque<Vector2Int>& snakeBody) {
    bool onSnake = true;
    while (onSnake) {
        position.x = GetRandomValue(0, gameConfig.getCols() - 1);
        position.y = GetRandomValue(0, gameConfig.getRows() - 1);

        onSnake = false;
        for (const auto& segment : snakeBody) {
            if (segment.x == position.x && segment.y == position.y) {
                onSnake = true;
                break;
            }
        }
    }
}

void Food::respawn(const std::deque<Vector2Int>& snakeBody) {
    spawn(snakeBody);
}

void Food::draw() {
    int cellSize = gameConfig.getCellSize();
    Rectangle source = { 0, 0, (float)texture.width, (float)texture.height };
    Rectangle dest = {
        (float)(position.x * cellSize),
        (float)(position.y * cellSize),
        (float)cellSize,
        (float)cellSize
    };
    DrawTexturePro(texture, source, dest, { 0, 0 }, 0.0f, WHITE);
}

const Vector2Int& Food::getPosition() const {
    return position;
}

int Food::getScoreValue() const {
    return scoreValue;
}

void Food::unloadTexture() {
    UnloadTexture(texture);
}