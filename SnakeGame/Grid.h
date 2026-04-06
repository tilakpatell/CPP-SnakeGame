#pragma once

#include "raylib.h"
#include <iostream>
#include "GameConfig.h"

class Grid {
private:
	GameConfig gameConfig;
public:
	Grid(const GameConfig& gameConfig);
	void drawGrid();
};