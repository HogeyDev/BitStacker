#include "window.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

Window::Window() {
  SDL_Init(SDL_INIT_VIDEO);

  this->window = SDL_CreateWindow("BitStacker", 0, 0, 1280, 720, 0);
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
    for (int dy = 0; dy < w; dy++) {
      this->pixel({p.x + dx, p.y + dy}, c);
    }
  }
}

void Window::clear() { this->pixels.clear(); }
void Window::drawBoard(Board board) {
  this->rect({100, 100}, 150, 200, {255, 255, 0, 255});
}
