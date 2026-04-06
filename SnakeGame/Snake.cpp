#include "Snake.h"

Snake::Snake(const GameConfig& gameConfig) : gameConfig(gameConfig) {
	snake_body.push_back({ 10, 10 }); // center of the grid
}

void Snake::draw() {
	int cellSize = gameConfig.getCellSize();
	Color snake_color = gameConfig.getSnakeColor();
	for (const auto& segment : snake_body) {
		DrawRectangle(segment.x * cellSize, segment.y * cellSize, cellSize, cellSize, snake_color);
	}
}

void Snake::grow() {
	snake_body.push_back(snake_body.back());
}

void Snake::move(Direction direction) {

	current_direction = direction;
	// Move the snake_body segments
	for (size_t i = snake_body.size() - 1; i > 0; --i) {
		snake_body[i] = snake_body[i - 1];
	}
	// Move the head
	switch (direction) {
	case Direction::UP:
		snake_body[0].y -= 1;
		break;
	case Direction::DOWN:
		snake_body[0].y += 1;
		break;
	case Direction::LEFT:
		snake_body[0].x -= 1;
		break;
	case Direction::RIGHT:
		snake_body[0].x += 1;
		break;
	}
}

bool Snake::checkBoundaryCollision() {
	int maxCols = gameConfig.getCols();
	int maxRows = gameConfig.getRows();
	const Vector2Int head = snake_body[0];
	return head.x < 0 || head.x >= maxCols || head.y < 0 || head.y >= maxRows;
}