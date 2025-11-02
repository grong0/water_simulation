#ifndef CONNECTEDTEST2_H
#define CONNECTEDTEST2_H

#include "../../include/constants.h"
#include "../../include/body.h"
#include <vector>

#define TEST_BODY_COUNT 3
#define TEST_HOLE_COUNT 2

void createTestBodies(std::vector<Body> *bodies, std::vector<Hole> *holes){
// Create test bodies  isCapped, maxHeight, waterHeight,      width,      pos_x,          pos_y
    bodies->push_back(Body{ true   , 5.0f *20     , 4.0f*20       , 1.0f*20 , 0.0f*20 + 50 , 0.0f * 20 + 250 }); // Body 1
    bodies->push_back(Body{ true   , 10.0f*20     , 6.0f*20       , 1.0f*20 , 1.0f*20 + 50 , 0.0f * 20 + 250 }); // Body 2
    bodies->push_back(Body{ true   , 10.0f*20     , 8.5f*20       , 1.0f*20 , 2.0f*20 + 50 , 0.0f * 20 + 250 }); // Body 3

// Create test holes  width,             x,                y          DIRECTION          {bodies connected}
	holes->push_back(Hole{ 1.0f * 20     , 1.0f * 20 + 50, 1.0f * 20 + 250, HORIZONTAL, &bodies->at(0), &bodies->at(1) });
	holes->push_back(Hole{ 1.0f * 20     , 2.0f * 20 + 50, 1.0f * 20 + 250, HORIZONTAL, &bodies->at(1), &bodies->at(2) });
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