#include "MapEditorRescorces.h"


MapEditorRescorces::MapEditorRescorces()
{
	loadImages();
	loadTextures();
}


MapEditorRescorces::~MapEditorRescorces()
{
}

sf::Texture& MapEditorRescorces::getTexture(int i){
	return *mTextures[i];
}

void MapEditorRescorces::loadImages(){
	mSpritesheetIMG.loadFromFile("Resources/MainMeny Rescourses/Images/34742.jpg");
	mBackgroundIMG.loadFromFile("Resources/MainMeny Rescourses/Images/robo rally.jpg");
}

void MapEditorRescorces::loadTextures(){

	// Background
	mBackgroundTexture.loadFromImage(mBackgroundIMG);

	// Spritesheet
	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mSpritesheetIMG, sf::IntRect(0, 0, 300, 300));

	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mSpritesheetIMG, sf::IntRect(100, 0, 300, 300));

	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mSpritesheetIMG, sf::IntRect(0, 100, 300, 300));
}
