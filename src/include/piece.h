#pragma once

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

int getPieceMatrix(int id, int state);
int framesPerDrop(int level);

class Piece {
public:
  int id;
  int rotationState;
  int x;
  int y;
  int pieceMatrix : 16;
  int framesAlive;

  Piece(int id);
};
