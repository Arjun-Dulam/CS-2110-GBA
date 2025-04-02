#ifndef MOVEMENT_METHODS_H
#define MOVEMENT_METHODS_H

#include <stdbool.h>

#include "gba.h"
#include "main.h"

// Function prototype for moveEntity
void moveEntity(entity *e, u32 currentButtons, u16 backgroundColor);

bool detectCollision(entity *a, entity *b);

bool isFullyContained(entity *box, entity *boulder);

#endif