#pragma once
#include "Hero.h"
#include "RelationshipManager.h"
#include "Framework.h"
class Control
{
	Hero* hero = 0;
	RelationshipManager* relationshipManager;
public:
	Control(Hero*,RelationshipManager*);
	
	void keyPressed(FRKey);
	void keyRealesed(FRKey);
	void mousePressed(FRMouseButton);
	void mouseRealesed(FRMouseButton);
};

