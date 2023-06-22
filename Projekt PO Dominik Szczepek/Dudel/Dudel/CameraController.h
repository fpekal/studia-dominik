#pragma once
#include "SteadyObject.h"
#include "PlatformManager.h"
#include <vector>
// This class will force player to be on the lower half of the screen.
// And if player would try to go higher, everything on screen will be moved down.

class CameraController
{
public:
	float distancePassed;
	SteadyObject* followedObject;
	std::vector<SteadyObject*> objectsToActWithCamera;
	int canvasWidth,canvasHeight;
	CameraController(SteadyObject* followedObject);
	CameraController();
	
	bool isOnUpperHalf();

	float pixelsAboveHalf();
	void addObjectToActWithCamera(SteadyObject*);
	void move();
};
