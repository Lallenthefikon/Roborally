#pragma once

#include <SFML\Graphics.hpp>

#include <vector>

class World
{
public:
	typedef std::vector<sf::IntRect> Rects;
	typedef std::vector<sf::Sprite*> Sprites;

	World(Rects rects);
	~World();

	Sprites mGridSprites;

private:

	void loadSprites(Rects rects);
};

