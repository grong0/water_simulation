#ifndef CONNECTEDTEST2_H
#define CONNECTEDTEST2_H

#include "../../include/constants.h"
#include "../../include/body.h"

#define TEST_BODY_COUNT 3
#define TEST_HOLE_COUNT 2

void createTestBodies(Body* bodies, Hole* holes){
// Create test bodies  isCapped, maxHeight, waterHeight,      width,      pos_x,          pos_y
    bodies[0] = Body{ true   , 5.0f *20     , 4.0f*20       , 1.0f*20 , 0.0f*20 + 50 , 0.0f * 20 + 250 }; // Body 1
    bodies[1] = Body{ true   , 10.0f*20     , 6.0f*20       , 1.0f*20 , 1.0f*20 + 50 , 0.0f * 20 + 250 }; // Body 2
    bodies[2] = Body{ true   , 10.0f*20     , 8.5f*20       , 1.0f*20 , 2.0f*20 + 50 , 0.0f * 20 + 250 }; // Body 3
// Create test holes  width,             direction,          {bodies connected}
	holes[0] = Hole{ 1.0f * 20     , 1.0f * 20 + 50, 1.0f * 20 + 250, HORIZONTAL, &bodies[0], &bodies[1] };
	holes[1] = Hole{ 1.0f * 20     , 1.0f * 20 + 50, 1.0f * 20 + 250, HORIZONTAL, &bodies[1], &bodies[2] };
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