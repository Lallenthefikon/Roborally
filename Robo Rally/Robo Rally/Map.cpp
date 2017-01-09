#include "Map.h"


Map::Map():
mGrid(new xGrid),
mGridRects(){
}


Map::~Map(){
	clearMap();
}

void Map::addGridRect(sf::Vector2i startingPoint, sf::Vector2i size){
	int xDifference = startingPoint.x + size.x - mGrid->size();
	int yDifference;
	if (xDifference > 0){
		for (int i = xDifference; i > 0; i--){
			mGrid->push_back(new yGrid);
		}
	}
	for (int i = startingPoint.x; i < startingPoint.x + size.x; i++){
		yDifference = startingPoint.y - mGrid->at(i)->size();
		if (yDifference > 0){
			for (int index3 = yDifference; index3 > 0; index3--){
				mGrid->at(i)->push_back(0);
			}
		}
		for (int index4 = 0; index4 < size.y; index4++){
			mGrid->at(i)->push_back(new Entities);
		}
	}
	mGridRects.push_back(sf::IntRect(startingPoint, size));
}

void Map::moveEntity(Entity* entity, sf::Vector2i newPos){

}

std::vector<sf::IntRect> Map::getRects()const{
	return mGridRects;
}

// Privates

void Map::clearMap(){
	while (!mGrid->empty()){
		while (!mGrid->back()->empty()){
			if (mGrid->back()->back() != 0){
				for (Entities::iterator i = mGrid->back()->back()->begin(); i != mGrid->back()->back()->end(); i++){
					delete *i;
				}
				mGrid->back()->back()->clear();
			}
			delete mGrid->back()->back();
			mGrid->back()->pop_back();
		}
		delete mGrid->back();
		mGrid->pop_back();
	}
	delete mGrid;
}