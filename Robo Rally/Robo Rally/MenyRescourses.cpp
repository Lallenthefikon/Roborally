#include "MenyRescourses.h"


MenyRescourses::MenyRescourses()
{
	loadImages();
	loadTextures();
}


MenyRescourses::~MenyRescourses()
{
}

sf::Texture& MenyRescourses::getTexture(int i){
	return *mTextures[i];
}

// Privates

void MenyRescourses::loadImages(){
	mMenyspritesheetIMG.loadFromFile("Resources/MainMeny Rescourses/Images/34742.jpg");
	mBackgroundIMG.loadFromFile("Resources/MainMeny Rescourses/Images/robo rally.jpg");
}

void MenyRescourses::loadTextures(){

	// Background
	mBackgroundTexture.loadFromImage(mBackgroundIMG);

	// Spritesheet
	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mMenyspritesheetIMG, sf::IntRect(0, 0, 300, 300));
	
	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mMenyspritesheetIMG, sf::IntRect(300, 0, 300, 300));

	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mMenyspritesheetIMG, sf::IntRect(0, 300, 300, 300));
}