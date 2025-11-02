#ifndef CONSTANTS_H
#define CONSTANTS_H

#define GRAVITY 9.81f
#define RHO 1000f
#define ALMOSTZERO 0.000001f

enum CellType
{
    AIR = 0,
    WATER = 1,
    HALF_WATER = 2,

    H_WALL = 3,
    V_WALL = 4,
    CORNER_WALL = 5,
    EMPTY_WALL = 6,

    INVALID_CELL = -1,
};

#endif
