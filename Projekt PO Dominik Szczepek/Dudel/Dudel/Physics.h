#pragma once
#include "DynamicObject.h"
class Physics{
private:
	float forceOfGravity;
public:
	Physics();

	void setForceOfGravity(float);
	float getForceOfGravity();

	virtual float calculateForceOfGravity() = 0;
};