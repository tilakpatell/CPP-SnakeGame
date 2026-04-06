#pragma once

#include <iostream>
#include "raylib.h"
#include <string>
#include <deque>
#include <memory>
#include "Gameconfig.h"
#include "EventBus.h"

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
	GameConfig gameConfig;
	EventBus& bus;
	std::deque<Vector2Int> snake_body;
	Direction current_direction = Direction::UP;

public:
	Snake(const GameConfig& gameConfig, EventBus& bus);

	void draw();

	void move();

	void grow();

	bool checkBoundaryCollision();

};



