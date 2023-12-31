#include "piece.h"
#include <cassert>

/*
 * Piece IDs
 * 0 - O
 * 1 - S
 * 2 - Z
 * 3 - L
 * 4 - J
 * 5 - T
 * 6 - I
 */

int getPieceMatrix(int id, int state) {
  static const int matrices[] = {
      // O
      0b0000011001100000,
      0b0000011001100000,
      0b0000011001100000,
      0b0000011001100000,
      // S
      0b000011110,
      0b010011001,
      0b000011110,
      0b010011001,
      // Z
      0b000110011,
      0b001011010,
      0b000110011,
      0b001011010,
      // L
      0b000111100,
      0b110010010,
      0b100111000,
      0b011010010,
      // J
      0b000111001,
      0b010010110,
      0b100111000,
      0b011010010,
      // T
      0b000111010,
      0b010110010,
      0b010111000,
      0b010011010,
      // I
      0b0000000011110000,
      0b0010001000100010,
      0b0000000011110000,
      0b0010001000100010,
  };
  return matrices[id * 4 + state];
}

int framesPerDrop(int level) {
  if (0 <= level && level <= 8)
    return 45 - 5 * level;
  else if (8 <= level && level <= 9)
    return 8 - 2 * level;
  else if (10 <= level && level <= 12)
    return 5;
  else if (13 <= level && level <= 15)
    return 4;
  else if (16 <= level && level <= 18)
    return 3;
  else if (19 <= level && level <= 28)
    return 2;
  else if (29 <= level)
    return 1;
  assert(0 && "DAWG WHAT LEVEL ARE YOU ON???");
}

Piece::Piece(int id) {
  this->id = id;
  this->rotationState = 0;
  this->x = 3;
  this->y = -1;
  if (this->id == 3 || this->id == 4 || this->id == 5)
    this->x = 4;
  this->pieceMatrix = getPieceMatrix(id, this->rotationState);
  this->framesAlive = 0;
}
