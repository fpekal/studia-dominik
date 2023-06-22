#include "SteadyObject.h"

SteadyObject::SteadyObject(float posX = 0,float posY = 0,float sizeX = 0,float sizeY = 0) {
	this->posX = posX;
	this->posY = posY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}
SteadyObject::~SteadyObject() {
	//destroySprite(spriteForDisplay);
}
void SteadyObject::setPosX(float PosX) { this->posX = PosX; }
void SteadyObject::setPosY(float PosY) { this->posY = PosY; }
float SteadyObject::getPosX() { return posX; }
float SteadyObject::getPosY() { return posY; }
void SteadyObject::display() {
	if(spriteForDisplay!=nullptr)
		drawSprite(spriteForDisplay,posX,posY);
}

void SteadyObject::setSpriteForDisplay(Sprite* spriteForDisplay)
{
	this->spriteForDisplay = spriteForDisplay;
	if(spriteForDisplay!=nullptr)
	setSpriteSize(spriteForDisplay, sizeX, sizeY);
}
