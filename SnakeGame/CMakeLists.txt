add_executable (SnakeGame "SnakeGame.cpp" "SnakeGame.h" "Snake.h" "Snake.cpp" "Grid.h" "Grid.cpp" "Gameconfig.cpp" "Gameconfig.h" "EventBus.h" "EventBus.cpp" "InputManager.h"  "InputManager.cpp" "Game.h" "Game.cpp")
target_link_libraries(SnakeGame raylib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SnakeGame PROPERTY CXX_STANDARD 20)
endif()