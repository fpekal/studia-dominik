#include "Bullet.h"

Bullet::Bullet(float posX, float posY, float speed,float directionX, float directionY): Movement(posX, posY, 20, 20, 0) {
	calculateVelocity(directionX, directionY,speed);
	spriteForDisplay = createSprite("../data/bubble@2x.png");
	setSpriteSize(spriteForDisplay,sizeX,sizeY);
};
Bullet::~Bullet()
{
	destroySprite(spriteForDisplay);
}

void Bullet::calculateVelocity(float directionX, float directionY,float speed)
{
	directionX = directionX - posX;
	directionY = directionY - posY;
	float dist = sqrt(directionX*directionX+directionY*directionY);
	velocityX = (directionX)/dist*speed;
	velocityY = (directionY)/dist*speed;
}
