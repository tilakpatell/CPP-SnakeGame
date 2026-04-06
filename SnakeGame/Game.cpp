#include "Game.h"

Game::Game(const GameConfig& gameConfig) : bus(),
config(gameConfig),
input(bus),
snake(this->config, bus),
grid(this->config) {

    bus.subscribe(GameEvent::PAUSE, [this]() {
        if (state == GameState::GAME_RUNNING) {
            state = GameState::GAME_PAUSED;
        }
        else if (state == GameState::GAME_PAUSED)
            state = GameState::GAME_RUNNING;
        });

        bus.subscribe(GameEvent::GAMEOVER, [this]() {
            state = GameState::GAME_OVER;
        });
};

void Game::update() {
    if (state != GameState::GAME_RUNNING) return;

    moveTimer -= GetFrameTime();
    if (moveTimer <= 0.0f) {
        snake.move();
        moveTimer = 0.15f;

        if (snake.checkBoundaryCollision()) {
            bus.publish(GameEvent::GAMEOVER);
        };
    };
};

void Game::draw() {
    BeginDrawing();
    ClearBackground(config.getBackgroundColor());
    grid.drawGrid();
    snake.draw();

    if (state == GameState::GAME_PAUSED) {
        DrawText("PAUSED", config.getScreenWidth() / 2 - 100,
            config.getScreenHeight() / 2, 40, WHITE);
    }

    if (state == GameState::GAME_OVER) {
        DrawText("GAME OVER", config.getScreenWidth() / 2 - 130,
            config.getScreenHeight() / 2, 40, RED);
    }

    EndDrawing();
}

void Game::run() {
    InitWindow(config.getScreenWidth(), config.getScreenHeight(), "Snake Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        input.poll();    
        update();
        draw();
    }

    CloseWindow();
};