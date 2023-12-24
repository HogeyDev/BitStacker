#include "board.h"
#include "window.h"
#include <SDL2/SDL.h>
#include <iostream>

int main() {
  Window window = Window();
  Board board = Board();

  while (true) {
    window.clear();
    window.drawBoard(board);
    window.pollEvents();
    window.draw();
    SDL_Delay(1000. / 60.);
  }

  return 0;
}
