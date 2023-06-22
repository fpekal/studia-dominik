#include "Movement.h"
Movement::Movement(	float posX = 0, float posY = 0,
					float sizeX = 0, float sizeY = 0, 
					float speedX = 0) :
	DynamicObject{ posX,posY,sizeX,sizeY} {
	this->speedX = speedX;
}
void Movement::jump() {
	addForce(0,-jumpForce);
}
void Movement::goLeft() {
	setVelocityX(-speedX);
}
void Movement::goRight() {
	setVelocityX(speedX);
}

void Movement::addCustomForce(float forceX, float forceY)
{
	addForce(forceX,forceY);
}

void Movement::setCustomVelocityX(float velocityX)
{
	setVelocityX(velocityY);
}

void Movement::setCustomVelocityY(float velocityY)
{
	setVelocityY(velocityY);
}

void Movement::setJumpForce(float jumpForce)
{
	this->jumpForce = jumpForce;
}

float Movement::getSpeedX()
{
	return speedX;
}


//float Movement::calculateJumpForce() {
	//int howManyTicksToPeak;
	//howManyTicksToPeak = (-forceGravity + sqrt(forceGravity * forceGravity + 8 * forceGravity * heightOfJump)) / (2 * forceGravity);
	//return sqrt(2 * forceGravity * heightOfJump);
	//return howManyTicksToPeak;
	//return 1;
//}