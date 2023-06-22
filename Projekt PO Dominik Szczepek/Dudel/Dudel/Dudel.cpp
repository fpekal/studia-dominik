#include <iostream>
#include "Framework.h"
#include "Hero.h"
#include "Platform.h"
#include "PlatformManager.h"
#include "RelationshipManager.h"
#include "Control.h"
#include "CameraController.h"
#include "Scoreboard.h"
#include "Background.h"
#include "EnemyManager.h"
#include "BulletManager.h"

class MyFramework : public Framework {

public:

	bool death;

	int canvasWidth, canvasHeight;
	bool canvasFullscreen;

	int mouseX;
	int mouseY;
	
	Background* background = 0;
	Hero* hero = 0;
	Control* control = 0;
	PlatformManager* platformManager=0;
	RelationshipManager* relationshipManager =0;
	CameraController* cameraController;
	Scoreboard* scoreboard;
	EnemyManager* enemyManager;
	BulletManager* bulletManager;
	

	MyFramework(int width, int height, bool fullscreen) {
		canvasWidth = width;
		canvasHeight = height;
		canvasFullscreen = fullscreen;
	}
	MyFramework() {
		canvasWidth = 600;
		canvasHeight = 800;
		canvasFullscreen = 0;
	}

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = canvasWidth;
		height = canvasHeight;
		fullscreen = canvasFullscreen;
	}

	virtual bool Init() {
		mouseX = 0;
		mouseY = 0;
		getScreenSize(canvasWidth, canvasHeight);
		creation();
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		if(death) 
			gameOver();
		background->display();
		relationshipManager->collisionDetection();
		cameraController->move();
		platformManager->movePlatforms();
		hero->move();
		platformManager->displayPlatforms();
		hero->display();
		enemyManager->display();
		scoreboard->display();
		bulletManager->display();
		bulletManager->letThemFly();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		mouseX = x;
		mouseY = y;
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if(!isReleased)
		control->mousePressed(button);
	}

	virtual void onKeyPressed(FRKey k) {
		control->keyPressed(k);
	}

	virtual void onKeyReleased(FRKey k) {
		control->keyRealesed(k);
	}

	virtual const char* GetTitle() override
	{
		return "Fully original game";
	}
	void gameOver() {
		delete background; 
		delete hero;
		delete control;
		delete platformManager;
		delete relationshipManager;
		delete cameraController;
		delete scoreboard;
		delete enemyManager;
		delete bulletManager;
		creation();
	}
	void creation() {
		background = new Background("../data/jungle-bck@2x.png");
		hero = new Hero(canvasWidth / 2, canvasHeight / 2, 80, 80, 0, 200, 200, true);
		enemyManager = new EnemyManager(60,100);
		platformManager = new PlatformManager(200, 30, hero->getHeightOfJump(),enemyManager);
		bulletManager = new BulletManager();
		relationshipManager = new RelationshipManager(hero, platformManager, enemyManager, bulletManager);
		relationshipManager->giveAccessToDeath(&death);
		relationshipManager->giveAccessToMouse(&mouseX, &mouseY);
		control = new Control(hero,relationshipManager);
		cameraController = new CameraController(hero);
		addAllObjectsActingWithCamera();
		scoreboard = new Scoreboard(&cameraController->distancePassed, &relationshipManager->numberOfPassedPlatforms);
		death = false;
	}
	void addAllObjectsActingWithCamera() {
		for (SteadyObject* a : platformManager->platforms)
			cameraController->addObjectToActWithCamera(a);
		for (SteadyObject* a : platformManager->fakePlatforms)
			cameraController->addObjectToActWithCamera(a);

	}
};

void getFromCommandLineArguments(int argc, char* argv[], int* width, int* height, bool* fullscreen) {
	while (argc > 0) {
		if (std::string(argv[0]) == "-window") {
			std::string encodedSize = argv[1];

			auto separator = encodedSize.find('x');

			std::string widthStr = encodedSize.substr(0, separator);
			std::string heightStr = encodedSize.substr(separator + 1);

			*width = std::atoi(widthStr.c_str());
			*height = std::atoi(heightStr.c_str());

			argc -= 2;
			argv += 2;
			continue;
		}
		else if (std::string(argv[0]) == "-fullscreen") {
			*fullscreen = true;
			
			argc -= 1;
			argv += 1;
			continue;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc > 1) {
		int width = 600;
		int height = 800;
		bool fullscreen = false;
		getFromCommandLineArguments(argc - 1, argv + 1, &width, &height, &fullscreen);
		return run(new MyFramework(width, height, fullscreen));
	}
	else {
		return run(new MyFramework);// (int)argv[1], (int)argv[2], (bool)argv[3]));
	}
}

