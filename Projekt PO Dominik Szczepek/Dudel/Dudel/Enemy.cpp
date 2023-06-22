#include "Enemy.h"
#include "Platform.h"

Enemy::Enemy(Platform* platformToFollow,float sizeX,float sizeY):
	Movement(platformToFollow->getPosX(), platformToFollow->getPosY(),
			sizeX, sizeY, platformToFollow->getSpeedX())
{
	this->platformToFollow = platformToFollow;
	spriteForDisplay = createSprite("../data/ooga-right@2x.png");
	setSpriteSize(spriteForDisplay,sizeX,sizeY);
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	alive = true;
}

Enemy::~Enemy() {
	destroySprite(spriteForDisplay);
}

void Enemy::followPlatform()
{
	setPosX(platformToFollow->getPosX() + platformToFollow->sizeX/2);
	setPosY(platformToFollow->getPosY() - sizeY);
}

void Enemy::display()
{
	followPlatform();
	SteadyObject::display();
}


void Enemy::setSpriteForDisplay(const char* path)
{
	destroySprite(spriteForDisplay);
	spriteForDisplay = createSprite(path);
	SteadyObject::setSpriteForDisplay(spriteForDisplay);
}
