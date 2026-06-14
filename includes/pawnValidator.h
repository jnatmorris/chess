#ifndef PAWNVALIDATOR_H
#define PAWNVALIDATOR_H

#include "constants.h"
#include <stdbool.h>

bool isValidPositionForPawn(struct BoardPosition *from,
                            struct BoardPosition *to, bool playerIsWhite);

#endif
