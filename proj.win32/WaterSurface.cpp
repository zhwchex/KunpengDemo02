#include "WaterSurface.h"
//Nastiest designs ever!
#include "HeroSprite.h"
#include "Stage1GameplayLayer.h"
//Nastiest designs ever!

WaterSurface::WaterSurface()
{
}


WaterSurface::~WaterSurface()
{
}

WaterSurface * WaterSurface::create(const std::string & filename){
	WaterSurface *myBullet = new WaterSurface();
	if (myBullet &&myBullet->initWithFile(filename)){
		myBullet->autorelease();
		return myBullet;
	}
	CC_SAFE_DELETE(myBullet);
	return nullptr;
}

void WaterSurface::onEnter(){
	//this->setPositionY(this->getPositionY()+111);
	//this->schedule(schedule_selector(WaterSurface::myUpdate));
	Sprite::onEnter();
}
void WaterSurface::myUpdate(float dt){
	//this->setPositionY(this->getPositionY() - 1);

	HeroSprite * kp = ((Stage1GameplayLayer *) this->getParent())->kunpeng;
	if (kp != nullptr){
		kp->setPositionX(kp->getPositionX()+1);
		if (kp->isBird){
			if (kp->getPositionY() < this->getPositionY()){
				kp->transformFromBirdToFish();
			}
		}
		else if (kp->isFish){
			if (kp->getPositionY() > this->getPositionY()){
				kp->transformFromFishToBird();
			}
		}
	}
}