add_executable (SnakeGame "SnakeGame.cpp" "SnakeGame.h" "Snake.h" "Snake.cpp" "Grid.h" "Grid.cpp" "Gameconfig.cpp" "Gameconfig.h" "EventBus.h" "EventBus.cpp" "InputManager.h"  "InputManager.cpp" "Game.h" "Game.cpp" "Food.h" "Food.cpp" "SpriteSheet.h")
target_link_libraries(SnakeGame raylib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SnakeGame PROPERTY CXX_STANDARD 20)
endif()

add_custom_command(TARGET SnakeGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "$<TARGET_FILE_DIR:SnakeGame>/Graphics"
)