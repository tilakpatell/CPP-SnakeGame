#pragma once

#include <iostream>
#include "raylib.h"
#include <string>
#include <deque>
#include <memory>

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
	std::deque<Vector2Int> body;
	int cellSize;
	Direction direction;

public:
	Snake();

	void draw();

	void move(Direction direction);

	void grow();

	bool checkBoundaryCollision(int screenWidth, int screenHeight);

};



