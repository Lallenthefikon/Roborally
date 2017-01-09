#pragma once
#include <vector>


#include "GameState.h"
#include "MenyRescourses.h"
#include "variablesAndConstants.h"
#include "GraphicFunctions.h"
#include "AbstractGame.h"
#include "Camera.h"


class MainMeny : public GameState
{
public:
	typedef std::vector<sf::Sprite*> Sprites;
	MainMeny();
	~MainMeny();

	virtual void update( bool mouseKeyEvent, bool keyboardEvent, bool mouseMoveEvent, AbstractGame* roborally);
	virtual void render(sf::RenderWindow& window);
	virtual void initialize(sf::RenderWindow& window);
private:

	void renderWorld(sf::RenderWindow& window);
	void renderHud(sf::RenderWindow& window);

	void loadSprites();
	void loadScreen_0();

	void moveHud(sf::Vector2f& cameraPos);
	void checkMouse(AbstractGame* roborally);
	int checkWhatIsClicked();
	void mainMenyEvent(int i);

	void clearmSprites();
	
	Camera mCamera;

	MenyRescourses mMenyRescourses;
	Sprites mSprites;
	Sprites mCurrentSprites;
	sf::Sprite mBackground;

	std::string mMapFilename;
};