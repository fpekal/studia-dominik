#include "Scoreboard.h"
#include <Windows.h>

Scoreboard::Scoreboard(float* distancePassed, int* numberOfPassedPlatforms)
{
	distanceIconPath = "../data/rular.png";
	platformIconPath = "../data/perfectplatform.png";
	
	getScreenSize(canvasWidth, canvasHeight);
	fontSizeX = 20; 
	fontSizeY = 30;
	distanceBarPosX = 20;
	distanceBarPosY = 20;
	platformBarPosX = distanceBarPosX;
	platformBarPosY = distanceBarPosY + 1.5 * fontSizeY;


	distance = new NumberDisplayerWithPrefix(distanceIconPath);
	platform = new NumberDisplayerWithPrefix(platformIconPath);

	setPlatformBar();
	setDistanceBar();
	this->distancePassed = distancePassed;
	this->numberOfPassedPlatforms = numberOfPassedPlatforms;
}
Scoreboard::~Scoreboard() {
	delete distance;
	delete platform;
}

void Scoreboard::setDistanceBar()
{
	distance->setPrefixSize(fontSizeY+2/3*fontSizeY);
	distance->setFontSize(fontSizeX, fontSizeY);
}

void Scoreboard::setPlatformBar()
{
	platform->setPrefixSize(fontSizeY + 2 / 3 * fontSizeY);
	platform->setFontSize(fontSizeX, fontSizeY);
}

void Scoreboard::display()
{
	displayDistancePassed(distanceBarPosX, distanceBarPosX);
	displayPlatformPassed(platformBarPosX, platformBarPosY);
}

void Scoreboard::displayDistancePassed(float posX, float posY)
{
	distance->drawNumber((int)*distancePassed/30, posX, posY);
}

void Scoreboard::displayPlatformPassed(float posX, float posY)
{
	platform->drawNumber((int)*numberOfPassedPlatforms, posX, posY);
}
