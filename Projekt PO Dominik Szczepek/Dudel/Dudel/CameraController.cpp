#include "CameraController.h"
#include "Framework.h"

CameraController::CameraController(SteadyObject* followedObject)
{
	distancePassed = 0;
	this->followedObject = followedObject;
	getScreenSize(canvasWidth,canvasHeight);
}

CameraController::CameraController() : CameraController{nullptr} {}

bool CameraController::isOnUpperHalf() {
	return pixelsAboveHalf() > 0;
}

float CameraController::pixelsAboveHalf() {
	float diff = followedObject->posY - canvasHeight / 2;
	diff *= -1;

	if (diff < 0) return 0;
	return diff;
}

void CameraController::addObjectToActWithCamera(SteadyObject* objectToActWithCamera)
{
	objectsToActWithCamera.push_back(objectToActWithCamera);
}

void CameraController::move() {
	if (isOnUpperHalf()) {				// followed object is on upper half of the screen
		float diff = pixelsAboveHalf(); // How much followed object should go down
		distancePassed += diff;
		followedObject->posY += diff;	// Lower the player
		// And lower every Object acting with camera
		for(SteadyObject* steadyObject : objectsToActWithCamera)
		{
			steadyObject->posY += diff;
		}
	}
}