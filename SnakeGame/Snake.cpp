#include "Snake.h"

Snake::Snake(const GameConfig& gameConfig, EventBus& bus) : gameConfig(gameConfig), bus(bus) {

    bus.subscribe(GameEvent::MOVE_UP, [this]() {
        if (current_direction != Direction::DOWN)
            current_direction = Direction::UP;
        });

    bus.subscribe(GameEvent::MOVE_DOWN, [this]() {
        if (current_direction != Direction::UP)
            current_direction = Direction::DOWN;
        });

    bus.subscribe(GameEvent::MOVE_LEFT, [this]() {
        if (current_direction != Direction::RIGHT)
            current_direction = Direction::LEFT;
        });

    bus.subscribe(GameEvent::MOVE_RIGHT, [this]() {
        if (current_direction != Direction::LEFT)
            current_direction = Direction::RIGHT;
        });

    bus.subscribe(GameEvent::EAT_FOOD, [this]() {
        grow();
        });

    snake_body.push_back({ 10, 10 });
}

void Snake::setTextures(const SnakeTextures* tex) {
    textures = tex;
}

void Snake::draw() {
    int cellSize = gameConfig.getCellSize();

    if (snake_body.size() == 1) {
        drawHead(cellSize);
        return;
    }

    for (size_t i = 0; i < snake_body.size(); ++i) {
        if (i == 0) {
            drawHead(cellSize);
        }
        else if (i == snake_body.size() - 1) {
            drawTail(cellSize);
        }
        else {
            drawBody(i, cellSize);
        }
    }
}

void Snake::drawHead(int cellSize) {
    const auto& head = snake_body[0];
    const Texture2D* tex;

    switch (current_direction) {
    case Direction::UP:    tex = &textures->head_up;    break;
    case Direction::DOWN:  tex = &textures->head_down;  break;
    case Direction::LEFT:  tex = &textures->head_left;  break;
    case Direction::RIGHT: tex = &textures->head_right; break;
    }

    Rectangle source = { 0, 0, (float)tex->width, (float)tex->height };
    Rectangle dest = {
        (float)(head.x * cellSize),
        (float)(head.y * cellSize),
        (float)cellSize,
        (float)cellSize
    };
    DrawTexturePro(*tex, source, dest, { 0, 0 }, 0.0f, WHITE);
}

void Snake::drawTail(int cellSize) {
    size_t last = snake_body.size() - 1;
    const auto& tail = snake_body[last];
    const auto& before_tail = snake_body[last - 1];

    int dx = before_tail.x - tail.x;
    int dy = before_tail.y - tail.y;

    const Texture2D* tex;

    if (dx == 0 && dy == -1)      tex = &textures->tail_down;
    else if (dx == 0 && dy == 1)  tex = &textures->tail_up;
    else if (dx == -1 && dy == 0) tex = &textures->tail_right;
    else                          tex = &textures->tail_left;

    Rectangle source = { 0, 0, (float)tex->width, (float)tex->height };
    Rectangle dest = {
        (float)(tail.x * cellSize),
        (float)(tail.y * cellSize),
        (float)cellSize,
        (float)cellSize
    };
    DrawTexturePro(*tex, source, dest, { 0, 0 }, 0.0f, WHITE);
}

void Snake::drawBody(size_t index, int cellSize) {
    const auto& segment = snake_body[index];
    const auto& prev = snake_body[index + 1];  // toward tail
    const auto& next = snake_body[index - 1];  // toward head

    int px = prev.x - segment.x;
    int py = prev.y - segment.y;
    int nx = next.x - segment.x;
    int ny = next.y - segment.y;

    const Texture2D* tex;

    if (px == nx) {
        tex = &textures->body_vertical;
    }
    else if (py == ny) {
        tex = &textures->body_horizontal;
    }
    else if ((px == -1 && ny == -1) || (py == -1 && nx == -1)) {
        tex = &textures->body_tl;
    }
    else if ((px == 1 && ny == -1) || (py == -1 && nx == 1)) {
        tex = &textures->body_tr;
    }
    else if ((px == -1 && ny == 1) || (py == 1 && nx == -1)) {
        tex = &textures->body_bl;
    }
    else {
        tex = &textures->body_br;
    }

    Rectangle source = { 0, 0, (float)tex->width, (float)tex->height };
    Rectangle dest = {
        (float)(segment.x * cellSize),
        (float)(segment.y * cellSize),
        (float)cellSize,
        (float)cellSize
    };
    DrawTexturePro(*tex, source, dest, { 0, 0 }, 0.0f, WHITE);
};

void Snake::grow() {
    snake_body.push_back(snake_body.back());
};

void Snake::move() {
    for (size_t i = snake_body.size() - 1; i > 0; --i) {
        snake_body[i] = snake_body[i - 1];
    }
    switch (current_direction) {
    case Direction::UP:    snake_body[0].y -= 1; break;
    case Direction::DOWN:  snake_body[0].y += 1; break;
    case Direction::LEFT:  snake_body[0].x -= 1; break;
    case Direction::RIGHT: snake_body[0].x += 1; break;
    }
};

const Vector2Int& Snake::getHeadPosition() const {
    return snake_body[0];
}

const std::deque<Vector2Int>& Snake::getBody() const {
    return snake_body;
};