#include "EventBus.h"

void EventBus::subscribe(GameEvent event, std::function<void()> callable) {
	event_mapping[event].emplace_back(callable);
};

void EventBus::publish(GameEvent event) {
    if (!event_mapping.contains(event)) {
        std::cerr << "[WARNING] Published event with no subscribers" << std::endl;
        return;
    }
    for (auto& func : event_mapping[event]) {
        func();
    }
}