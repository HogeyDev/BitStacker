#include "window.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <algorithm>
#include <cmath>

Window::Window(int width, int height) {
  this->width = width;
  this->height = height;

  SDL_Init(SDL_INIT_VIDEO);

  this->window =
      SDL_CreateWindow("BitStacker", 0, 0, this->width, this->height, 0);
  this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Window::draw() {
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
  SDL_RenderClear(this->renderer);

  for (Pixel &p : this->pixels) {
    SDL_SetRenderDrawColor(this->renderer, p.color.r, p.color.g, p.color.b,
                           p.color.a);
    SDL_RenderDrawPointF(this->renderer, p.pos.x, p.pos.y);
  }

  SDL_RenderPresent(this->renderer);
}

void Window::pollEvents() {
  while (SDL_PollEvent(&this->event)) {
    switch (this->event.type) {
    case SDL_QUIT:
      SDL_Quit();
      exit(0);
    }
  }
}

void Window::pixel(SDL_FPoint p, Color c) { this->pixels.push_back({p, c}); }
void Window::rect(SDL_FPoint p, float w, float h, Color c) {
  for (int dx = 0; dx < w; dx++) {
    for (int dy = 0; dy < h; dy++) {
      this->pixel({p.x + dx, p.y + dy}, c);
    }
  }
}

void Window::clear() { this->pixels.clear(); }
void Window::drawBoard(Board &board) {
  int boardMargin = 10;
  int boardWidth = 300;
  int boardHeight = 2 * boardWidth;
  int blockSize = boardWidth / 10;
  float boardLeftX = ((float)this->width - boardWidth) / 2;
  float boardTopY = ((float)this->height - boardHeight) / 2;

  this->rect({boardLeftX - boardMargin, boardTopY - boardMargin},
             boardWidth + 2 * boardMargin, boardHeight + 2 * boardMargin,
             {0x44, 0x47, 0x5A, 0xFF});

  int boardStateSize = 200;
  std::vector<int> renderBoardState =
      getBoardWithPiece(board.boardState, board.activePiece);
  for (int i = 0; i < boardStateSize; i++) {
    if (renderBoardState.at(i))
      this->rect({boardLeftX + (i % 10) * blockSize,
                  boardTopY + std::floor((float)i / 10) * blockSize},
                 blockSize, blockSize, {0xF8, 0xF8, 0xF2, 0xFF});
  }
}
