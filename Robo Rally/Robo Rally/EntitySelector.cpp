#include "EntitySelector.h"


EntitySelector::EntitySelector(MapEditorRescorces* mapeditorRescorces, int iStartpoint,
	sf::Vector2f posOnScreen) :
mBackgroundHud(mapeditorRescorces->getTexture(iStartpoint)),
mSprites(),
mPosOnSceen(posOnScreen)
{
	loadSprites(mapeditorRescorces, iStartpoint);
}


EntitySelector::~EntitySelector()
{
}

const sf::IntRect EntitySelector::getRect(){
	return mBackgroundHud.getTextureRect();
}

void EntitySelector::render(sf::RenderWindow& window){
	window.draw(mBackgroundHud);
	for (int i = 0; i < mSprites.size(); i++){
		window.draw(*mSprites[i]);
	}
}

void EntitySelector::setPos(sf::Vector2f& pos){
	sf::Vector2f difference = (pos + mPosOnSceen) - mBackgroundHud.getPosition();
	mBackgroundHud.move(difference);
	//moveAllSprites(difference);
}

// Privates

void EntitySelector::loadSprites(MapEditorRescorces* mapeditorRescorces, int iStartpoint){
	mSprites.push_back(new sf::Sprite(mapeditorRescorces->getTexture(iStartpoint + 1)));
	mSprites.back()->setPosition(mBackgroundHud.getPosition().x + 200, mBackgroundHud.getPosition().x + 200);

	mSprites.push_back(new sf::Sprite(mapeditorRescorces->getTexture(iStartpoint + 2)));
	mSprites.back()->setPosition(mBackgroundHud.getPosition().x + 1000, mBackgroundHud.getPosition().x + 200);
}

void EntitySelector::moveAllSprites(sf::Vector2f vector){
	for (int i = 0; i < mSprites.size(); i++){
		mSprites[i]->move(vector);
	}
}