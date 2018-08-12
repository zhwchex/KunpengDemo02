#include "Rock.h"
//Nastiest designs ever!
#include "HeroSprite.h"
#include "Stage1GameplayLayer.h"
#include "AudioManager.h"
//Nastiest designs ever!
#define upY 0
#define downY 500

Rock::Rock()
{

}


Rock::~Rock()
{
}



Rock * Rock::create(const std::string &filename){
	Rock *rock = new Rock();

	if (rock && rock->initWithFile(filename)){
		rock->autorelease();
		return rock;
	}
	CC_SAFE_DELETE(rock);
	return nullptr;
}


void Rock::onEnter(){
	Sprite::onEnter();
}

void Rock::myUpdate(float dt){
	

	//¼ì²éÖ÷½Ç¿¿½ü
	auto tempGameplayLayer = (Stage1GameplayLayer*)this->getParent();
	auto hero = (HeroSprite*)tempGameplayLayer->kunpeng;
	if (this->getBoundingBox().intersectsRect(hero->getBoundingBox())){
		hero->getHurtGeneral(10);
	}
}


void Rock::wanderAbout(){
	myUpdate(0);
}

void Rock::setPlace(int x, bool inTheSky){
	this->setPosition(x, inTheSky ? upY : downY);
}

void Rock::Lockhoving(){
	if (lock == 0){
		lock = 1;
		auto an = Animate::create(this->hoveringAnimation);
		this->runAction(Sequence::create(an, an, nullptr));
		auto delayTime = DelayTime::create(1.0f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}
}