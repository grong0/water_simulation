#ifndef ADVANCEDTANKNETWORK_H
#define ADVANCEDTANKNETWORK_H

#include "../../include/constants.h"
#include "../../include/body.h"
#include "../../include/interface.h"

#define TEST_BODY_COUNT 7
#define TEST_HOLE_COUNT 7

void createTestBodies(Body* bodies, Hole* holes) {
    // Create test bodies  isCapped, maxHeight, waterHeight, width, pos_x, pos_y
    bodies[0] = Body{ true   , 5.0f      , 0.0f       , 5.0f , 5.0f , 0.0f }; // Body 1
    bodies[1] = Body{ true   , 5.0f      , 4.0f       , 6.0f , 16.0f, 2.0f }; // Body 2
    bodies[2] = Body{ true   , 5.0f      , 5.0f       , 6.0f , 0.0f , 5.0f }; // Body 3
    bodies[3] = Body{ true   , 5.0f      , 5.0f       , 7.0f , 9.0f , 5.0f }; // Body 4
    bodies[4] = Body{ true   , 6.0f      , 5.0f       , 1.0f , 1.0f , 10.0f}; // Body 5
    bodies[5] = Body{ true   , 5.0f      , 2.0f       , 8.0f , 4.0f , 10.0f}; // Body 6
    bodies[6] = Body{ true   , 3.0f      , 2.0f       , 5.0f , 14.0f, 10.0f}; // Body 7
    // Create test holes  width, direction, {bodies connected}
    holes[0] = Hole{ 1      , 5.5f, 5.0f, VERTICAL  , &bodies[0], &bodies[2] };
    holes[1] = Hole{ 1      , 9.5f, 5.0f, HORIZONTAL, &bodies[0], &bodies[3] };
    holes[2] = Hole{ 2      , 16  , 6.0f, VERTICAL  , &bodies[1], &bodies[3] };
    holes[3] = Hole{ 1      , 1.5f, 10  , VERTICAL  , &bodies[2], &bodies[4] };
    holes[4] = Hole{ 2      , 5.0f, 10  , VERTICAL  , &bodies[2], &bodies[5] };
    holes[5] = Hole{ 2      , 10.5f, 10 , VERTICAL  , &bodies[3], &bodies[5] };
    holes[6] = Hole{ 2      , 15  , 10  , VERTICAL  , &bodies[3], &bodies[6] };
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