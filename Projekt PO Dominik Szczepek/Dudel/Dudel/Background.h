#pragma once
#include "Framework.h"
class Background 
{
    int canvasWidth, canvasHeight;
    int sizeX, sizeY;
    int numberOfSpritesHorizontally, numberOfSpritesVertically;
public:

    Sprite* sprite = 0;
    Background(const char*);
    ~Background();
    void display();
    void calculateNumberOfSprites();
};

