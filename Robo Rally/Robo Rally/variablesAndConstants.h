#pragma once
#include <SFML\Graphics.hpp>

class variablesAndConstants
{
public:
	~variablesAndConstants();
	static variablesAndConstants* getInstance();

	sf::Vector2i windowSize = sf::Vector2i(1900, 1000);
	float cameraSpeed = 7;
	bool cameraMoved = false;

	sf::Vector2i mousePos;
	sf::Vector2f worldMousePos;
	sf::Mouse::Button mousebutton;
	bool mouseButtonPressed = false;
	bool mouseButtonClicked = false;
	bool mouseDragging = false;
	bool mouseDragged = false;
	int mouseButtonCount = 0;

private:
	variablesAndConstants();

};

