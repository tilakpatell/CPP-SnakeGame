#include "Game.h"

Game::Game(const GameConfig& gameConfig) : bus(),
config(gameConfig),
input(bus),
snake(this->config, bus),
grid(this->config),
food(this->config, snake.getBody()) {

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
}

void Game::loadTextures() {
    snakeTextures.head_up = LoadTexture("Graphics/head_up.png");
    snakeTextures.head_down = LoadTexture("Graphics/head_down.png");
    snakeTextures.head_left = LoadTexture("Graphics/head_left.png");
    snakeTextures.head_right = LoadTexture("Graphics/head_right.png");

    snakeTextures.tail_up = LoadTexture("Graphics/tail_up.png");
    snakeTextures.tail_down = LoadTexture("Graphics/tail_down.png");
    snakeTextures.tail_left = LoadTexture("Graphics/tail_left.png");
    snakeTextures.tail_right = LoadTexture("Graphics/tail_right.png");

    snakeTextures.body_vertical = LoadTexture("Graphics/body_vertical.png");
    snakeTextures.body_horizontal = LoadTexture("Graphics/body_horizontal.png");

    snakeTextures.body_tl = LoadTexture("Graphics/body_topleft.png");
    snakeTextures.body_tr = LoadTexture("Graphics/body_topright.png");
    snakeTextures.body_bl = LoadTexture("Graphics/body_bottomleft.png");
    snakeTextures.body_br = LoadTexture("Graphics/body_bottomright.png");

    snake.setTextures(&snakeTextures);

    food.loadTexture("Graphics/apple.png");
    grid.loadTextures("Graphics/grass_light.png", "Graphics/grass_dark.png");
    gameOverTexture = LoadTexture("Graphics/game_over.jpg");

}

void Game::unloadTextures() {
    UnloadTexture(snakeTextures.head_up);
    UnloadTexture(snakeTextures.head_down);
    UnloadTexture(snakeTextures.head_left);
    UnloadTexture(snakeTextures.head_right);
    UnloadTexture(snakeTextures.tail_up);
    UnloadTexture(snakeTextures.tail_down);
    UnloadTexture(snakeTextures.tail_left);
    UnloadTexture(snakeTextures.tail_right);
    UnloadTexture(snakeTextures.body_vertical);
    UnloadTexture(snakeTextures.body_horizontal);
    UnloadTexture(snakeTextures.body_tl);
    UnloadTexture(snakeTextures.body_tr);
    UnloadTexture(snakeTextures.body_bl);
    UnloadTexture(snakeTextures.body_br);

    grid.unloadTextures();
    food.unloadTexture();

	UnloadTexture(gameOverTexture);
}

void Game::update() {
    if (state != GameState::GAME_RUNNING) return;

    moveTimer -= GetFrameTime();
    if (moveTimer <= 0.0f) {
        snake.move();
        moveTimer = 0.15f;

        if (checkBoundaryCollision() || checkSnakeCollision()) {
            bus.publish(GameEvent::GAMEOVER);
            return;
        }

        checkFoodCollision();
    }
}

bool Game::checkBoundaryCollision() {
    const Vector2Int& head = snake.getHeadPosition();
    return head.x < 0 || head.x >= config.getCols() ||
        head.y < 0 || head.y >= config.getRows();
}

bool Game::checkSnakeCollision() {
    const Vector2Int& head = snake.getHeadPosition();
    const auto& body = snake.getBody();
    for (size_t i = 1; i < body.size(); ++i) {
        if (head.x == body[i].x && head.y == body[i].y) {
            return true;
        }
    }
    return false;
}

void Game::checkFoodCollision() {
    const Vector2Int& head = snake.getHeadPosition();
    if (head.x == food.getPosition().x && head.y == food.getPosition().y) {
        bus.publish(GameEvent::EAT_FOOD);
        score += food.getScoreValue();
        food.respawn(snake.getBody());
    }
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(config.getBackgroundColor());
    grid.drawGrid();
    snake.draw();
    food.draw();

    if (state == GameState::GAME_PAUSED) {
        DrawRectangle(0, 0, config.getScreenWidth(), config.getScreenHeight(),
            { 0, 0, 0, 150 });
        DrawText("PAUSED", config.getScreenWidth() / 2 - 100,
            config.getScreenHeight() / 2, 40, WHITE);
    }

    if (state == GameState::GAME_OVER) {
        Rectangle source = { 0, 0,
            (float)gameOverTexture.width,
            (float)gameOverTexture.height };
        Rectangle dest = { 0, 0,
            (float)config.getScreenWidth(),
            (float)config.getScreenHeight() };
        DrawTexturePro(gameOverTexture, source, dest, { 0, 0 }, 0.0f, WHITE);
    };

    EndDrawing();
}

void Game::run() {
    InitWindow(config.getScreenWidth(), config.getScreenHeight(), "Snake Game");
    SetTargetFPS(60);

    loadTextures();

    while (!WindowShouldClose()) {
        input.poll();
        update();
        draw();
    }

    unloadTextures();
    CloseWindow();
}