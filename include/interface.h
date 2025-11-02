#ifndef INTERFACE_H
#define INTERFACE_H

#define WATER_STR '#'
#define HALF_WATER_STR '~'
#define AIR_STR ' '

#define H_WALL_STR '-' 
#define V_WALL_STR '|'
#define CORNER_STR '+'
#define EMPTY_WALL_STR '.'

#define DISPLAY_HEIGHT 5
#define DISPLAY_WIDTH  5

// Only include one at a time to avoid redefinition errors
#include "body.h"
#include "constants.h"

class Interface
{
private:

    void printCell(CellType cell, CellType prevCell);

    // 2D array representing the display
    CellType display[DISPLAY_HEIGHT][DISPLAY_WIDTH] = {AIR};

public:
    Interface(CellType display[][DISPLAY_WIDTH]);
    Interface();

    void print(body_t* bodies, size_t bodyCount);
};



#endif