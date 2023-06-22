#pragma once
#include "VerticalControl.h"
#include "Movement.h"
#include "Collidable.h"

class Hero : public Movement,public VerticalControl,public Collidable {
public:	
	bool onTheGround;
	float initialJumpHeight;
	int initialTickToPeakOfJump;
	float normalSpeedX;
	
	Hero(float, float, float, float, float, float, float,bool);
	~Hero();

	void setSpriteForDisplay(Sprite*);
	void leftSideOfScreen();
	void rightSideOfScreen();
	void setPosX(float);
	void setPosY(float);
	float getPosX();
	float getPosY();

	void display();
	void move();

	void collisionWithPlatformFromTop();


	//control
	//void keyActionPressed(FRKey);
	//void keyActionReleased();
	//void mouseAction(FRMouseButton);
};