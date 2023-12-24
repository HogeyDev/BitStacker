#pragma once

#include "color.h"
#include <SDL2/SDL_rect.h>
#include <cstdint>

typedef struct {
  SDL_FPoint pos;
  Color color;
} Pixel;
