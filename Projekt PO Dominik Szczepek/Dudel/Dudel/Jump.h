#pragma once
class Jump
{
protected:
	float jumpForce;
	float numberOfTicksToPeakOfJump;
	float heightOfJump;
	float normalheightOfJump;
	float normalnumberOfTicksToPeakOfJump;

	Jump(float,float);

	void setJumpForce(float);
	virtual float getJumpForce();
	virtual float getHeightOfJump();
	virtual float calculateJumpForce() = 0;
};

