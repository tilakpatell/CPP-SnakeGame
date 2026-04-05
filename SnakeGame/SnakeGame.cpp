// SnakeGame.cpp : Defines the entry point for the application.
//

#include "SnakeGame.h"
#include "raylib.h"
#include <iostream>
#include "Grid.h"
#include "Snake.h"


constexpr int screenWidth = 800;
constexpr int screenHeight = 600;
constexpr int cellSize = 20;

int main()
{
	std::cout << "Starting Snake Game..." << std::endl;

	InitWindow(screenWidth, screenHeight, "Snake Game");
	SetTargetFPS(60);
	float timer = 0.15f;

	Snake snake;
	Grid grid(screenWidth, screenHeight, cellSize, BLACK);

	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		grid.drawGrid();
		snake.draw();
		timer -= GetFrameTime();
		if (timer <= 0.0f) {
			snake.move(Direction::RIGHT);
			timer = 0.15f;
		}
		EndDrawing();
	};
	CloseWindow();
	return 0;
}
