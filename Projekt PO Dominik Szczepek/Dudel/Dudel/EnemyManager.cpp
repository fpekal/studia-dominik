#include "EnemyManager.h"

EnemyManager::EnemyManager(float defaultSizeX, float defaultSizeY)
{
	this->defaultSizeX = defaultSizeX;
	this->defaultSizeY = defaultSizeY;
}

void EnemyManager::addEnemy(Platform* platformToFollow)
{
	enemies.push_back(new Enemy(platformToFollow,defaultSizeX, defaultSizeY));
}

void EnemyManager::deleteEnemies() {
	for (Enemy* e : enemies)
		delete e;
	enemies.clear();
}

void EnemyManager::display()
{
	for (Enemy* e : enemies) {
		e->display();
	}
}
