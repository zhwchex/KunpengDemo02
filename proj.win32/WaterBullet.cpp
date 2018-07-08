#include "WaterBullet.h"


WaterBullet::WaterBullet()
{
}


WaterBullet::~WaterBullet()
{
}

WaterBullet * WaterBullet::create(const std::string & filename){
	WaterBullet *myBullet = new WaterBullet();
	if (myBullet &&myBullet->initWithFile(filename)){
		myBullet->autorelease();
		return myBullet;
	}
	CC_SAFE_DELETE(myBullet);
	return nullptr;
}