#include "Physics.h"
Physics::Physics() {
	forceOfGravity = 0;
}
void Physics::setForceOfGravity(float forceOfGravity)
{
	this->forceOfGravity = forceOfGravity;
}
float Physics::getForceOfGravity()
{
	return forceOfGravity;
}