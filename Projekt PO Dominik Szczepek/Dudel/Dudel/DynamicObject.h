#pragma once
#include "SteadyObject.h"
class DynamicObject : 
	public SteadyObject {
protected:
	float velocityX, velocityY;
public:
	DynamicObject(float, float, float, float);
	virtual ~DynamicObject();

	void setVelocityX(float);
	void setVelocityY(float);
	float getVelocityX();
	float getVelocityY();

	void move();
	void addForce(float,float);
	void resetHorizontalMovement();
	void resetVerticalMovement();
};