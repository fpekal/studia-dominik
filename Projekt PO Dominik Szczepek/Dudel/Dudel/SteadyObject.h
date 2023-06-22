#pragma once
#include "Framework.h"
#include <iostream>
class SteadyObject {

public:
	float posX, posY;
	float sizeX, sizeY;
	Sprite* spriteForDisplay = 0;

	SteadyObject(float,float,float,float);
	virtual ~SteadyObject();

	void setPosX(float);
	void setPosY(float);
	float getPosX();
	float getPosY();

	void display();
	void setSpriteForDisplay(Sprite*);
	
};