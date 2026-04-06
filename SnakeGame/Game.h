#pragma once

#include "raylib.h"
#include "EventBus.h"
#include "Snake.h"
#include "Grid.h"
#include "InputManager.h"

enum class GameState {
	GAME_PAUSED,
	GAME_RUNNING,
	GAME_OVER,
};


class Game {
private:
	EventBus bus;
	const GameConfig config;
	InputManager input;
	Snake snake;
	Grid grid;
	GameState state = GameState::GAME_RUNNING;
	float moveTimer = 0.15f;

	void update();

	void draw();

public:
	Game(const GameConfig& config);

	void run();
};