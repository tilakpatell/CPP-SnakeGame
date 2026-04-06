# Snake Game

A classic snake game built with C++ and Raylib, designed with clean architecture and 
modern C++ practices.

## About

A simple yet well-structured snake game where you guide a snake around a grid, 
eating food to grow while avoiding walls and yourself. Built as a learning project 
to explore game development patterns in C++.

## Architecture

The project follows an event-driven architecture using the Observer pattern. 
An EventBus decouples input handling from game logic, making the codebase 
modular and extensible.

- **Game** — owns the game loop and manages state (running, paused, game over)
- **EventBus** — routes events between systems without direct dependencies
- **InputManager** — translates keyboard input into game events with rebindable keys
- **Snake** — subscribes to movement events and handles its own logic
- **Grid** — renders the game board
- **GameConfig** — centralizes all game settings with sensible defaults

## Controls

- **WASD / Arrow Keys** — change direction
- **Escape** — pause / unpause
- **R** — restart

## Built With

- C++20
- [Raylib](https://www.raylib.com/) — graphics and input
- CMake — build system

## Building
```bash
git clone <your-repo-url>
cd SnakeGame
cmake -B build
cmake --build build
```