#include "GeneralEnemy.h"


GeneralEnemy::GeneralEnemy()
{
}


GeneralEnemy::~GeneralEnemy()
{
}


GeneralEnemy * GeneralEnemy::create(const std::string &filename){
	GeneralEnemy *myEnemy = new GeneralEnemy();
	if (myEnemy &&myEnemy->initWithFile(filename)){
		myEnemy->autorelease();
		return myEnemy;
	}
	CC_SAFE_DELETE(myEnemy);
	return nullptr;
}