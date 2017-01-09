#include "Camera.h"

static const int MOUSE_OOB_RECT = 15;

Camera::Camera() :
mWindow(),
mCurrentView(),
mMouseLeftOfWindow(false),
mMouseRightOfWindow(false),
mMouseTopOfWindow(false),
mMouseBottomOfWindow(false),
mWindowNeedUpdate(false),
mZoom(1)
{
}

Camera::~Camera()
{
}

void Camera::update(bool mouseKeyEvent, bool keyboardEvent, bool mouseMoveEvent){
	variablesAndConstants::getInstance()->cameraMoved = false;

	if (mouseMoveEvent){
		mouseViewMove();
	}
	if (mWindowNeedUpdate){
		updateWindow();
		variablesAndConstants::getInstance()->cameraMoved = true;
	}	
}


void Camera::setWindow(sf::RenderWindow* window){
	mWindow = window;
	mCurrentView = window->getView();
}

sf::Vector2f Camera::getViewPos()const{
	sf::Vector2f temp = mCurrentView.getCenter();
	temp.x -= mCurrentView.getSize().x / 2;
	temp.y -= mCurrentView.getSize().y / 2;
	return temp;
}

sf::Vector2f Camera::getViewSize()const{
	return mCurrentView.getSize();
}

// Privates



void Camera::mouseViewMove(){
	if (mouseInBounds()){
		mMouseLeftOfWindow = false;
		mMouseRightOfWindow = false;
		mMouseTopOfWindow = false;
		mMouseBottomOfWindow = false;

		mWindowNeedUpdate = false;
	}
	else {
		if (variablesAndConstants::getInstance()->mousePos.x <= MOUSE_OOB_RECT)
			mMouseLeftOfWindow = true;
		else if (variablesAndConstants::getInstance()->mousePos.x >= mCurrentView.getSize().x - MOUSE_OOB_RECT)
			mMouseRightOfWindow = true;
		if (variablesAndConstants::getInstance()->mousePos.y <= MOUSE_OOB_RECT)
			mMouseTopOfWindow = true;
		else if (variablesAndConstants::getInstance()->mousePos.y >= mCurrentView.getSize().y - MOUSE_OOB_RECT)
			mMouseBottomOfWindow = true;

		mWindowNeedUpdate = true;
	}
}

bool Camera::mouseInBounds(){

	sf::Vector2i mousePos(variablesAndConstants::getInstance()->mousePos);

	if (mousePos.y > MOUSE_OOB_RECT &&
		mousePos.y < mCurrentView.getSize().y - MOUSE_OOB_RECT &&
		mousePos.x > MOUSE_OOB_RECT &&
		mousePos.x < mCurrentView.getSize().x - MOUSE_OOB_RECT){
		return true;
	}
	else{
		return false;
	}
}

void Camera::updateWindow(){
	sf::Vector2f temp;
	if (mMouseLeftOfWindow)
		temp.x -= variablesAndConstants::getInstance()->cameraSpeed * mZoom;
	else if (mMouseRightOfWindow)
		temp.x += variablesAndConstants::getInstance()->cameraSpeed * mZoom;
	if (mMouseTopOfWindow)
		temp.y -= variablesAndConstants::getInstance()->cameraSpeed * mZoom;
	else if (mMouseBottomOfWindow)
		temp.y += variablesAndConstants::getInstance()->cameraSpeed * mZoom;
	mCurrentView.move(temp);

	mWindow->setView(mCurrentView);
}
