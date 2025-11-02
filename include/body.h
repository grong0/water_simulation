#ifndef BODY_H
#define BODY_H

#include <string>

// A body of water
typedef struct
{
	// Whether or not the body has a lid on it
	bool isCapped;
	
	// The maximum height of the body, relative to pos_y
	float maxHeight;

	// The current height of the water, relative to pos_y
	float waterHeight;

	// The width of the body
	float width;

	// The position of the body is at the bottom left of the body

	// The X position of the body
	float pos_x;

	// The Y position of the body
	float pos_y;

	float waterLevel() {
		return pos_y - waterHeight;
	}

	float volume() {
		return waterHeight * width;
	}

	std::string toString() {
		return "Body at (" + std::to_string(pos_x) + ", " + std::to_string(pos_y) + "), has a size of " + std::to_string(width) + " by " + std::to_string(maxHeight) + " and has a waterHeight of " + std::to_string(waterHeight);
	}	
}body_t;

#endif