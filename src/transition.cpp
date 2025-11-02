#include "../include/transition.h"
#include "../include/constants.h"
#include <cmath>
/*
void Transition::update(float deltaTime) {

	float crossSectionalArea = Transition::host.waterHeight;
	
	float deltaH = Transition::targets[0].waterLevel() - Transition::targets[1].waterLevel();

	if(std::abs(deltaH) < ALMOSTZERO) return;

	float volumeDifference = deltaH * (deltaH > 0 ? Transition::targets[0].width : Transition::targets[1].width);

	float flowRate = crossSectionalArea * sqrtf(2 * GRAVITY * std::abs(deltaH));
	float deltaVolume = std::min(flowRate * deltaTime, std::abs(volumeDifference / 2));

	if(deltaH > 0) {
		Transition::targets[0].waterHeight -= deltaVolume;
		Transition::targets[1].waterHeight += deltaVolume;
	} else {
		Transition::targets[0].waterHeight += deltaVolume;
		Transition::targets[1].waterHeight -= deltaVolume;
	}
}*/


//ASSUMPTIONS:
// - Host doesn't change water level during update