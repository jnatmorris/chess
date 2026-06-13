#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <constants.h>
#include <stdbool.h>

int movePeice(struct BoardPosition boardPositionFrom,
              struct BoardPosition boardPositionTo, bool playerIsWhite);

#endif
