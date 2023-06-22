#include "VerticalControl.h"
#include <cmath>
VerticalControl::VerticalControl(float numberOfTicksToPeakOfJump,float heightOfJump) :
	Jump{ numberOfTicksToPeakOfJump, heightOfJump }
{
	setForceOfGravity(calculateForceOfGravity());
	setJumpForce(calculateJumpForce());
}

float VerticalControl::calculateForceOfGravity()
{

	return 2 * getHeightOfJump() / (numberOfTicksToPeakOfJump * numberOfTicksToPeakOfJump + numberOfTicksToPeakOfJump);
}

float VerticalControl::calculateJumpForce()
{
	return sqrt(2*getHeightOfJump()*getForceOfGravity());
	return numberOfTicksToPeakOfJump*getForceOfGravity();
}

void VerticalControl::calculate()
{
	setForceOfGravity(calculateForceOfGravity());
	setJumpForce(calculateJumpForce());
}


float VerticalControl::getJumpForce()
{
	return Jump::getJumpForce();
}

float VerticalControl::getHeightOfJump()
{
	return Jump::getHeightOfJump();
}
