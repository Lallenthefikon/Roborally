#pragma once

#include "GameState.h"
#include "Map.h"
#include "EntitySelector.h"
#include "MapEditorRescorces.h"
#include "variablesAndConstants.h"
#include "Camera.h"
#include "World.h"

class MapEditor : public GameState
{
public:
	MapEditor(Map* map);
	virtual ~MapEditor();

	virtual void update(bool mouseKeyEvent, bool keyboardEvent, bool mouseMoveEvent, AbstractGame* roborally);
	virtual void render(sf::RenderWindow& window);
	virtual void initialize(sf::RenderWindow& window);

private:

	void renderWorld(sf::RenderWindow& window);
	void renderHud(sf::RenderWindow& window);

	void moveHud();

	void writeMapToFile();

	MapEditorRescorces mMapEditorRescorces;
	EntitySelector mEntityselector;
	World mWorld;

	std::string mMapname;
	Map* mMap;

	Camera mCamera;

	sf::Sprite mBackground;

	
};

