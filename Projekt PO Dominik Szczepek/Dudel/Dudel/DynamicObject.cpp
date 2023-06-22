#include "DynamicObject.h"
DynamicObject::DynamicObject(float posX = 0, float posY = 0, float sizeX = 0, float sizeY = 0) :
	SteadyObject{posX,posY,sizeX,sizeY} {
	velocityX = 0;
	velocityY = 0;
}
DynamicObject::~DynamicObject(){
	
}
void DynamicObject::setVelocityX(float velocityX) { 
	this->velocityX = velocityX;
}
void DynamicObject::setVelocityY(float velocityY) {
	this->velocityY = velocityY;
}
float DynamicObject::getVelocityX() {
	return velocityX;
}
float DynamicObject::getVelocityY() {
	return velocityY;
}

void DynamicObject::move() {
	posX += velocityX;
	posY += velocityY;
}
void DynamicObject::addForce(float forceX,float forceY) {
	velocityX += forceX;
	velocityY += forceY;
}

void DynamicObject::resetHorizontalMovement() {
	velocityX = 0;
}
void DynamicObject::resetVerticalMovement() {
	velocityY = 0;
}