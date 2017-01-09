#pragma once

#include "Hud.h"
#include "MapEditorRescorces.h"

#include <vector>

class EntitySelector : public Hud
{
public:
	EntitySelector(MapEditorRescorces* mapeditorRescorces, int iStartpoint, sf::Vector2f posOnScreen);
	virtual ~EntitySelector();

	virtual const sf::IntRect getRect();
	virtual void render(sf::RenderWindow& window);
	virtual void setPos(sf::Vector2f& pos);

private:

	void loadSprites(MapEditorRescorces* mapeditorRescorces, int iStartpoint);

	void moveAllSprites(sf::Vector2f vector);

	sf::Sprite mBackgroundHud;
	typedef std::vector<sf::Sprite*> Sprites;
	Sprites mSprites;

	sf::Vector2f mPosOnSceen;
};

