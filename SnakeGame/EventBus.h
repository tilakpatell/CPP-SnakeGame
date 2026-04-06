#pragma once

#include <vector>
#include <functional>
#include <string>
#include <unordered_map>
#include <iostream>

enum class GameEvent {
	PAUSE,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_RIGHT,
	MOVE_LEFT,
	EAT_FOOD,
	GAMEOVER,
	RESTART,
};

struct GameEventHash {
	size_t operator()(const GameEvent& e) const {
		return static_cast<size_t>(e); /* C++ 23+ recommends to_underlying */
	}
};


/* This is a Observer pattern for the Inputs of the Game*/
class EventBus {

private:
	std::unordered_map<GameEvent, std::vector<std::function<void()>>, GameEventHash> event_mapping; /*Basically a dict that points to a function*/
public:
	EventBus() {};

	void subscribe(GameEvent event, std::function<void()> callable);

	void publish(GameEvent event);
	
};