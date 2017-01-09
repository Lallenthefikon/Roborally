#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class MapEditorRescorces
{
public:
	MapEditorRescorces();
	~MapEditorRescorces();

	sf::Texture& getTexture(int i);
	sf::Texture& getBackgroundTexture(){ return mBackgroundTexture; }


private:

	void loadImages();
	void loadTextures();

	sf::Image mBackgroundIMG;
	sf::Image mSpritesheetIMG;

	std::vector<sf::Texture*> mTextures;
	sf::Texture mBackgroundTexture;
};

