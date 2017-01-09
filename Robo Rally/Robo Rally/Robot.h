#pragma once

#include "Entity.h"

class Robot : public Entity
{
public:
	Robot();
	virtual ~Robot();

	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
};

