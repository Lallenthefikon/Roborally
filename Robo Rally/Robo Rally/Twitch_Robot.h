#pragma once

#include "Robot.h"

class Twitch_Robot : public Robot
{
public:
	Twitch_Robot(sf::Vector2i pos);
	virtual ~Twitch_Robot();

	virtual void update();
	virtual void render(sf::RenderWindow& window);
};

