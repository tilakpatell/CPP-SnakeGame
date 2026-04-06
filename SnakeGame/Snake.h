#pragma once

#include <iostream>
#include "raylib.h"
#include <string>
#include <deque>
#include <memory>
#include "Gameconfig.h"

enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct Vector2Int {
	int x;
	int y;
};	

class Snake {
private:
	std::deque<Vector2Int> snake_body;
	Direction current_direction = Direction::UP;
	GameConfig gameConfig;

public:
	Snake(const GameConfig& gameConfig);

	void draw();

	void move(Direction direction);

	void grow();

	bool checkBoundaryCollision();

};



