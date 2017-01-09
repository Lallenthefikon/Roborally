#pragma once

#include "SFML\Graphics.hpp"


class Hud
{
public:
	Hud();
	virtual ~Hud();
	virtual const sf::IntRect getRect() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void setPos(sf::Vector2f& pos) = 0;
};

