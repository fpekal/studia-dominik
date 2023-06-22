#include "Platform.h"
Platform::Platform(float posX = 0, float posY = 0,
	float sizeX = 0, float sizeY = 0,
	float speedX = 0, bool possibleCollision = false) :
	Movement(posX, posY, sizeX, sizeY, speedX), Collidable(possibleCollision, posX, posY, sizeX, sizeY)
{
	this->possibleCollision = possibleCollision;
	setSpriteForDisplay(createSprite("../data/perfectplatform.png"));
}
Platform::~Platform()
{
	destroySprite(spriteForDisplay);
}

void Platform::setPosX(float PosX) { this->posX = PosX; }
void Platform::setPosY(float PosY) { this->posY = PosY; }
float Platform::getPosX() { return posX; }
float Platform::getPosY() { return posY; }

void Platform::move()
{
	if (getSpeedX() == 0) return;
	if (moveDirection == LEFT) goLeft();
	if (moveDirection == RIGHT) goRight();
}

void Platform::display() {
	SteadyObject::display();
}
void Platform::setSpriteForDisplay(Sprite* spriteForDisplay)
{
	SteadyObject::setSpriteForDisplay(spriteForDisplay);
}

void Platform::setDirectionToRight()
{
	setDirection(Platform::RIGHT);
}

void Platform::setDirectionToLeft()
{
	setDirection(Platform::LEFT);
}

void Platform::setDirection(MoveDirection moveDirection)
{
	this->moveDirection = moveDirection;
}
