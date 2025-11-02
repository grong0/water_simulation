#ifndef BODY_H
#define BODY_H

#include <string>
#include <vector>

float torricelliVelocity(float dh);

float torricelliVelocityBetweenPressures(float dh, float pressure1, float pressure2);

class Hole;

// A body of water
class Body
{
public:
	Body();
	Body(bool isCapped, float maxHeight, float waterHeight, float width, float pos_x, float pos_y);

	// Whether or not the body has a lid on it
	bool isCapped;

	// The maximum height of the body, relative to pos_y
	float maxHeight;

	// The current height of the water, relative to pos_y
	float waterHeight;

	// The width of the body
	float width;

	// holes
	std::vector<Hole*> holes;

	// The position of the body is at the bottom left of the body

	// The X position of the body
	float pos_x;

	// The Y position of the body
	float pos_y;

	float waterLevel();

	float volume();

	bool isFull();

	std::string toString();

	void update(float deltaTime);
};

enum Direction {
	VERTICAL = 0,
	HORIZONTAL = 1,
};

class Hole {
public:
	Hole() {
		this->width = 0;
		this->direction = HORIZONTAL;
		this->bodies[0] = nullptr;
		this->bodies[1] = nullptr;
	}
	Hole(float width, float pos_x, float pos_y, Direction direction, Body* body1, Body* body2 = nullptr)
	{
		this->width = width;
		this->direction = direction;
		this->pos_x = pos_x;
		this->pos_y = pos_y;
		this->bodies[0] = body1;
		this->bodies[1] = body2;
	}

	// The width of the hole
	float width;

	// The position of the body is at the bottom left of the body

	// The X position of the body
	float pos_x;

	// The Y position of the body
	float pos_y;

	// The direction of the hole
	Direction direction;

	// The bodies the hole connects; only one if it connects the body to air
	Body* bodies[2];

	// Get a given body's destination, returns null if
	// this hole isn't connected to the given body
	Body* getDestination(Body* body);

	void update(float deltaTime);
};

#endif