#include "Rock.h"
//Nastiest designs ever!
#include "HeroSprite.h"
#include "Stage1GameplayLayer.h"
//Nastiest designs ever!
#define upY 0
#define downY 500
Rock::Rock()
{
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/pipe0.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/pipe0.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/pipe1.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/pipe1.png");
	this->hoveringAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->hoveringAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->hoveringAnimation->retain();
}


Rock::~Rock()
{
}



Rock * Rock::create(const std::string &filename){
	Rock *rock = new Rock();

	if (rock &&rock->initWithFile(filename)){
		rock->autorelease();
		return rock;
	}
	CC_SAFE_DELETE(rock);
	return nullptr;
}


void Rock::onEnter(){
	//this->setPositionY(this->getPositionY()+111);
	//this->schedule(schedule_selector(Rock::myUpdate));
	Sprite::onEnter();
}

void Rock::myUpdate(float dt){
	//播放动画
	//auto action = Animate::create(hoveringAnimation);
	//this->runAction(RepeatForever::create(action));
	//this->runAction(Animate::create(this->hoveringAnimation));
	Lockhoving();

	//检查主角靠近
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