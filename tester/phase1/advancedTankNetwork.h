#ifndef ADVANCEDTANKNETWORK_H
#define ADVANCEDTANKNETWORK_H

#include "../../include/constants.h"
#include "../../include/body.h"
#include "../../include/interface.h"

#define TEST_BODY_COUNT 7
#define TEST_HOLE_COUNT 7

void createTestBodies(Body* bodies, Hole* holes) {
    // Create test bodies  isCapped, maxHeight, waterHeight, width, pos_x, pos_y
    bodies[0] = Body{ true   , 5.0f * 20.0      , 0.0f * 20.0      , 5.0f * 20.0, 5.0f  * 20.0, 0.0f  * 20.0}; // Body 1
    bodies[1] = Body{ true   , 5.0f * 20.0      , 4.0f * 20.0      , 6.0f * 20.0, 16.0f * 20.0, 2.0f  * 20.0}; // Body 2
    bodies[2] = Body{ true   , 5.0f * 20.0      , 5.0f * 20.0      , 6.0f * 20.0, 0.0f  * 20.0, 5.0f  * 20.0}; // Body 3
    bodies[3] = Body{ true   , 5.0f * 20.0      , 5.0f * 20.0      , 7.0f * 20.0, 9.0f  * 20.0, 5.0f  * 20.0}; // Body 4
    bodies[4] = Body{ true   , 6.0f * 20.0      , 5.0f * 20.0      , 1.0f * 20.0, 1.0f  * 20.0, 10.0f * 20.0}; // Body 5
    bodies[5] = Body{ true   , 5.0f * 20.0      , 2.0f * 20.0      , 8.0f * 20.0, 4.0f  * 20.0, 10.0f * 20.0}; // Body 6
    bodies[6] = Body{ true   , 3.0f * 20.0      , 2.0f * 20.0      , 5.0f * 20.0, 14.0f * 20.0, 10.0f * 20.0}; // Body 7
    // Create test holes  width, direction, {bodies connected}
    holes[0] = Hole{ 1 * 20.0     , 5.5f * 20.0 , 5.0f * 20.0 , VERTICAL  , &bodies[0], &bodies[2] };
    holes[1] = Hole{ 1 * 20.0     , 9.5f * 20.0 , 5.0f * 20.0 , HORIZONTAL, &bodies[0], &bodies[3] };
    holes[2] = Hole{ 2 * 20.0     , 16   * 20.0 , 6.0f * 20.0 , VERTICAL  , &bodies[1], &bodies[3] };
    holes[3] = Hole{ 1 * 20.0     , 1.5f * 20.0 , 10   * 20.0 , VERTICAL  , &bodies[2], &bodies[4] };
    holes[4] = Hole{ 2 * 20.0     , 5.0f * 20.0 , 10   * 20.0 , VERTICAL  , &bodies[2], &bodies[5] };
    holes[5] = Hole{ 2 * 20.0     , 10.5f * 20.0, 10   * 20.0 , VERTICAL  , &bodies[3], &bodies[5] };
    holes[6] = Hole{ 2 * 20.0     , 15   * 20.0 , 10   * 20.0 , VERTICAL  , &bodies[3], &bodies[6] };
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