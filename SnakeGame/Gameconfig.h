#pragma once

#include <iostream>
#include "raylib.h"

struct Vector2Int {
	int x;
	int y;
};

class GameConfig {
public:
	GameConfig(int screenWidth = 1000, int screenHeight = 1000, int cellSize = 50,
		Color backgroundColor = { 44, 54, 57, 255 },    // dark teal-gray
		Color snakeColor = { 130, 220, 75, 255 });       // vibrant green

	int getScreenWidth() const;

	int getScreenHeight() const;

	int getCellSize() const;

	int getRows() const;
	
	int getCols() const;

	Color getBackgroundColor() const;

	Color getSnakeColor() const;

private:

	int screenWidth;
	int screenHeight; 
	int cellSize;
	Color backgroundColor;
	Color snakeColor;
	int rows;
	int cols;

};