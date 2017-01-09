#include "RoboRally.h"



RoboRally::RoboRally() :
mGamestate(AbstractGame::Gamestate::MAINMENY),
mCurrentGamestate(GamestateFactory::createMainMeny()),
mMouseKeyEvent(false),
mMouseMoveEvent(false),
mKeyboardEvent(false),
mExitGame(false),
mGamestateChanged(false)
{
}


RoboRally::~RoboRally()
{
}

void RoboRally::runGame(){
	sf::RenderWindow window(sf::VideoMode(1900, 1000), "Robbo Rally");
	window.setFramerateLimit(60);
	mCurrentGamestate->initialize(window);

	while (window.isOpen()){

		checkEvents(window);

		window.clear();
		mCurrentGamestate->update(mMouseKeyEvent, mKeyboardEvent, mMouseMoveEvent, this);
		mCurrentGamestate->render(window);
		window.display();

		mMouseKeyEvent = false;
		mMouseMoveEvent = false;
		mKeyboardEvent = false;

		if (mGamestateChanged){
			changeGameStateEXE();
			mCurrentGamestate->initialize(window);
		}
		if (mExitGame)
			window.close();
	}
}

void RoboRally::changeGamestate(AbstractGame::Gamestate gamestate){
	mGamestate = gamestate;
	mGamestateChanged = true;
}

void RoboRally::changeGamestate(AbstractGame::Gamestate gamestate, std::string filename){
	mGamestate = gamestate;
	mGamestateChanged = true;
	mMapFilename = filename;
}

void RoboRally::exitGame(){
	mExitGame = true;
}

// Privates

void RoboRally::changeGameStateEXE(){
	delete mCurrentGamestate;
	switch (mGamestate){
	case AbstractGame::MAINMENY:
		mCurrentGamestate = GamestateFactory::createMainMeny();
		break;
	case AbstractGame::BATTLEFIELD:
		mCurrentGamestate = GamestateFactory::createBattlefield(MapGenerator::getInstance()->generateMap(mMapFilename));
		break;
	case AbstractGame::MAPEDITOR:
		mCurrentGamestate = GamestateFactory::createMapEditor(MapGenerator::getInstance()->generateMap(mMapFilename));
	default:
		break;
	}
	mGamestateChanged = false;
}

void RoboRally::checkEvents(sf::RenderWindow& window){
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{


		case sf::Event::Closed:
			window.close();
			break;



		case sf::Event::MouseMoved:
			mMouseMoveEvent = true;
			if (variablesAndConstants::getInstance()->mouseButtonPressed)
				variablesAndConstants::getInstance()->mouseDragging = true;
			variablesAndConstants::getInstance()->mouseButtonPressed = false;
			variablesAndConstants::getInstance()->mousePos = sf::Mouse::getPosition(window);
			variablesAndConstants::getInstance()->worldMousePos = window.mapPixelToCoords(variablesAndConstants::getInstance()->mousePos);
			break;



		case sf::Event::MouseButtonPressed:
			mMouseKeyEvent = true;
			variablesAndConstants::getInstance()->mouseButtonCount += 1;
			if ((!variablesAndConstants::getInstance()->mouseButtonPressed) && (!variablesAndConstants::getInstance()->mouseDragging)){
				variablesAndConstants::getInstance()->mouseButtonPressed = true;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
					variablesAndConstants::getInstance()->mousebutton = sf::Mouse::Middle;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
					variablesAndConstants::getInstance()->mousebutton = sf::Mouse::Right;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					variablesAndConstants::getInstance()->mousebutton = sf::Mouse::Left;
			}
			break;



		case sf::Event::MouseButtonReleased:
			mMouseKeyEvent = true;
			variablesAndConstants::getInstance()->mouseButtonCount -= 1;
			if (variablesAndConstants::getInstance()->mouseButtonCount == 0){
				if (variablesAndConstants::getInstance()->mouseButtonPressed){
					variablesAndConstants::getInstance()->mouseButtonClicked = true;
					variablesAndConstants::getInstance()->mouseButtonPressed = false;
				}
				if (variablesAndConstants::getInstance()->mouseDragging){
					variablesAndConstants::getInstance()->mouseDragged = true;
					variablesAndConstants::getInstance()->mouseDragging = false;
				}
			}
			break;



		default:
			break;
		}
	}
}