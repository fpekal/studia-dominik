#include "NumberDisplayer.h"
#include <sstream>

NumberDisplayer::Digit::Digit() : sprite{ nullptr }, sizeX{ 0 }, sizeY{ 0 } {}

NumberDisplayer::Digit::Digit(const char* path) {
    sprite = createSprite(path);
    getSpriteSize(sprite, sizeX, sizeY);
}

NumberDisplayer::Digit::~Digit()
{
   destroySprite(sprite);
}

void NumberDisplayer::Digit::draw(int posX, int posY) {
    if(sprite!=nullptr)
        drawSprite(sprite, posX, posY);
}

void NumberDisplayer::Digit::changeSize(int sizeX, int sizeY) {
    setSpriteSize(sprite, sizeX, sizeY);
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

NumberDisplayer::NumberDisplayer() {
    for (int i = 0; i < 10; i++) {
        digits[i] = new Digit(sprites_paths[i].c_str());
    }
}

NumberDisplayer::~NumberDisplayer()
{
    for (Digit* digit : digits) {
        delete digit;
    }
}

void NumberDisplayer::setFontSize(int sizeX, int sizeY) {
    for (Digit* digit : digits) {
        digit->changeSize(sizeX, sizeY);
    }
}

void NumberDisplayer::drawNumber(int number, int posX, int posY) {
    std::stringstream ss;
    ss << number;
    std::string convertedNumber = ss.str();

    for (int i = 0; i < convertedNumber.length(); i++) {
        int spriteNum = convertedNumber[i] - '0';

        if (spriteNum < 0 || spriteNum > 9) spriteNum = 0;

        Digit* n = digits[spriteNum];
        n->draw(posX, posY);
        posX += n->sizeX;
    }

}

const std::string NumberDisplayer::sprites_paths[10]
{
   "../data/0.png",
   "../data/1.png",
   "../data/2.png",
   "../data/3.png",
   "../data/5.png",
   "../data/6.png",
   "../data/6.png",
   "../data/7.png",
   "../data/8.png",
   "../data/9.png"
};



NumberDisplayerWithPrefix::NumberDisplayerWithPrefix(const char* prefix_path) {
    prefix = new Digit(prefix_path);
    dx = 0;
    dy = 0;
}

NumberDisplayerWithPrefix::~NumberDisplayerWithPrefix()
{
    delete prefix;
}

void NumberDisplayerWithPrefix::setPrefixSize(int sizeX, int sizeY) {
    prefix->changeSize(sizeX, sizeY);
}

void NumberDisplayerWithPrefix::setPrefixSize(int sizeY)
{
    int spriteSizeRatio;
    int spirteSizeX, spirteSizeY;
    getSpriteSize(prefix->sprite, spirteSizeX, spirteSizeY);
    spriteSizeRatio = spirteSizeX / spirteSizeY;
    prefix->changeSize(sizeY*spriteSizeRatio, sizeY);
}

void NumberDisplayerWithPrefix::setShift(int dx, int dy) {
    this->dx = dx;
    this->dy = dy;
}

void NumberDisplayerWithPrefix::drawNumber(int number, int posX, int posY) {
    prefix->draw(posX + dx, posY + dy);
    NumberDisplayer::drawNumber(number, posX + prefix->sizeX, posY);
}
