#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdbool.h>

int movePeice(int rowToMoveFrom, char columnToMoveFrom, int rowToMoveTo,
              char columnToMoveTo, bool playerIsWhite);

#endif
