#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <constants.h>
#include <stdbool.h>

bool inputFromValidator(struct BoardPosition *out, int row, char column);
bool inputToValidator(struct BoardPosition *from, struct BoardPosition *out,
                      int row, char column);

#endif
