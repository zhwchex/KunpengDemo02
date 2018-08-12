#include "ThunderCloud.h"
//Nastiest designs ever!
#include "HeroSprite.h"
#include "Stage1GameplayLayer.h"
#include "AudioManager.h"
//Nastiest designs ever!
#define upY 0
#define downY 500
ThunderCloud::ThunderCloud()
{
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/leidian_0.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/leidian_1.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/leidian_2.png");
	this->hoveringAnimation->setDelayPerUnit(0.1f);  // 设置动画帧率
	this->hoveringAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->hoveringAnimation->retain();
}


ThunderCloud::~ThunderCloud()
{
}



ThunderCloud * ThunderCloud::create(const std::string &filename){
	ThunderCloud *thunderCloud = new ThunderCloud();

	if (thunderCloud && thunderCloud->initWithFile(filename)){
		thunderCloud->autorelease();
		return thunderCloud;
	}
	CC_SAFE_DELETE(thunderCloud);
	return nullptr;
}


void ThunderCloud::onEnter(){
	//this->setPositionY(this->getPositionY()+111);
	//this->schedule(schedule_selector(ThunderCloud::myUpdate));
	Sprite::onEnter();
}

void ThunderCloud::myUpdate(float dt){
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


void ThunderCloud::wanderAbout(){
	myUpdate(0);
}

void ThunderCloud::setPlace(int x, bool inTheSky){
	this->setPosition(x, inTheSky ? upY : downY);
}

void ThunderCloud::Lockhoving(){
	if (lock == 0){
		lock = 1;
		auto an = Animate::create(this->hoveringAnimation);
		this->runAction(Sequence::create(an, an, nullptr));
		auto delayTime = DelayTime::create(0.4f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}
}