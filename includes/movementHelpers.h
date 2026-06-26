#ifndef MOVEMENTHELPERS_H
#define MOVEMENTHELPERS_H

#include "constants.h"
#include <stdbool.h>

bool isPositionEmpty(struct BoardPosition *position);
bool isLocationSameColor(struct BoardPosition *position, bool isWhite);

#endif
