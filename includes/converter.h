#ifndef CONVERTER_H
#define CONVERTER_H

#include "constants.h"

int convertColumnToInternalRepresentation(char column);
int convertRowToInternalRepresentation(int row);
struct BoardPosition convertToInternalRepresentation(int row, char column);

#endif
