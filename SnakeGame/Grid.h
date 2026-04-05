#pragma once

#include "raylib.h"
#include <iostream>

class Grid {
private:
	int cols;
	int rows;
	int cellSize;
	Color color;

public:
	Grid(int screenWidth, int screenHeight, int cellSize, Color color = DARKGRAY);

	void drawGrid();



};