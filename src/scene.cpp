#include "../include/scene.h"
#include "../include/constants.h"
#include "../include/body.h"

#include "math.h"

// Scene::Scene() : bodyCount(0), holeCount(0) {
// 	for (size_t i = 0; i < HOLE_LIMIT; i++) {
// 		this->holes[i] = hole_t(); // Assuming hole_t has a default constructor
// 	}
// }
Scene::Scene() {
	this->bodyCount = 0;
	this->holeCount = 0;
}

void Scene::update(float deltaTime) {
	for (size_t i = 0; i < this->bodyCount; i++)
	{
		if (this->bodies[i]->isFull() && this->bodies[i]->isCapped) {
			this->bodies[i]->update(deltaTime);
		}
	}
	for (size_t i = 0; i < this->holeCount; i++) {
		this->holes[i]->update(deltaTime);
	}
}

/*body_t** Scene::getBodyNeighbors(body_t* body) {
	for (size_t i = 0; i < this->holeCount; i++)
	{
		
	}

	return nullptr;
}*/

bool Scene::addBody(Body *body)
{
	if (this->bodyCount < BODY_LIMIT)
	{
		this->bodies[this->bodyCount] = body;
		this->bodyCount += 1;
		return true;
	}
	return false;
}

bool Scene::addHole(Hole *hole)
{
	if (this->holeCount < HOLE_LIMIT)
	{
		this->holes[this->holeCount] = hole;
		hole->bodies[0]->holes.push_back(hole);
		if(hole->bodies[1] != nullptr) {
			hole->bodies[1]->holes.push_back(hole);
		}
		this->holeCount += 1;
		return true;
	}
	return false;
}
