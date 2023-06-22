#pragma once
#include "DynamicObject.h"
class Movement :
    public DynamicObject
{
private:
	float jumpForce;
public:
	float speedX;
	
	Movement(float, float, float, float, float);

	void jump();
	void goLeft();
	void goRight();
	void addCustomForce(float,float);
	void setCustomVelocityX(float);
	void setCustomVelocityY(float);

	void setJumpForce(float);
	float getSpeedX();
};

