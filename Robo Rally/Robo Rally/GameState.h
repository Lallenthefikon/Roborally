#pragma once

class AbstractGame;

#include <SFML\Graphics.hpp>

class GameState
{
public:
	GameState();
	virtual ~GameState();
	virtual void update(bool mouseKeyEvent, bool keyboardEvent, bool mouseMoveEvent, AbstractGame* roborally) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void initialize(sf::RenderWindow& window) = 0;

};

