#include "MapEditor.h"

static const int NrOfTextures = 0;

MapEditor::MapEditor(Map* map) :
mMapEditorRescorces(),
mEntityselector(&mMapEditorRescorces, NrOfTextures, sf::Vector2f(0,0)),
mMap(map),
mMapname(),
mBackground(),
mCamera(),
mWorld(map->getRects())
{

}


MapEditor::~MapEditor(){
	delete mMap;
}

void MapEditor::update(bool mouseKeyEvent, bool keyboardEvent, bool mouseMoveEvent, AbstractGame* roborally){
	mCamera.update(mouseKeyEvent, keyboardEvent, mouseMoveEvent);
	if (variablesAndConstants::getInstance()->cameraMoved)
		moveHud();
}

void MapEditor::render(sf::RenderWindow& window){
	window.draw(mBackground);
	renderWorld(window);
	renderHud(window);
}

void MapEditor::initialize(sf::RenderWindow& window){
	mCamera.setWindow(&window);
}

// Privates

void MapEditor::renderWorld(sf::RenderWindow& window){
	
}

void MapEditor::renderHud(sf::RenderWindow& window){
	mEntityselector.render(window);
}

void MapEditor::moveHud(){
	mEntityselector.setPos(mCamera.getViewPos());
}