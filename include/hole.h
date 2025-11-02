#ifndef HOLE_H
#define HOLE_H

#include "body.h"

enum Direction {
	VERTICAL = 0,
	HORIZONTAL = 1
};

typedef struct {
	// The width of the hole
	int width;

	// The position is at the bottom of the hole if its horizontal or left if its vertical
	int pos_x;
	int pos_y;

	// The direction of the hole
	Direction direction;

	// The bodies the hole connects; only one if it connects the body to air
	body_t* bodies[2];

	// Get a given body's destination, returns null if
	// this hole isn't connected to the given body
	body_t* getDestination(body_t* body)
	{
		for (size_t i = 0; i < 2; i++)
		{
			if (body == bodies[i])
			{
				return bodies[(i - 1) * -1];
			}
		}
		return nullptr;
	}
} hole_t;

#endif