#pragma once
#include "Physics.h"
#include "Jump.h"
#include "Movement.h"
class VerticalControl :
    public Physics,public Jump
{
public:
    VerticalControl(float,float);

    float getJumpForce();
    float getHeightOfJump();
    float calculateForceOfGravity();
    float calculateJumpForce();
    void calculate();
};

