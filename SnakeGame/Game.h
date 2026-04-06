#pragma once

#include "raylib.h"
#include "EventBus.h"
#include "Snake.h"
#include "Grid.h"
#include "InputManager.h"
#include "Food.h"
#include "SpriteSheet.h"

enum class GameState {
    GAME_PAUSED,
    GAME_RUNNING,
    GAME_OVER,
};

class Game {
private:
    EventBus bus;
    const GameConfig config;
    InputManager input;
    Snake snake;
    Grid grid;
    Food food;
    SnakeTextures snakeTextures;
    Texture2D gameOverTexture = {};
    int score = 0;
    GameState state = GameState::GAME_RUNNING;
    float moveTimer = 0.15f;

    void update();
    void draw();
    void checkFoodCollision();
    bool checkBoundaryCollision();
    bool checkSnakeCollision();
    void loadTextures();
    void unloadTextures();

public:
    Game(const GameConfig& config);
    void run();
};