#include "../include/body.h"
#include "../include/constants.h"
#include <cmath>
#include <iostream>

float torricelliVelocity(float dh)
{
	return sqrt(2 * GRAVITY * abs(dh)) * (dh >= 0 ? 1 : -1);
}

float torricelliVelocityBetweenPressures(float dh, float pressure1, float pressure2)
{
	return sqrt(2 * (((pressure1 - pressure2) / RHO) + (GRAVITY * abs(dh)))) * ((dh+1)/(abs(dh)+1));
}

Body::Body()
{
	this->isCapped = false;
	this->maxHeight = 0.0f;
	this->waterHeight = 0.0f;
	this->width = 0.0f;
	this->pos_x = 0.0f;
	this->pos_y = 0.0f;
	this->holes = std::vector<Hole*>();
}

Body::Body(bool isCapped, float maxHeight, float waterHeight, float width, float pos_x, float pos_y)
{
	this->isCapped = isCapped;
	this->maxHeight = maxHeight;
	this->waterHeight = waterHeight;
	this->width = width;
	this->pos_x = pos_x;
	this->pos_y = pos_y;

	this->holes = std::vector<Hole*>();
}

void Body::update(float deltaTime)
{
	float volumetricNormal = 0;
	std::vector<float> volumetricFlows;
	for (size_t i = 0; i < this->holes.size(); i++)
	{
		float deltaH = this->holes[i]->getDestination(this)->waterLevel() - this->waterLevel();
		float volumetricFlow = this->holes[i]->width * torricelliVelocity(deltaH);

		if (volumetricFlow > 0 && this->holes[i]->getDestination(this)->volume()) {
			volumetricFlow = this->holes[i]->getDestination(this)->volume();
		}
		else if (volumetricFlow < 0 && this->holes[i]->getDestination(this)->maxHeight - this->holes[i]->getDestination(this)->waterHeight > ALMOSTZERO) {
			volumetricFlow = std::min(volumetricFlow, (this->holes[i]->getDestination(this)->maxHeight - this->holes[i]->getDestination(this)->waterHeight) * this->holes[i]->getDestination(this)->width);
		}


		volumetricFlows.push_back(volumetricFlow);
		volumetricNormal += volumetricFlow;
	}
	volumetricNormal /= holes.size();
	
	float volumetricOutflow = 0;
	for (size_t i = 0; i < this->holes.size(); i++)
	{
		this->holes[i]->getDestination(this)->waterHeight -= std::min(volumetricFlows[i] - volumetricNormal, volumetricFlows[i]) / width;
		volumetricOutflow += std::min(volumetricFlows[i] - volumetricNormal, volumetricFlows[i]);
	}

	this->waterHeight -= volumetricOutflow / this->width;
}

float Body::waterLevel() {
	return pos_y + waterHeight;
}

float Body::volume() {
	return waterHeight * width;
}

bool Body::isFull() {
	return maxHeight - waterHeight <= ALMOSTZERO;
}

std::string Body::toString() {
	return "Body at (" + std::to_string(pos_x) + ", " + std::to_string(pos_y) + "), has a size of " + std::to_string(width) + " by " + std::to_string(maxHeight) + " and has a waterHeight of " + std::to_string(waterHeight);
}


//ASSUMPTIONS:
// - Host doesn't change water level during update