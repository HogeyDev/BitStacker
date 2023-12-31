#pragma once

#include "piece.h"
#include <vector>

class Board {
public:
  std::vector<int> boardState = {0};
  Piece activePiece = {0};
  int level = 18;

  Board();
  void tick();
  bool pieceColliding();
};

std::vector<int> getBoardWithPiece(std::vector<int> board, Piece &piece);
