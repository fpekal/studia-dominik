#pragma once
#include "Movement.h"
#include "Platform.h"

class Enemy :
    public Movement
{
public:
	// Is enemy collidable, visible etc.
	bool alive;
	Platform* platformToFollow;
    Enemy(Platform*,float,float);
    ~Enemy();
	void setSpriteForDisplay(const char*);
	void followPlatform();
	void display();
};

