#pragma once

class Sprite;

Sprite* createSprite(const char* path);
void drawSprite(Sprite*, int x, int y);

void getSpriteSize(Sprite* s, int& w, int& h);
void setSpriteSize(Sprite* s, int w, int h);
void destroySprite(Sprite* s);

void getScreenSize(int& w, int& h);

unsigned int getTickCount();

enum class FRKey {
	RIGHT,
	LEFT,
	DOWN,
	UP,
	COUNT
};

enum class FRMouseButton {
	LEFT,
	MIDDLE,
	RIGHT,
	COUNT
};

class Framework {
public:
	virtual void PreInit(int& width, int& height, bool& fullscreen) = 0;
	virtual bool Init() = 0;
	virtual void Close() = 0;
	virtual bool Tick() = 0;
	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) = 0;
	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) = 0;
	virtual void onKeyPressed(FRKey k) = 0;
	virtual void onKeyReleased(FRKey k) = 0;
	virtual const char* GetTitle() = 0;
	virtual ~Framework() {};
};

int run(Framework*);