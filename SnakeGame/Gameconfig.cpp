#include "Gameconfig.h"

GameConfig::GameConfig(int screenWidth, int screenHeight, int cellSize, Color backgroundColor, Color snakeColor)
	: screenWidth(screenWidth), screenHeight(screenHeight),
	cellSize(cellSize), backgroundColor(backgroundColor),
	snakeColor(snakeColor),
	rows(screenHeight / cellSize),
	cols(screenWidth / cellSize) 
{};

Color GameConfig::getBackgroundColor() const {
	return backgroundColor;
}

int GameConfig::getCellSize() const {
	return cellSize;
}

int GameConfig::getScreenHeight() const {
	return screenHeight;
}

int GameConfig::getScreenWidth() const {
	return screenWidth;
}

Color GameConfig::getSnakeColor() const {
	return snakeColor;
}

int GameConfig::getRows() const {
	return rows;
}

int GameConfig::getCols() const {
	return cols;
}
