#pragma once
#include "Bullet.h"
#include <vector>
class BulletManager
{
public:
	float defaultSpeed;
	std::vector<Bullet*> bullets;
	BulletManager();
	~BulletManager();
	void fireBullet(float originX,float originY, float mouseX,float mouseY);
	void destroyBullet(Bullet* );
	void letThemFly();
	void display();
};

