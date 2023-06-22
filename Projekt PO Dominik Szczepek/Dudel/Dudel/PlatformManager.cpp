#include "PlatformManager.h"
#include <random>
PlatformManager::PlatformManager(float platformDefaultSizeX,
	float platformDefaultSizeY,float maxLengthBetweenPlatforms,EnemyManager* enemyManager)
{
	this->platformDefaultSizeX = platformDefaultSizeX;
	this->platformDefaultSizeY = platformDefaultSizeY;
	this->maxLengthBetweenPlatforms = maxLengthBetweenPlatforms;
	percentageForEnemyOnPlatform = 10;
	this->enemyManager = enemyManager;
	getScreenSize(canvasWidth, canvasHeight);
	numberOfPlatforms = canvasHeight/platformDefaultSizeY; // even in the worst scenario there will be no platforms poping up on the screen, they will slide from heaven like angels.
	numberOfFakePlatforms = 10;
	numberOfResetPlatforms = 0;
	floor = new Platform(-100, canvasHeight,canvasWidth + 100, platformDefaultSizeY,0,false);
	for (int i = 0; i < numberOfPlatforms; i++)
		generatePlatform(platformDefaultSizeX, platformDefaultSizeY, 0.05, true);
	for (int i = 0; i < numberOfFakePlatforms; i++) {
		generateFakePlatform(platformDefaultSizeX, platformDefaultSizeY, 0.05, true);
	}
}
void PlatformManager::generateFakePlatform(float sizeX, float sizeY, float speedX, bool possibleCollision) {
	float posX = 0;
	float posY = canvasHeight - platformDefaultSizeY;
	calculateTopFakePlatformPlacement(&posX, &posY);
	Platform* newPlatform = new Platform(posX, posY, sizeX, sizeY, speedX, possibleCollision);
	newPlatform->setSpriteForDisplay(createSprite("../data/perfectfakeplatform.png"));
	fakePlatforms.push_back(newPlatform);
}

void PlatformManager::generatePlatform(float sizeX, float sizeY, float speedX, bool possibleCollision) {
	float posX = 0;
	float posY = canvasHeight - platformDefaultSizeY;
	calculateTopPlatformPlacement(&posX, &posY);

	Platform* newPlatform = new Platform(posX, posY, sizeX, sizeY, speedX, possibleCollision);
	platforms.push_back(newPlatform);
	newPlatform->setSpriteForDisplay(createSprite("../data/perfectplatform.png"));
	if (chanceTrueFalse(percentageForEnemyOnPlatform))
		enemyManager->addEnemy(newPlatform);
}

bool PlatformManager::chanceTrueFalse(int percentage) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> xrnd(1, 100);
	return xrnd(gen) <= percentage;
}
void PlatformManager::calculateTopPlatformPlacement(float* posX, float*posY)
{
	// random
	std::random_device rd;
	std::mt19937 gen(rd()); // Mersenne Twister 19937 generator
	std::uniform_int_distribution<int> xrnd(0, canvasWidth - platformDefaultSizeX);
	*posX = (float)xrnd(gen); // generates a random number

	std::uniform_int_distribution<int> yrnd(platformDefaultSizeY, maxLengthBetweenPlatforms);
	if (!platforms.empty())
		*posY = (float)platforms[platforms.size() - 1]->posY - yrnd(gen);
}
void PlatformManager::calculateTopFakePlatformPlacement(float* posX, float* posY)
{
	// random
	std::random_device rd;
	std::mt19937 gen(rd()); // Mersenne Twister 19937 generator
	std::uniform_int_distribution<int> xrnd(0, canvasWidth - platformDefaultSizeX);
	*posX = (float)xrnd(gen); // generates a random number

	std::uniform_int_distribution<int> yrnd(platformDefaultSizeY, canvasWidth*2);
	if (!fakePlatforms.empty())
		*posY = (float)fakePlatforms[fakePlatforms.size() - 1]->posY - yrnd(gen);
}
void PlatformManager::movePlatforms()
{
	for (Platform* p : platforms) {
		p->move();
		p->Movement::move();
	}
	for (Platform* p : fakePlatforms) {
		p->move();
		p->Movement::move();
	}
}

void PlatformManager::bouncePlatforms()
{
	for (Platform* p : platforms) {
		if (p->posX < 0) p->setDirectionToRight();
			else if (p->posX + p->sizeX > canvasWidth) p->setDirectionToLeft();
	}
	for (Platform* p : fakePlatforms) {
		if (p->posX < 0) p->setDirectionToRight();
		else if (p->posX + p->sizeX > canvasWidth) p->setDirectionToLeft();
	}
}

void PlatformManager::displayPlatforms() {
	for (Platform* p : platforms) {
		p->display();
	}
	for (Platform* p : fakePlatforms) {
		p->display();
	}
}
void PlatformManager::reset() {
	numberOfResetPlatforms++;
	resetPlatform(platforms[0]);
}
void PlatformManager::fakeReset() {
	resetFakePlatform(fakePlatforms[0]);
}
void PlatformManager::resetPlatform(Platform* p) {
		float posX = 0, posY = canvasHeight;
		calculateTopPlatformPlacement(&posX, &posY);
		p->setPosX(posX);
		p->setPosY(posY);
		auto i = std::find(platforms.begin(), platforms.end(), p);
		platforms.erase(i);
		platforms.push_back(p);
}
void PlatformManager::resetFakePlatform(Platform* p) {
	float posX = 0, posY = canvasHeight;
	calculateTopFakePlatformPlacement(&posX, &posY);
	p->setPosX(posX);
	p->setPosY(posY);
	auto i = std::find(fakePlatforms.begin(), fakePlatforms.end(), p);
	fakePlatforms.erase(i);
	fakePlatforms.push_back(p);
}

int PlatformManager::indexOfPlatform(Platform* platform)
{
	for(int i = 0; i < platforms.size();i++)
		if(platforms[i] == platform)
			return i;
	return -1;
}

int PlatformManager::indexOfFakePlatform(Platform* platform)
{
	for (int i = 0; i < fakePlatforms.size(); i++)
		if (fakePlatforms[i] == platform)
			return i;
	return -1;
}

