#include "Battlefield.h"


Battlefield::Battlefield(Map* map):
mMap(map),
mCamera()
{
}


Battlefield::~Battlefield()
{
	delete mMap;
}

void Battlefield::update( bool mouseKeyEvent, bool keyboardEvent, bool mouseMoveEvent, AbstractGame* roborally){
	mCamera.update(mouseKeyEvent, keyboardEvent, mouseMoveEvent);
}

void Battlefield::render(sf::RenderWindow& window){
	renderWorld(window);
	renderHud(window);
}

void Battlefield::initialize(sf::RenderWindow& window){
	mCamera.setWindow(&window);
}


// Privates

void Battlefield::renderWorld(sf::RenderWindow& window){

}

void Battlefield::renderHud(sf::RenderWindow& window){

}