#include "../include/body.h"
#include "../include/constants.h"
#include <cmath>

void Hole::update(float deltaTime) {
	//Update based on water depth on either side
	float crossSectionalArea = this->width;

	float deltaH = bodies[0]->waterLevel() - bodies[1]->waterLevel();

	if (std::abs(deltaH) < ALMOSTZERO) return;
	Body* higherBody = deltaH > 0 ? bodies[0] : bodies[1];
	Body* lowerBody = deltaH > 0 ? bodies[1] : bodies[0];
	if (lowerBody->isCapped && lowerBody->maxHeight - lowerBody->waterHeight <= ALMOSTZERO) return;


	float volumeDifference = deltaH * higherBody->width;

	float flowRate = crossSectionalArea * sqrtf(2 * GRAVITY * std::abs(deltaH));
	float deltaVolume = std::min(flowRate * deltaTime, std::abs(volumeDifference / 2));
	deltaVolume = std::min(higherBody->volume(), deltaVolume); // Can't drain more water than is present
	if(lowerBody->isCapped) deltaVolume = std::min(lowerBody->maxHeight * lowerBody->width - lowerBody->volume(), deltaVolume); // Can't overfill the lower body

	higherBody->waterHeight -= deltaVolume / higherBody->width;
	lowerBody->waterHeight += deltaVolume / lowerBody->width;
}

Body* Hole::getDestination(Body* body)
{
	for (size_t i = 0; i < 2; i++)
	{
		if (body == bodies[i])
		{
			return bodies[1 - i];
		}
	}
	return nullptr;
}
