
#include "SnakeGame.h"

int main()
{
	std::cout << "Starting Snake Game..." << std::endl;

	GameConfig gameConfig;
	int screenWidth = gameConfig.getScreenWidth();
	int screenHeight = gameConfig.getScreenHeight();

	InitWindow(screenWidth, screenHeight, "Snake Game");
	SetTargetFPS(60);
	float timer = 0.15f;

	Snake snake(gameConfig);
	Grid grid(gameConfig);

	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(gameConfig.getBackgroundColor());
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
