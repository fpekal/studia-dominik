#include "RelationshipManager.h"
#include <vector>

RelationshipManager::RelationshipManager(Hero* hero, PlatformManager* platformManager, EnemyManager* enemyManager, BulletManager* bulletManager)
{
	numberOfPassedPlatforms = 0;
	this->hero = hero;
	this->platformManager = platformManager;
	this->enemyManager = enemyManager;
	this->bulletManager = bulletManager;
	getScreenSize(canvasWidth, canvasHeight);
	
}
void RelationshipManager::checkFloorActivationTurnOff()
{
	if (!activeFloor) return;
	if (timeFromActivationFloor > 20000)
		activeFloor = false;
}
void RelationshipManager::setActiveFloor() {
	platformManager->floor->possibleCollision = true;
}
void RelationshipManager::giveAccessToDeath(bool *death){
	this->death = death;
}
void RelationshipManager::giveAccessToMouse(int* mouseX, int* mouseY) {
	this->mouseX = mouseX;
	this->mouseY = mouseY;
}
void RelationshipManager::collisionDetection()
{
	resetOutOfScreenPlatforms();
	bouncePlatforms();
	collisionHeroWithAllPlatforms();
	collisionHeroWithAllFakePlatforms();
	collisionHeroWithScreenSides();
	calculatePlatformPassedByHero();
	collisionsWithEnemies();
	collisionsWithBullets();
	checkFloorActivationTurnOff();
}

void RelationshipManager::collisionHeroWithScreenSides() {

	if (hero->getPosY() > canvasHeight) {
		*death = true;
		return;
	}
	if (hero->getPosX() > canvasWidth) {
		hero->setPosX(1-hero->sizeX);
		return;
	}
	if (hero->getPosX() < -hero->sizeX){
		hero->setPosX(canvasWidth - 1);
		return;
	}
	if (hero->getPosX() < canvasWidth/2) {
		hero->leftSideOfScreen();
		return;
	}
	if (hero->getPosX() < canvasWidth / 2) {
		hero->rightSideOfScreen();
	}
	return;
	if (hero->getPosY() < 0)
		std::string yeahRight = "Almost there.";
}

void RelationshipManager::collisionHeroWithAllPlatforms()
{
	Platform* collidedPlatform = 0;
	if (isHeroCollidingWithPlatformFromTop(platformManager->floor)) collidedPlatform = platformManager->floor;
	else 
	for (Platform* p : platformManager->platforms) 
		if (isHeroCollidingWithPlatformFromTop(p)) {
			collidedPlatform = p;
			break;
		}
	if (collidedPlatform == nullptr) return;
	hero->setPosY(collidedPlatform->getPosY() - hero->sizeY);
	hero->resetVerticalMovement();
	hero->collisionWithPlatformFromTop();
	numberOfPlatformsUnderHero = platformManager->indexOfPlatform(collidedPlatform);

}
void RelationshipManager::collisionHeroWithAllFakePlatforms()
{
	for (Platform* p : platformManager->fakePlatforms)
			if (isHeroCollidingWithPlatformFromTop(p)) {
				platformManager->resetFakePlatform(p);
				break;
			}
}
bool RelationshipManager::isHeroCollidingWithPlatformFromTop(Platform* platform)
{
	if (hero == nullptr) return false;
	if (hero->getVelocityY() < 0) return false;
	if (!platform->possibleCollision) return false;
	if ((hero->getPosY() + hero->sizeY >= platform->posY) && (hero->sizeY + hero->getPosY() <= platform->posY + platform->sizeY / 2)) {
		if ((hero->getPosX() + hero->sizeX / 2 >= platform->posX) && (hero->getPosX() + hero->sizeX / 2 <= platform->posX + platform->sizeX)) {
		return true;
		}
	}
	return false;
}
void RelationshipManager::calculatePlatformPassedByHero()
{
	numberOfPassedPlatforms = platformManager->numberOfResetPlatforms + numberOfPlatformsUnderHero;
}

void RelationshipManager::fire()
{
	bulletManager->fireBullet(hero->getPosX() - 10, hero->getPosY() + hero->sizeY * 0.5f, *mouseX, *mouseY);
}

void RelationshipManager::collisionsWithBullets() {
	// Iterate over all enemies on screen
	for (Enemy* enemy : enemyManager->enemies) {
		// Iterate over all bullets
		for (Bullet* bullet : bulletManager->bullets) {
			
			bool collided = enemyCollidedWithBullet(enemy, bullet);

			if (collided) {
				delete enemy;
				std::vector<Enemy*>::iterator iter;
				iter = std::find(enemyManager->enemies.begin(), enemyManager->enemies.end(), enemy);
				enemyManager->enemies.erase(iter);
				bulletManager->destroyBullet(bullet);
			}

		}
	}
}

bool RelationshipManager::enemyCollidedWithBullet(Enemy* enemy, Bullet* bullet) {
	int enemyLeftEdge = enemy->getPosX();
	int enemyRightEdge = enemyLeftEdge + enemy->sizeX;

	int enemyUpEdge = enemy->getPosY();
	int enemyDownEdge = enemyUpEdge + enemy->sizeY;

	int bulletPosX = bullet->getPosX();
	int bulletPosY = bullet->getPosY();

	// If bullet position is inside of enemy hitbox
	if (bulletPosX > enemyLeftEdge && bulletPosX < enemyRightEdge &&
		bulletPosY > enemyUpEdge && bulletPosY < enemyDownEdge) {
		return true;
	}

	return false;
}

void RelationshipManager::collisionsWithEnemies()
{
	for (int i = 0; i < enemyManager->enemies.size(); i++) {
		bool killingCollided = killingCollisionWithSpecificEnemy(enemyManager->enemies[i]);

		// If the player has stepped on the enemy, reset the platform it was on
		if (killingCollided) {
			delete enemyManager->enemies[i];
			enemyManager->enemies.erase(enemyManager->enemies.begin()+i);
			break;
		}
		else {
			// If the player didn't step on the enemy but the collision occured anyway, it means
			// the hero should die in pain
			bool collided = collisionWithSpecificEnemy(enemyManager->enemies[i]);
			if (collided) {
				*death = true;
			}
		}
	}
}
// Checks if the player touches enemy in any way, even if the player should kill the enemy
bool RelationshipManager::collisionWithSpecificEnemy(Enemy* enemy) {
	int playersLeftEdge = hero->getPosX();
	int playersRightEdge = playersLeftEdge + hero->hitboxSizeX;

	int playersUpEdge = hero->getPosY();
	int playersDownEdge = playersUpEdge + hero->sizeY;

	int enemyLeftEdge = enemy->getPosX();
	int enemyRightEdge = enemyLeftEdge + enemy->sizeX;

	int enemyUpEdge = enemy->getPosY();
	int enemyDownEdge = enemyUpEdge + enemy->sizeY;


	if (
		playersLeftEdge > enemyRightEdge ||
		playersRightEdge < enemyLeftEdge ||
		playersUpEdge > enemyDownEdge ||
		playersDownEdge < enemyUpEdge
		)
		return false;
	else
		return true;
}
// Checks if the player jumped on the head of the enemy
bool RelationshipManager::killingCollisionWithSpecificEnemy(Enemy* enemy) {
	// Maximal y value where enemy is still hittable
	int maxPosY = enemy->getPosY();

	// Minimal y value where enemy is still hittable
	int minPosY = maxPosY - 10;

	// When player's bottom edge is in this range, then the player jumped on the enemy
	int playersBottomEdge = hero->getPosY() + hero->sizeY;
	if (playersBottomEdge > minPosY && playersBottomEdge < maxPosY) {
		// And now horizontal check
		if ((hero->getPosX() > enemy->getPosX() + enemy->sizeX) ||
			(hero->getPosX() + hero->hitboxSizeX < enemy->getPosX()))
			return false;
		else
			return true;
	}

	return false;
}

bool RelationshipManager::isPlatformOutOfScreen(Platform* platform)
{
	return platform->getPosY()>canvasHeight+enemyManager->defaultSizeY;
}
void RelationshipManager::bouncePlatforms()
{
	for (Platform* p : platformManager->platforms) {
		if (p->posX < 0) p->setDirectionToRight();
		else if (p->posX + p->sizeX > canvasWidth) p->setDirectionToLeft();
	}
}
void RelationshipManager::resetOutOfScreenPlatforms()
{
	if (isPlatformOutOfScreen(platformManager->platforms[0])) {
		platformManager->reset();
		
	}
	if (isPlatformOutOfScreen(platformManager->fakePlatforms[0])) {
		platformManager->fakeReset();
	}
}






