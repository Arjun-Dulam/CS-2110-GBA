#include "movementMethods.h"

void moveEntity(entity *e, u32 currentButtons, u16 backgroundColor) {
    // clear the place where the character was originally
    drawRectDMA(e->row, e->col, 10, 10, backgroundColor);

    if (KEY_DOWN(BUTTON_UP, currentButtons) && e->row > 0) {
        e->row--;
    } else if (KEY_DOWN(BUTTON_DOWN, currentButtons) && e->row + 10 < HEIGHT) {
        e->row++;
    } else if (KEY_DOWN(BUTTON_LEFT, currentButtons) && e->col > 0) {
        e->col--;
    } else if (KEY_DOWN(BUTTON_RIGHT, currentButtons) && e->col + 10 < WIDTH) {
        e->col++;
    }

    // redraw entity
    drawImageDMA(e->row, e->col, 10, 10, e->image);
}

bool detectCollision(entity *a, entity *b) {
    int aLeft = a->col;
    int aTop = a->row;
    int aRight = a->col + 10;
    int aBottom = a->row + 10;

    int bLeft = b->col;
    int bTop = b->row;
    int bRight = b->col + 10;
    int bBottom = b->row + 10;

    bool horizontalCollision = !(aRight <= bLeft || aLeft >= bRight);
    bool verticalCollision = !(aBottom <= bTop || aTop >= bBottom);

    if (!horizontalCollision || !verticalCollision) {
        return false;
    }
    return true;
}