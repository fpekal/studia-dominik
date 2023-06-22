#pragma once
#include "Platform.h"
#include <vector>
#include "EnemyManager.h"
class PlatformManager {
public:
	int numberOfResetPlatforms;
	int canvasWidth, canvasHeight;
	int numberOfPlatforms;
	int numberOfFakePlatforms;
	int maxLengthBetweenPlatforms;
	int percentageForEnemyOnPlatform;
	float platformDefaultSizeX, platformDefaultSizeY;
	std::vector<Platform*> platforms;
	std::vector<Platform*> fakePlatforms;
	Platform* floor = 0;
	
	EnemyManager* enemyManager;

	PlatformManager(float, float,float,EnemyManager*);
	void generatePlatform(float, float, float,bool);
	void generateFakePlatform(float, float, float,bool);
	void displayPlatforms();
	void calculateTopPlatformPlacement(float*,float*);
	void calculateTopFakePlatformPlacement(float*,float*);
	bool chanceTrueFalse(int percentage);
	void movePlatforms();
	void bouncePlatforms();
	void reset();
	void fakeReset();
	void resetPlatform(Platform*);
	void resetFakePlatform(Platform*);
	int indexOfPlatform(Platform *);
	int indexOfFakePlatform(Platform *);
};