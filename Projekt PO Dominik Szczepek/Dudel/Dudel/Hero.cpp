#include "Hero.h"

Hero::Hero(float posX = 0, float posY = 0,
	float sizeX = 0, float sizeY = 0,
	float speedX = 0,
	float numberOfTicksToPeakOfJump = 0, float heightOfJump = 0, bool possibleCollision = false) :
	
	VerticalControl{numberOfTicksToPeakOfJump, heightOfJump}, 
	Movement{posX, posY, sizeX, sizeY, speedX},
	Collidable{possibleCollision,posX,posY,sizeX*0.75,sizeY}
{	
	int w, h;
	getScreenSize(w, h);
	this->speedX = w /(numberOfTicksToPeakOfJump*2);
	normalSpeedX = this->speedX;
	setSpriteForDisplay(createSprite("../data/blue-lik-left.png"));
	onTheGround = true;
	Movement::setJumpForce(getJumpForce()); // it doesn't have access to other function but still can't decide? heh
}
Hero::~Hero() {
	destroySprite(spriteForDisplay);
}
void Hero::setSpriteForDisplay(Sprite* spriteForDisplay)
{
	SteadyObject::setSpriteForDisplay(spriteForDisplay);
}
void Hero::leftSideOfScreen() {
	Jump::numberOfTicksToPeakOfJump = normalnumberOfTicksToPeakOfJump;
	speedX = normalSpeedX;
	calculate();
}
void Hero::rightSideOfScreen() {
	speedX = normalSpeedX * 1.5;
	Jump::numberOfTicksToPeakOfJump = normalnumberOfTicksToPeakOfJump/1.5;
	calculate();
}
void Hero::setPosX(float PosX) { this->posX = PosX; }
void Hero::setPosY(float PosY) { this->posY = PosY; }
float Hero::getPosX() { return posX; }
float Hero::getPosY() { return posY; }

void Hero::display() {

	SteadyObject::display();
}


void Hero::move() {
	
	if (onTheGround) {
		jump(); 
		onTheGround = false;
	}
	addCustomForce(0,getForceOfGravity());
	Movement::move();
}

void Hero::collisionWithPlatformFromTop()
{
	onTheGround = true;
}

/*
void Hero::keyActionPressed(FRKey key) {
	if (key == FRKey::LEFT) {
		goLeft();
		return;
	}
	if (key == FRKey::RIGHT) {
		goRight();
		return;
	}
	if (key == FRKey::UP) {
		jump();
		return;
	}
}
void Hero::keyActionReleased() {
	resetHorizontalMovement();
}*/
