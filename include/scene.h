#ifndef SCENE_H
#define SCENE_H

#include "constants.h"
#include "body.h"

#define BODY_LIMIT 12
#define HOLE_LIMIT 12

class Scene
{
	private:
		// Each body in the scene
		Body* bodies[BODY_LIMIT];

		// The number of bodies in the scene
		size_t bodyCount;

		// Each hole in the scene
		Hole* holes[HOLE_LIMIT];

		// The number of holes in the scene
		size_t holeCount;

		// Calculates the velocity between two points where
		// the input is the difference between the two heights
		static float torricelliVelocity(float dh);
		
		// Calculates the velocity between two water heights where
		// the input is the difference between the two heights and
		// includes the difference of pressure between the two points.
		static float torricelliVelocityBetweenPressures(float dh, float pressure1, float pressure2);

	public:
		// Creates a scene from given bodies of water
		// Scene(Body* bodies[BODY_LIMIT], Hole* holes[HOLE_LIMIT]);
        Scene();

		// Gets a given body's neighbors
		Body** getBodyNeighbors(Body* body);

		// TODO: reword
		// Updates the scene??
		void update(float deltaTime);

		// Adds a new body to the scene, returns whether
		// or not the body was added successfully
		bool addBody(Body* body);

		// Adds a new hole to the scene, returns whether
		// or not the hole was added successfully
		bool addHole(Hole* hole);

		// Returns the bodies for GUI
		Hole** getHolesForGUI();

		Body** getBodiesForGUI();
};

#endif
