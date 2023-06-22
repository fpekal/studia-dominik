#pragma once
#include "NumberDisplayer.h"
#include "Framework.h"
class Scoreboard
{
private:
	int canvasWidth,canvasHeight;
	float distanceBarPosX, distanceBarPosY;
	float platformBarPosX, platformBarPosY;
	float fontSizeX,fontSizeY;
	const char* distanceIconPath;
	const char* platformIconPath;
public:
	NumberDisplayerWithPrefix* distance = 0;
	NumberDisplayerWithPrefix* platform = 0;
	float* distancePassed = 0;
	int* numberOfPassedPlatforms = 0;
	Scoreboard(float*,int*);
	~Scoreboard();
	void setDistanceBar();
	void setPlatformBar();
	void display();
	void displayDistancePassed(float posX, float posY);
	void displayPlatformPassed(float posX, float posY);

};

