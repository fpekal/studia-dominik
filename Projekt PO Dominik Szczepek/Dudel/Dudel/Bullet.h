#pragma once
#include "Movement.h"
class Bullet :
    public Movement
{
public:
    Bullet(float posX, float posY, float speed,float directionX, float directionY);
    ~Bullet();
    void calculateVelocity(float directionX,float directionY, float speed);

};

