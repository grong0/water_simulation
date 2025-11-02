#ifndef CONNECTEDTEST_H
#define CONNECTEDTEST_H

#include "../../include/body.h"

#define TEST_BODY_COUNT 1

void createTestBodies(Body* bodies){
// Create test bodies      isCapped, maxHeight, waterHeight, width, pos_x, pos_y
    *bodies = Body{false   , 3.0f     , 3.0f       , 3.0f , 0.0f , 0.0f}; // Body 1
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