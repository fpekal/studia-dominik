#include "Collidable.h"

Collidable::Collidable(bool possibleCollision, float hitboxPosX, float hitboxPosY, float hitboxSizeX, float hitboxSizeY)
{
	this->hitboxPosX = hitboxPosX;
	this->hitboxPosY = hitboxPosY;
	this->hitboxSizeX = hitboxSizeX;
	this->hitboxSizeY = hitboxSizeY;
	this->possibleCollision = possibleCollision;
}
