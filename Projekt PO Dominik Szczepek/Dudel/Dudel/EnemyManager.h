#pragma once
#include "Enemy.h"
#include "Platform.h"
#include <vector>
class EnemyManager
{
public:
    float defaultSizeX, defaultSizeY;
    std::vector<Enemy*> enemies;
    EnemyManager(float defaultSizeX,float defaultSizeY);
    void addEnemy(Platform* platformToFollow);
    void deleteEnemies();
    void display();
};

