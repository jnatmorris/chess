#ifndef CONSTANTS_H
#define CONSTANTS_H

#define GAME_BOARD_WITH_EDGES_SIZE 9
#define GAME_BOARD_SIZE 8

enum TypeOfSquare {
  Pawn = 'P',
  Rook = 'R',
  Knight = 'k',
  Bishop = 'B',
  Queen = 'Q',
  King = 'K',
  Empty = ' '
};

static const enum TypeOfSquare SquareOrder[] = {Rook, Knight, Bishop, Queen,
                                                King, Bishop, Knight, Rook};

struct GamePeice {
  enum TypeOfSquare PeiceType;
  int isWhite;
};

struct BoardPosition {
  int row;
  int column;
};

extern const char borderLeft[];
extern const char borderTop[9];

extern const char peiceOrder[];

extern const struct GamePeice emptyGamePeice;

#endif
