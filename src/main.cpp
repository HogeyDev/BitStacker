#include "board.h"
#include "window.h"
#include <SDL2/SDL.h>

int main() {
  Window window = Window(1280, 720);
  Board board = Board();

  while (true) {
    board.tick();

    window.clear();
    window.drawBoard(board);
    window.pollEvents();
    window.draw();
    SDL_Delay(1000. / 60.);
  }

  return 0;
}
