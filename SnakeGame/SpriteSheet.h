#pragma once

#include "raylib.h"

struct SnakeTextures {
    Texture2D head_up;
    Texture2D head_down;
    Texture2D head_left;
    Texture2D head_right;

    Texture2D tail_up;
    Texture2D tail_down;
    Texture2D tail_left;
    Texture2D tail_right;

    Texture2D body_vertical;
    Texture2D body_horizontal;

    Texture2D body_tl;
    Texture2D body_tr;
    Texture2D body_bl;
    Texture2D body_br;
};