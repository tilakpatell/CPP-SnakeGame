#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "raylib.h"
#include "EventBus.h"


class InputManager {
private:
	std::unordered_map<int, GameEvent> inputMapping;
	EventBus& bus;

public:
	InputManager(EventBus& bus);

	void poll();
};