#include "Jump.h"

Jump::Jump(float numberOfTicksToPeakOfJump, float heightOfJump)
{
	this->numberOfTicksToPeakOfJump = numberOfTicksToPeakOfJump;
	this->heightOfJump = heightOfJump;
	normalheightOfJump = heightOfJump;
	normalnumberOfTicksToPeakOfJump = numberOfTicksToPeakOfJump;
	jumpForce = 0;
}

void Jump::setJumpForce(float jumpForce)
{
	this->jumpForce = jumpForce;
}

float Jump::getJumpForce()
{
	return jumpForce;
}

float Jump::getHeightOfJump()
{
	return heightOfJump;
}
