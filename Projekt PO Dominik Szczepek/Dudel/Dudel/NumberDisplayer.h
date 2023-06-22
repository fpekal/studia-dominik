#pragma once
#include "Framework.h"
#include <string>
class NumberDisplayer {
protected:
    
    class Digit {
    public:
        Sprite* sprite = 0;
        int sizeX, sizeY;

        Digit();
        Digit(const char* path);
        ~Digit();

        void draw(int posX, int posY);
        void changeSize(int sizeX, int sizeY);
    };

    static const std::string sprites_paths[10];
    Digit* digits[10];

public:
    NumberDisplayer();
    ~NumberDisplayer();
    void drawNumber(int number, int posX, int posY);
    void setFontSize(int sizeX, int sizeY);
    
};

class NumberDisplayerWithPrefix : public NumberDisplayer {
protected:
    int dx, dy;
    Digit* prefix;

public:

    NumberDisplayerWithPrefix(const char* prefix_path);
    ~NumberDisplayerWithPrefix();

    void drawNumber(int number, int posX, int posY);
    void setPrefixSize(int sizeX, int sizeY);
    void setPrefixSize(int sizeY);
    void setShift(int dx, int dy);
};