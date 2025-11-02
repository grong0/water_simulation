#ifndef TRANSITION_H
#define TRANSITION_H

#include "body.h"

class Transition
{
	public:
		Transition(body_t host, body_t* targets);

		body_t host;
		body_t targets[2];
		void update(float deltaTime);
};

#endif
