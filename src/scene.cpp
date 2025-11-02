#include "../include/scene.h"

// Scene::Scene() : bodyCount(0), holeCount(0) {
// 	for (size_t i = 0; i < HOLE_LIMIT; i++) {
// 		this->holes[i] = hole_t(); // Assuming hole_t has a default constructor
// 	}
// }
Scene::Scene() {
	this->bodyCount = 0;
	this->holeCount = 0;
}

void Scene::update() {
	return;
}

body_t** Scene::getBodyNeighbors(body_t* body) {
	for (size_t i = 0; i < this->holeCount; i++)
	{
		/* code */
	}

	return nullptr;
}

bool Scene::addBody(body_t *body)
{
	if (this->bodyCount < BODY_LIMIT)
	{
		this->bodies[this->bodyCount] = *body;
		this->bodyCount += 1;
		return true;
	}
	return false;
}

bool Scene::addHole(hole_t *hole)
{
	if (this->holeCount < HOLE_LIMIT)
	{
		this->holes[this->holeCount] = *hole;
		this->holeCount += 1;
		return true;
	}
	return false;
}
