#include "Snake.h"

Snake::Snake() : cellSize(20), direction(Direction::RIGHT) {
	body.push_back({ 20, 15 }); // Initial position of the snake's head
}

void Snake::draw() {
	for (const auto& segment : body) {
		DrawRectangle(segment.x * cellSize, segment.y * cellSize, cellSize, cellSize, GREEN);
	}
}

void Snake::grow() {
	body.push_back(body.back());
}

void Snake::move(Direction direction) {
	// Move the body segments
	for (size_t i = body.size() - 1; i > 0; --i) {
		body[i] = body[i - 1];
	}
	// Move the head
	switch (direction) {
	case Direction::UP:
		body[0].y -= 1;
		break;
	case Direction::DOWN:
		body[0].y += 1;
		break;
	case Direction::LEFT:
		body[0].x -= 1;
		break;
	case Direction::RIGHT:
		body[0].x += 1;
		break;
	}
}

bool Snake::checkBoundaryCollision(int screenWidth, int screenHeight) {
	int maxCols = screenWidth / cellSize;
	int maxRows = screenHeight / cellSize;
	const Vector2Int head = body[0];
	return head.x < 0 || head.x >= maxCols || head.y < 0 || head.y >= maxRows;
}