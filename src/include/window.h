#pragma once

#include "board.h"
#include "pixel.h"
#include <SDL2/SDL.h>
#include <vector>

class Window {
public:
  int width;
  int height;

  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;
  std::vector<Pixel> pixels;
  Window(int width, int height);
  void draw();
  void pollEvents();
  void pixel(SDL_FPoint p, Color c);
  void rect(SDL_FPoint p, float w, float h, Color c);
  void clear();
  void drawBoard(Board &board);
};
