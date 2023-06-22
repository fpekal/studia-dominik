#pragma once
class Collidable {
public:
	float hitboxPosX, hitboxPosY;
	float hitboxSizeX, hitboxSizeY;
public:
	bool possibleCollision;
	Collidable(bool,float,float,float,float);
};

