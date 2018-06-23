#include "HeroSprite.h"


HeroSprite::HeroSprite()
{
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_01.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_02.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_03.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_04.jpg");
	this->hoveringAnimation->setDelayPerUnit(0.5f);
	this->hoveringAnimation->setRestoreOriginalFrame(true);

	ValueMap info;
	info["FrameId"] = Value("Frame3");
	info["three"] = Value(3);
	log("here three = %s,",info["FrameId"].asString());

	hoveringAnimation->getFrames().at(3)->setUserInfo(info);

	EventListenerCustom * flyingEvtLsnCstm = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this,info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		log("Target %p with data %s , three = %d. ", userData->target, Value(userData->userInfo).getDescription().c_str(), *userData->userInfo == info);
		//log("Value(userData->userInfo).asString = %s",Value(userData->userInfo).asString());
		this->setPositionY(this->getPositionY()+33);
	});

	_eventDispatcher->addEventListenerWithFixedPriority(flyingEvtLsnCstm,-1);

	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
	this->hoveringAnimation->retain();

	



	this->movingUpAnimation = Animation::create();
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_04.jpg");
	this->movingUpAnimation->setDelayPerUnit(0.5f);
	this->movingUpAnimation->setRestoreOriginalFrame(true);
	this->movingUpAnimation->retain();

	this->movingDownAnimation = Animation::create();
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_04.jpg");
	this->movingDownAnimation->setDelayPerUnit(0.5f);
	this->movingDownAnimation->setRestoreOriginalFrame(true);
	this->movingDownAnimation->retain();

	this->movingRightAnimation = Animation::create();
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_04.jpg");
	this->movingRightAnimation->setDelayPerUnit(0.5f);
	this->movingRightAnimation->setRestoreOriginalFrame(true);
	this->movingRightAnimation->retain();

	this->movingUpRightAnimation = Animation::create();
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_04.jpg");
	this->movingUpRightAnimation->setDelayPerUnit(0.5f);
	this->movingUpRightAnimation->setRestoreOriginalFrame(true);
	this->movingUpRightAnimation->retain();

	this->movingDownRightAnimation = Animation::create();
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_04.jpg");
	this->movingDownRightAnimation->setDelayPerUnit(0.5f);
	this->movingDownRightAnimation->setRestoreOriginalFrame(true);
	this->movingDownRightAnimation->retain();

	this->movingLeftAnimation = Animation::create();
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_04.jpg");
	this->movingLeftAnimation->setDelayPerUnit(0.5f);
	this->movingLeftAnimation->setRestoreOriginalFrame(true);
	this->movingLeftAnimation->retain();

	this->movingDownLeftAnimation = Animation::create();
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_04.jpg");
	this->movingDownLeftAnimation->setDelayPerUnit(0.5f);
	this->movingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->movingDownLeftAnimation->retain();

	this->movingUpLeftAnimation = Animation::create();
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_04.jpg");
	this->movingUpLeftAnimation->setDelayPerUnit(0.5f);
	this->movingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->movingUpLeftAnimation->retain();

	this->blowingWindAnimation = Animation::create();
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_01.jpg");
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_02.jpg");
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_03.jpg");
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_04.jpg");
	this->blowingWindAnimation->setDelayPerUnit(0.2f);
	this->blowingWindAnimation->setRestoreOriginalFrame(true);
	this->blowingWindAnimation->retain();


	this->windBulletFlyingAnimation = Animation::create();
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_01.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_02.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_03.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_04.jpg");
	this->windBulletFlyingAnimation->setDelayPerUnit(0.2f);
	this->windBulletFlyingAnimation->setRestoreOriginalFrame(true);
	this->windBulletFlyingAnimation->retain();

}


HeroSprite::~HeroSprite()
{
}


HeroSprite * HeroSprite::create(const std::string &filename){
	HeroSprite *mySprite = new HeroSprite();
	if (mySprite &&mySprite->initWithFile(filename)){
		mySprite->autorelease();
		return mySprite;
	}
	CC_SAFE_DELETE(mySprite);
	return nullptr;
}
void HeroSprite::windAttack(){
	this->stopAllActions();
	this->move();
	this->runAction(Animate::create(this->blowingWindAnimation));
	Sprite * windBullet = Sprite::create();
	windBullet->setPosition(this->getPosition());
	this->getParent()->addChild(windBullet);
	windBullet->runAction(Spawn::create(MoveBy::create(0.4f,Vec2(300,0)),Repeat::create(Animate::create(this->windBulletFlyingAnimation),2),nullptr));
}

//这个move对外开放，主角的普通移动只调用它。为了调试方便，所有细节目前都是public。八方向移动方法此时是public，今后应改为private。
void HeroSprite::move(){
	if (this->directionToMoveRight) {
		moveRight();
	}
	if (this->directionToMoveLeft){
		moveLeft();
	}
	if (this->directionToMoveUp){
		moveUp();
	}
	if (this->directionToMoveDown){
		moveDown();
	}

	if (this->directionToMoveUpRight){
		moveUpRight();
	}
	if (this->directionToMoveUpLeft){
		moveUpLeft();
	}
	if (this->directionToMoveDownRight){
		moveDownRight();
	}
	if (this->directionToMoveDownLeft){
		moveDownLeft();
	}
	if (this->directionToMoveUpRight == false &&
		this->directionToMoveRight == false &&
		this->directionToMoveDownRight == false &&
		this->directionToMoveDown == false &&
		this->directionToMoveDownLeft == false &&
		this->directionToMoveLeft == false &&
		this->directionToMoveUpLeft == false &&
		this->directionToMoveUp == false){
		moveBrake();
	}
}
//moving in 8 directions
void HeroSprite::moveRight(){
	this->stopAllActions();
	//this->runAction(Spawn::create(RepeatForever::create(MoveBy::create(2.0f,Vec2(33,0))),RepeatForever::create(Animate::create(this->movingRightAnimation)),nullptr));不知为何，这行用不了，提示[Action update] override me
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingRightAnimation)));
}
void HeroSprite::moveLeft(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingLeftAnimation)));
}
void HeroSprite::moveUp(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, this->speed_flying_pixel_per_second))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpAnimation)));
}
void HeroSprite::moveDown(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, -this->speed_flying_pixel_per_second))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownAnimation)));
}
void HeroSprite::moveUpRight(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.4142, this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation)));
}
void HeroSprite::moveUpLeft(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.4142, this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpLeftAnimation)));
}
void HeroSprite::moveDownRight(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.4142, -this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation)));
}
void HeroSprite::moveDownLeft(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.4142, -this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownLeftAnimation)));
}


//brakes after moving。虽然暂时没做完，但是一定要做的。这关系到技能流畅度
void HeroSprite::moveRightBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
}
void HeroSprite::moveLeftBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
}
void HeroSprite::moveDownBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
}
void HeroSprite::moveUpBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
}
void HeroSprite::moveBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
}