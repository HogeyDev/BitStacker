#include "board.h"
#include "piece.h"
#include <cstdlib>

Board::Board() {
  this->boardState.resize(200);
  this->activePiece = Piece(std::rand() % 7);
  this->level = 18;
}

// px = piece.x
// py = piece.y
// dx = i % matrixWidth
// dy = i / matrixWidth
// x = px + dx = piece.x + i % matrixWidth
// y = py + dy = piece.y + i / matrixWidth
// i = y * 10 + x = (piece.y + i / matrixWidth) * 10 + piece.x + i % matrixWidth
std::vector<int> getBoardWithPiece(std::vector<int> board, Piece &piece) {
  int matrixWidth = 4;
  if (piece.id >= 1 && piece.id <= 5)
    matrixWidth = 3;
  int matrixArea = matrixWidth * matrixWidth;
  int bitMask = 0b1 << (matrixArea - 1);
  for (int i = 0; i < matrixArea; i++) {
    int value = (piece.pieceMatrix & bitMask);
    if (value)
      board.at((piece.y + i / matrixWidth) * 10 + piece.x + i % matrixWidth) =
          value;
    bitMask >>= 1;
  }
  return board;
}

void Board::tick() {
  if ((this->activePiece.framesAlive + 1) % framesPerDrop(this->level) ==
      0) { //
    this->activePiece.y++;
    if (this->pieceColliding()) {
      this->activePiece.y--;
      this->boardState = getBoardWithPiece(this->boardState, this->activePiece);
      this->activePiece = Piece(std::rand() % 7);
    }
  }
  this->activePiece.framesAlive++;
}

bool Board::pieceColliding() {
  int matrixWidth = 4;
  if (this->activePiece.id >= 1 && this->activePiece.id <= 5)
    matrixWidth = 3;
  int matrixArea = matrixWidth * matrixWidth;
  int bitMask = 0b1 << (matrixArea - 1);
  for (int i = 0; i < matrixArea; i++) {
    int value = (this->activePiece.pieceMatrix & bitMask);
    if (value) {
      int x = this->activePiece.x + i % matrixWidth;
      int y = this->activePiece.y + i / matrixWidth;
      if (x < 0 || x > 9 || y < 0 || y > 19)
        return true;
      if (this->boardState.at(y * 10 + x))
        return true;
    }
    bitMask >>= 1;
  }
  return false;
}
