#ifndef CONNECTEDTEST2_H
#define CONNECTEDTEST2_H

#include "../../include/constants.h"
#include "../../include/body.h"
#include <vector>

#define TEST_BODY_COUNT 3
#define TEST_HOLE_COUNT 2

void createTestBodies(std::vector<Body> *bodies, std::vector<Hole> *holes) {
    // Create test bodies  isCapped, maxHeight, waterHeight, width, pos_x, pos_y
    bodies->push_back(Body{ true   , 10.0f*20     , 4.0f*20       , 1.0f*20 , 0.0f*20 + 50 , 0.0f*20 + 250 }); // Body 1
    bodies->push_back(Body{ true   , 2.0f *20     , 2.0f*20       , 1.0f*20 , 1.0f*20 + 50 , 0.0f*20 + 250 }); // Body 2
    bodies->push_back(Body{ true   , 10.0f*20     , 8.5f*20       , 1.0f*20 , 2.0f*20 + 50 , 0.0f*20 + 250 }); // Body 3
    // Create test holes  width,      x,        y       direction, {bodies connected}
    holes->push_back(Hole{ 1*20      , 1*20 + 50, 1*20 + 250, HORIZONTAL, &bodies->at(0), &bodies->at(1) });
    holes->push_back(Hole{ 1*20      , 2*20 + 50, 1*20 + 250, HORIZONTAL, &bodies->at(1), &bodies->at(2) });
}


#endif