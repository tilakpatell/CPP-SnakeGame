#include "InputManager.h"

InputManager::InputManager(EventBus& bus) : bus(bus) {
    inputMapping[KEY_W] = GameEvent::MOVE_UP;
    inputMapping[KEY_UP] = GameEvent::MOVE_UP;
    inputMapping[KEY_S] = GameEvent::MOVE_DOWN;
    inputMapping[KEY_DOWN] = GameEvent::MOVE_DOWN;
    inputMapping[KEY_A] = GameEvent::MOVE_LEFT;
    inputMapping[KEY_LEFT] = GameEvent::MOVE_LEFT;
    inputMapping[KEY_D] = GameEvent::MOVE_RIGHT;
    inputMapping[KEY_RIGHT] = GameEvent::MOVE_RIGHT;
    inputMapping[KEY_ESCAPE] = GameEvent::PAUSE;
    inputMapping[KEY_R] = GameEvent::RESTART;
};

void InputManager::poll() {
    for (auto& [key, event] : inputMapping) {
        if (IsKeyPressed(key)) {
            bus.publish(event);
        };
    };
};
