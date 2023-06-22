#include "Background.h"

Background::Background(const char* path)
{
	numberOfSpritesHorizontally = 0;
	numberOfSpritesVertically = 0;
	sprite = createSprite(path);
	getSpriteSize(sprite, sizeX, sizeY);
	getScreenSize(canvasWidth, canvasHeight);
	calculateNumberOfSprites();
}
Background::~Background() {
	destroySprite(sprite);
}
void Background::display()
{
	for (int i = 0; i < numberOfSpritesHorizontally; i++)
		for (int j = 0; j < numberOfSpritesVertically; j++)
			if(sprite != nullptr)
				drawSprite(sprite, sizeX * i, sizeY * j);
}

void Background::calculateNumberOfSprites()
{
	numberOfSpritesHorizontally=canvasWidth / sizeX+1;
	numberOfSpritesVertically=canvasHeight/ sizeY+1;
}
