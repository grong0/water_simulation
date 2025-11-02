#ifndef CONNECTEDTEST2_H
#define CONNECTEDTEST2_H

#include "../../include/constants.h"
#include "../../include/body.h"

#define TEST_BODY_COUNT 5
#define TEST_HOLE_COUNT 4

void createTestBodies(std::vector<Body> *bodies, std::vector<Hole> *holes) {
    // Create test  isCapped, maxHeight,        waterHeight,       width,          pos_x,        pos_y
    bodies->push_back(Body{ true   , 10.0f * 20.0    , 2.0f *20.0      , 1.0f * 20.0, 0.0f * 20.0 + 50, 2.0f * 20.0 + 250}); // Body 1
    bodies->push_back(Body{ true   , 10.0f * 20.0    , 3.0f *20.0      , 1.0f * 20.0, 2.0f * 20.0 + 50, 2.0f * 20.0 + 250}); // Body 2
    bodies->push_back(Body{ true   , 10.0f * 20.0    , 7.0f *20.0      , 1.0f * 20.0, 4.0f * 20.0 + 50, 2.0f * 20.0 + 250}); // Body 3
    bodies->push_back(Body{ true   , 10.0f * 20.0    , 4.0f *20.0      , 1.0f * 20.0, 6.0f * 20.0 + 50, 2.0f * 20.0 + 250}); // Body 4
    bodies->push_back(Body{ true   , 2.0f  * 20.0    , 2.0f *20.0      , 7.0f * 20.0, 0.0f * 20.0 + 50, 0.0f * 20.0 + 250}); // Body 5
    // Create test  width,     x                     y       direction, {bodies connected}
    holes->push_back(Hole{ 1 * 5.0, 0.5 * 20.0 + 50, 2 * 20.0 + 250, VERTICAL, &bodies->at(0), &bodies->at(4) });
    holes->push_back(Hole{ 1 * 5.0, 2.5 * 20.0 + 50, 2 * 20.0 + 250, VERTICAL, &bodies->at(1), &bodies->at(4) });
    holes->push_back(Hole{ 1 * 5.0, 4.5 * 20.0 + 50, 2 * 20.0 + 250, VERTICAL, &bodies->at(2), &bodies->at(4) });
    holes->push_back(Hole{ 1 * 5.0, 6.5 * 20.0 + 50, 2 * 20.0 + 250, VERTICAL, &bodies->at(3), &bodies->at(4) });
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