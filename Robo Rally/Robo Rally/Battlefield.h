#pragma once

#include "Map.h"
#include "GameState.h"
#include "EntityHandler.h"
#include "Camera.h"


class Battlefield : public GameState
{
public:
	Battlefield(Map* map);
	virtual ~Battlefield();

	virtual void update( bool mouseKeyEvent, bool keyboardEvent, bool mouseMoveEvent, AbstractGame* roborally);
	virtual void render(sf::RenderWindow& window);
	virtual void initialize(sf::RenderWindow& window);

private:

	void renderWorld(sf::RenderWindow& window);
	void renderHud(sf::RenderWindow& window);

	Map* mMap;
	Camera mCamera;

};

