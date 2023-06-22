#include "BulletManager.h"
#include <algorithm>
BulletManager::BulletManager()
{
	defaultSpeed = 3;
	
}

BulletManager::~BulletManager()
{
	for (Bullet* i : bullets)
		delete i;
}

void BulletManager::fireBullet(float originX, float originY,float directionX, float directionY)
{
	Bullet* newBullet = new Bullet(originX, originY, defaultSpeed, directionX, directionY);
	bullets.push_back(newBullet);
}

void BulletManager::destroyBullet(Bullet* bullet)
{
	std::vector<Bullet*>::iterator i;
	i = std::find(bullets.begin(), bullets.end(),bullet);
	bullets.erase(i);
	delete bullet;
}

void BulletManager::letThemFly()
{
	for (Bullet* i : bullets)
		i->move();
}

void BulletManager::display()
{
	for (Bullet* i : bullets)
		i->display();
}
