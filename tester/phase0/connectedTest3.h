#ifndef CONNECTEDTEST2_H
#define CONNECTEDTEST2_H

#include "../../include/constants.h"
#include "../../include/body.h"

#define TEST_BODY_COUNT 5
#define TEST_HOLE_COUNT 4

void createTestBodies(Body* bodies, Hole* holes) {
    // Create test  isCapped, maxHeight,        waterHeight,       width,          pos_x,        pos_y
    bodies[0] = Body{ true   , 10.0f * 20.0    , 2.0f *20.0      , 1.0f * 20.0, 0.0f * 20.0 + 50, 2.0f * 20.0 + 250}; // Body 1
    bodies[1] = Body{ true   , 10.0f * 20.0    , 3.0f *20.0      , 1.0f * 20.0, 2.0f * 20.0 + 50, 2.0f * 20.0 + 250}; // Body 2
    bodies[2] = Body{ true   , 10.0f * 20.0    , 7.0f *20.0      , 1.0f * 20.0, 4.0f * 20.0 + 50, 2.0f * 20.0 + 250}; // Body 3
    bodies[3] = Body{ true   , 10.0f * 20.0    , 4.0f *20.0      , 1.0f * 20.0, 6.0f * 20.0 + 50, 2.0f * 20.0 + 250}; // Body 4
    bodies[4] = Body{ true   , 2.0f  * 20.0    , 2.0f *20.0      , 7.0f * 20.0, 0.0f * 20.0 + 50, 0.0f * 20.0 + 250}; // Body 5
    // Create test  width,     x                     y       direction, {bodies connected}
    holes[0] = Hole{ 1 * 5.0, 0.5 * 20.0 + 50, 2 * 20.0 + 250, VERTICAL, &bodies[0], &bodies[4] };
    holes[1] = Hole{ 1 * 5.0, 2.5 * 20.0 + 50, 2 * 20.0 + 250, VERTICAL, &bodies[1], &bodies[4] };
    holes[2] = Hole{ 1 * 5.0, 4.5 * 20.0 + 50, 2 * 20.0 + 250, VERTICAL, &bodies[2], &bodies[4] };
    holes[3] = Hole{ 1 * 5.0, 6.5 * 20.0 + 50, 2 * 20.0 + 250, VERTICAL, &bodies[3], &bodies[4] };
}


CellType testGrid[][DISPLAY_WIDTH] =
{
    //    0          1           2            3           4    
    {AIR       , AIR        , AIR       , AIR        , AIR       }, // 0
    {AIR       , V_WALL     , WATER     , V_WALL     , AIR       }, // 1
    {AIR       , V_WALL     , WATER     , V_WALL     , AIR       }, // 2
    {AIR       , V_WALL     , WATER     , V_WALL     , AIR       }, // 3
    {AIR       , CORNER_WALL, H_WALL    , CORNER_WALL, AIR       }, // 4

};





#endif