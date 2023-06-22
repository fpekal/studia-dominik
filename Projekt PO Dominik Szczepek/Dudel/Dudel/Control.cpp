#include "Control.h"

Control::Control(Hero*hero,RelationshipManager* relationshipManager)
{
	this->hero = hero;
	this->relationshipManager = relationshipManager;
}

void Control::keyPressed(FRKey key)
{
	if (key == FRKey::RIGHT) { hero->goRight(); return; }
	if (key == FRKey::LEFT) { hero->goLeft(); return; }
}

void Control::keyRealesed(FRKey key)
{
	if (key == FRKey::RIGHT || key == FRKey::LEFT)
		hero->resetHorizontalMovement();
}

void Control::mousePressed(FRMouseButton mouseButton)
{
	if (mouseButton == FRMouseButton::LEFT) {
		relationshipManager->fire();
	}
	if (mouseButton == FRMouseButton::RIGHT)
		relationshipManager->setActiveFloor();
}

void Control::mouseRealesed(FRMouseButton mouseButton)
{
}
