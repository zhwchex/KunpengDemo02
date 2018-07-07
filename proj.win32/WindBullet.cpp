#include "WindBullet.h"


WindBullet::WindBullet()
{
}


WindBullet::~WindBullet()
{
}

WindBullet * WindBullet::create(const std::string & filename){
	WindBullet *mySprite = new WindBullet();
	if (mySprite &&mySprite->initWithFile(filename)){
		mySprite->autorelease();
		return mySprite;
	}
	CC_SAFE_DELETE(mySprite);
	return nullptr;
}