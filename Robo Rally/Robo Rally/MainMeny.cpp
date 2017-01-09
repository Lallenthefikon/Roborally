#include "MainMeny.h"

MainMeny::MainMeny() :
mMenyRescourses(),
mSprites(),
mCurrentSprites(),
mBackground(mMenyRescourses.getBackgroundTexture()),
mCamera()
{

}


MainMeny::~MainMeny(){
	clearmSprites();
}

void MainMeny::update( bool mouseKeyEvent, bool keyboardEvent, bool mouseMoveEvent, AbstractGame* roborally){
	mCamera.update(mouseKeyEvent, keyboardEvent, mouseMoveEvent);
	if (mouseKeyEvent)
		checkMouse(roborally);
		
}

void MainMeny::render(sf::RenderWindow& window){
	renderWorld(window);
	renderHud(window);
}

void MainMeny::initialize(sf::RenderWindow& window){
	mCamera.setWindow(&window);
	loadSprites();
	loadScreen_0();
}



// Privates

void MainMeny::renderWorld(sf::RenderWindow& window){

}

void MainMeny::renderHud(sf::RenderWindow& window){
	window.draw(mBackground);
	for (int i = 0; i < mCurrentSprites.size(); i++){
		window.draw(*mCurrentSprites[i]);
	}
}

void MainMeny::loadSprites(){
	mSprites.push_back(new sf::Sprite(mMenyRescourses.getTexture(0)));
	mSprites.back()->setPosition(200, 200);

	mSprites.push_back(new sf::Sprite(mMenyRescourses.getTexture(1)));
	mSprites.back()->setPosition(800, 200);

	mSprites.push_back(new sf::Sprite(mMenyRescourses.getTexture(2)));
	mSprites.back()->setPosition(500, 500);
}

void MainMeny::loadScreen_0(){
	mCurrentSprites.clear();
	mCurrentSprites.push_back(mSprites[0]);
	mCurrentSprites.push_back(mSprites[1]);
	mCurrentSprites.push_back(mSprites[2]);
}

void MainMeny::moveHud(sf::Vector2f& cameraPos){
}

void MainMeny::checkMouse(AbstractGame* roborally){
	if (variablesAndConstants::getInstance()->mouseButtonClicked){
		
		switch (checkWhatIsClicked()){
		case 1:
			roborally->exitGame();
			break;
		case 2:
			mMapFilename = "Resources/Maps/Prebuilt maps/Test Map_0.txt";
			roborally->changeGamestate(AbstractGame::BATTLEFIELD, mMapFilename);
			break;
		case 3:
			mMapFilename = "Resources/Maps/Prebuilt maps/Test Map_0.txt";
			roborally->changeGamestate(AbstractGame::MAPEDITOR, mMapFilename);
			break;
		default:
			break;
		}
		variablesAndConstants::getInstance()->mouseButtonClicked = false;
	}

}


int MainMeny::checkWhatIsClicked(){
	int v = 0;
	for (int i = 0; i < mCurrentSprites.size(); i++){
		if (GraphicFunctions::getInstance()->isSpriteClicked(&mCurrentSprites[i]->getTextureRect(),
			mCurrentSprites[i]->getPosition(), variablesAndConstants::getInstance()->mousePos))
			v = i + 1;
	}
	return v;
}

void MainMeny::mainMenyEvent(int i){
	switch (i){
	case 0:
		break;


	default:
		break;
	}
}

void MainMeny::clearmSprites(){
	while (!mSprites.empty()){
		delete mSprites.back();
		mSprites.pop_back();
	}
}