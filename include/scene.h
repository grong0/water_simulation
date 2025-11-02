#ifndef SCENE_H
#define SCENE_H

#include "constants.h"
#include "body.h"
#include "hole.h"

#define BODY_LIMIT 12
#define HOLE_LIMIT 12

class Scene
{
	private:
		// Each body in the scene
		body_t bodies[BODY_LIMIT];

		// The number of bodies in the scene
		size_t bodyCount;

		// Each hole in the scene
		hole_t holes[HOLE_LIMIT];

		// The number of holes in the scene
		size_t holeCount;

	public:
		// Creates a scene from given bodies of water
		// Scene(body_t* bodies[BODY_LIMIT], hole_t* holes[HOLE_LIMIT]);
        Scene();

		// Gets a given body's neighbors
		body_t** getBodyNeighbors(body_t* body);

		// TODO: reword
		// Updates the scene??
		void update();

		// Adds a new body to the scene, returns whether
		// or not the body was added successfully
		bool addBody(body_t *body);

		// Adds a new hole to the scene, returns whether
		// or not the hole was added successfully
		bool addHole(hole_t *hole);
};

#endif
