#pragma once
#include "Collidable.h"
#include "Movement.h"
class Platform: public Movement, public Collidable {
public:
	enum MoveDirection {
		RIGHT, LEFT
	};
private:
	MoveDirection moveDirection;

public:
	Platform(float, float, float, float, float, bool);
	~Platform();
	void setPosX(float);
	void setPosY(float);
	float getPosX();
	float getPosY();
	void move();
	void display();
	void setSpriteForDisplay(Sprite*);
	void setDirectionToRight();
	void setDirectionToLeft();

private:
	void setDirection(MoveDirection);
};