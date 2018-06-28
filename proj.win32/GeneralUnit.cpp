#include "GeneralUnit.h"


GeneralUnit::GeneralUnit()
{
}


GeneralUnit::~GeneralUnit()
{
}


GeneralUnit * GeneralUnit::create(const std::string &filename){
	GeneralUnit *myUnit = new GeneralUnit();
	if (myUnit && myUnit->initWithFile(filename)){
		myUnit->autorelease();
		return myUnit;
	}
	CC_SAFE_DELETE(myUnit);
	return nullptr;
}