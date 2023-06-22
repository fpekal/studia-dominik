#pragma once
#include "Hero.h"
#include "PlatformManager.h"
#include "EnemyManager.h"
#include "BulletManager.h"
class RelationshipManager
{
public:
	bool* death = 0;
	int canvasWidth, canvasHeight;
	int* mouseX = 0;
	int* mouseY = 0;
	bool activeFloor;
	int timeFromActivationFloor;
	Hero* hero = 0;
	PlatformManager* platformManager = 0;
	EnemyManager* enemyManager = 0;
	BulletManager* bulletManager = 0;
	int numberOfPlatformsUnderHero;
	int numberOfPassedPlatforms;
	RelationshipManager(Hero*,PlatformManager*,EnemyManager*,BulletManager*);
	void checkFloorActivationTurnOff();
	void setActiveFloor();
	void collisionHeroWithAllPlatforms();
	void collisionHeroWithAllFakePlatforms();
	void bouncePlatforms();
	void resetOutOfScreenPlatforms();

	void collisionDetection();
	void collisionHeroWithScreenSides();
	void giveAccessToDeath(bool* death);
	void giveAccessToMouse(int* mouseX, int* mouseY);
	void calculatePlatformPassedByHero();
	void fire();
private:
	bool isHeroCollidingWithPlatformFromTop(Platform*);
	bool isPlatformOutOfScreen(Platform*);

	void collisionsWithBullets();
	bool enemyCollidedWithBullet(Enemy* enemy, Bullet* bullet);

	void collisionsWithEnemies();
	bool collisionWithSpecificEnemy(Enemy*);
	bool killingCollisionWithSpecificEnemy(Enemy*);


};

