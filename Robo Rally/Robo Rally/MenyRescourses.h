#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class MenyRescourses
{
public:
	MenyRescourses();
	~MenyRescourses();

	sf::Texture& getTexture(int i);
	sf::Texture& getBackgroundTexture(){ return mBackgroundTexture; }
private:
	
	void loadImages();
	void loadTextures();

	sf::Image mMenyspritesheetIMG;
	sf::Image mBackgroundIMG;

	std::vector<sf::Texture*> mTextures;
	sf::Texture mBackgroundTexture;
};

