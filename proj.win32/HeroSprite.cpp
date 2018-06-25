#include "HeroSprite.h"


HeroSprite::HeroSprite()
{
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_00.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_01.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_02.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_03.jpg");
	this->hoveringAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringAnimation->setRestoreOriginalFrame(true);


	//以下是在第3帧和第1帧上加事件的例子，其中回调函数以lambda函数的形式给出
	ValueMap hoveringAnimationFrame03info;
	ValueMap hoveringAnimationFrame01info;
	hoveringAnimationFrame03info["1"] = Value(1);//除了让该info指向一个新地址外没有别的用处
	hoveringAnimationFrame01info["2"] = Value(2);//除了让该info指向一个新地址外没有别的用处
	//log("here three = %s,", hoveringAnimationFrame04info["FrameId"].asString());//不知为什么不能输出string，string会变成？？，只能正确输出数字。

	hoveringAnimation->getFrames().at(3)->setUserInfo(hoveringAnimationFrame03info);
	hoveringAnimation->getFrames().at(1)->setUserInfo(hoveringAnimationFrame01info);



	EventListenerCustom * hoveringAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hoveringAnimationFrame03info, hoveringAnimationFrame01info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		//log("Target %p with data %s , if this frame added 03 = %d. ", userData->target, Value(userData->userInfo).getDescription().c_str(), *userData->userInfo == hoveringAnimationFrame03info);
		//log("Value(userData->userInfo).asString = %s",Value(userData->userInfo).asString());
		if (*userData->userInfo == hoveringAnimationFrame03info){
			this->setPositionY(this->getPositionY() + 3);
		}
		if (*userData->userInfo == hoveringAnimationFrame01info){
			this->setPositionY(this->getPositionY() - 3);
		}
	
	});

	//将该事件添加到事件分发器
	_eventDispatcher->addEventListenerWithFixedPriority(hoveringAnimationFrameEventListener, -1);
	//帧事件例子结束。


	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
	this->hoveringAnimation->retain();

	


	//Moving events won't need frame events. However, slight up-down swings during horizontal flights would be welcome.
	this->movingUpAnimation = Animation::create();
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpAnimation->setRestoreOriginalFrame(true);
	this->movingUpAnimation->retain();

	this->movingDownAnimation = Animation::create();
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownAnimation->setRestoreOriginalFrame(true);
	this->movingDownAnimation->retain();

	this->movingRightAnimation = Animation::create();
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingRightAnimation->setRestoreOriginalFrame(true);
	this->movingRightAnimation->retain();

	this->movingUpRightAnimation = Animation::create();
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpRightAnimation->setRestoreOriginalFrame(true);
	this->movingUpRightAnimation->retain();

	this->movingDownRightAnimation = Animation::create();
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownRightAnimation->setRestoreOriginalFrame(true);
	this->movingDownRightAnimation->retain();

	this->movingLeftAnimation = Animation::create();
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingLeftAnimation->setRestoreOriginalFrame(true);
	this->movingLeftAnimation->retain();

	this->movingDownLeftAnimation = Animation::create();
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->movingDownLeftAnimation->retain();

	this->movingUpLeftAnimation = Animation::create();
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->movingUpLeftAnimation->retain();

	this->blowingWindAnimation = Animation::create();
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_00.jpg");
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_01.jpg");
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_02.jpg");
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_03.jpg");
	this->blowingWindAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->blowingWindAnimation->setRestoreOriginalFrame(true);
	this->blowingWindAnimation->retain();


	this->windBulletFlyingAnimation = Animation::create();
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_00.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_01.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_02.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_03.jpg");
	this->windBulletFlyingAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->windBulletFlyingAnimation->setRestoreOriginalFrame(true);
	this->windBulletFlyingAnimation->retain();


	//dashing animations would need frame events.
	this->dashingRightAnimation = Animation::create();
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_00.jpg");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_01.jpg");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_02.jpg");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_03.jpg");
	this->dashingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingRightAnimation->setRestoreOriginalFrame(true);
	this->dashingRightAnimation->retain();

	
	ValueMap dashingRightFrame00Info;
	ValueMap dashingRightFrame02Info;

	dashingRightFrame00Info["3"] = Value(3);
	dashingRightFrame02Info["4"] = Value(4);

	this->dashingRightAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingRightAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);

	EventListenerCustom * dashingRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dashingRightFrame00Info, dashingRightFrame02Info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dashingRightFrame00Info){
			this->windAttackable = false;
			this->moveable = false;
			this->dashable = false;
		}
		if (*userData->userInfo == dashingRightFrame02Info){
			this->windAttackable = true;
			this->moveable = true;
			this->dashable = true;
			if (this->directionToMoveUpRight  ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft||
				this->directionToMoveUp){
				this->move();
			}
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dashingRightAnimationFrameEventListener, -1);
	
	this->dashingDownRightAnimation = Animation::create();
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_00.jpg");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_01.jpg");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_02.jpg");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_03.jpg");
	this->dashingDownRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingDownRightAnimation->setRestoreOriginalFrame(true);
	this->dashingDownRightAnimation->retain();

	ValueMap dashingDownRightFrame00Info;
	ValueMap dashingDownRightFrame02Info;

	dashingDownRightFrame00Info["5"] = Value(3);
	dashingDownRightFrame02Info["6"] = Value(4);

	this->dashingDownRightAnimation->getFrames().at(0)->setUserInfo(dashingDownRightFrame00Info);
	this->dashingDownRightAnimation->getFrames().at(2)->setUserInfo(dashingDownRightFrame02Info);

	EventListenerCustom * dashingDownRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dashingDownRightFrame00Info, dashingDownRightFrame02Info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dashingDownRightFrame00Info){
			this->windAttackable = false;
			this->moveable = false;
			this->dashable = false;
		}
		if (*userData->userInfo == dashingDownRightFrame02Info){
			this->windAttackable = true;
			this->moveable = true;
			this->dashable = true;
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dashingDownRightAnimationFrameEventListener, -1);


	this->dashingUpRightAnimation = Animation::create();
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_00.jpg");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_01.jpg");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_02.jpg");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_03.jpg");
	this->dashingUpRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingUpRightAnimation->setRestoreOriginalFrame(true);
	this->dashingUpRightAnimation->retain();

	ValueMap dashingUpRightFrame00info;
	ValueMap dashingUpRightFrame02info;

	dashingUpRightFrame00info["7"] = Value(7);
	dashingUpRightFrame02info["8"] = Value(8);

	dashingUpRightAnimation->getFrames().at(0)->setUserInfo(dashingUpRightFrame00info);
	dashingUpRightAnimation->getFrames().at(2)->setUserInfo(dashingUpRightFrame02info);


	EventListenerCustom * dashingUpRightAnimationFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, dashingUpRightFrame00info, dashingUpRightFrame02info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dashingUpRightFrame00info){
			this->windAttackable = false;
			this->moveable = false;
			this->dashable = false;
		}
		if (*userData->userInfo == dashingUpRightFrame02info){
			this->windAttackable = true;
			this->moveable = true;
			this->dashable = true;
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dashingUpRightAnimationFrameEventListener, -1);



	this->dashingLeftAnimation = Animation::create();
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_00.jpg");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_01.jpg");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_02.jpg");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_03.jpg");
	this->dashingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingLeftAnimation->retain();

	ValueMap dashingLeftFrame00Info;
	ValueMap dashingLeftFrame02Info;

	dashingLeftFrame00Info["9"] = Value(9);
	dashingLeftFrame02Info["10"] = Value(10);

	this->dashingLeftAnimation->getFrames().at(0)->setUserInfo(dashingLeftFrame00Info);
	this->dashingLeftAnimation->getFrames().at(2)->setUserInfo(dashingLeftFrame02Info);

	EventListenerCustom * dashingLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dashingLeftFrame00Info, dashingLeftFrame02Info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dashingLeftFrame00Info){
			this->windAttackable = false;
			this->moveable = false;
			this->dashable = false;
		}
		if (*userData->userInfo == dashingLeftFrame02Info){
			this->windAttackable = true;
			this->moveable = true;
			this->dashable = true;
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dashingLeftAnimationFrameEventListener, -1);


	this->dashingUpLeftAnimation = Animation::create();
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_00.jpg");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_01.jpg");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_02.jpg");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_03.jpg");
	this->dashingUpLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingUpLeftAnimation->retain();

	ValueMap dashingUpLeftFrame00Info;
	ValueMap dashingUpLeftFrame02Info;

	dashingUpLeftFrame00Info["11"] = Value(11);
	dashingUpLeftFrame02Info["12"] = Value(12);

	this->dashingUpLeftAnimation->getFrames().at(0)->setUserInfo(dashingUpLeftFrame00Info);
	this->dashingUpLeftAnimation->getFrames().at(2)->setUserInfo(dashingUpLeftFrame02Info);

	EventListenerCustom * dashingUpLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dashingUpLeftFrame00Info, dashingUpLeftFrame02Info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dashingUpLeftFrame00Info){
			this->windAttackable = false;
			this->moveable = false;
			this->dashable = false;
		}
		if (*userData->userInfo == dashingUpLeftFrame02Info){
			this->windAttackable = true;
			this->moveable = true;
			this->dashable = true;
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dashingUpLeftAnimationFrameEventListener, -1);

	this->dashingDownLeftAnimation = Animation::create();
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_00.jpg");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_03.jpg");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_03.jpg");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_03.jpg");
	this->dashingDownLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingDownLeftAnimation->retain();

	ValueMap dashingDownLeftFrame00Info;
	ValueMap dashingDownLeftFrame02Info;

	dashingDownLeftFrame00Info["13"] = Value(13);
	dashingDownLeftFrame02Info["14"] = Value(14);

	this->dashingDownLeftAnimation->getFrames().at(0)->setUserInfo(dashingDownLeftFrame00Info);
	this->dashingDownLeftAnimation->getFrames().at(2)->setUserInfo(dashingDownLeftFrame02Info);

	EventListenerCustom * dashingDownLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dashingDownLeftFrame00Info, dashingDownLeftFrame02Info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dashingDownLeftFrame00Info){
			this->windAttackable = false;
			this->moveable = false;
			this->dashable = false;
		}
		if (*userData->userInfo == dashingDownLeftFrame02Info){
			this->windAttackable = true;
			this->moveable = true;
			this->dashable = true;
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dashingDownLeftAnimationFrameEventListener, -1);



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
	if (this->windAttackable){
		this->stopAllActions();
		this->move();
		this->runAction(Animate::create(this->blowingWindAnimation));
		Sprite * windBullet = Sprite::create();
		windBullet->setPosition(this->getPosition());
		this->getParent()->addChild(windBullet);
		windBullet->runAction(Spawn::create(MoveBy::create(0.4f, Vec2(300, 0)), Repeat::create(Animate::create(this->windBulletFlyingAnimation), 2), nullptr));
	}
}

//这个move对外开放，主角的普通移动只调用它。为了调试方便，所有细节目前都是public。八方向移动方法此时是public，今后应改为private。
//在此验证了主角在调用move方法时的可移动性。
//one more 废话：move是说方向按钮造成的位移，dash是说冲刺技能造成的位移。
void HeroSprite::move(){
	if (this->moveable){
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
}




void HeroSprite::dash(){
	if (this->dashable){
		if (this->directionToMoveRight){
			dashRight();
		}
		else if (this->directionToMoveDown){
			dashDown();
		}
		else if (this->directionToMoveDownLeft){
			dashDownLeft();
		}
		else if (this->directionToMoveDownRight){
			dashDownRight();
		}
		else if (this->directionToMoveLeft){
			dashLeft();
		}
		else if(this->directionToMoveUp){
			dashUp();
		}
		else if (this->directionToMoveUpLeft){
			dashUpLeft();
		}
		else if (this->directionToMoveUpRight){
			dashUpRight();
		}
		if (this->directionToMoveDown == false &&
			this->directionToMoveUp == false &&
			this->directionToMoveRight == false &&
			this->directionToMoveLeft == false &&
			this->directionToMoveDownLeft == false &&
			this->directionToMoveDownRight == false &&
			this->directionToMoveUpLeft == false &&
			this->directionToMoveUpRight == false){

			if (this->facingRight){
				dashRight();
			}
			else if (this->facingLeft){
				dashLeft();
			}
		}

	}
}


//dashing in 8 directions.
void HeroSprite::dashUp(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(0, this->DISTANCE_AIR_DASHING)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(0, this->DISTANCE_AIR_DASHING_BRAKING)), nullptr));
	if (this->facingRight){
		this->runAction(Animate::create(this->dashingUpRightAnimation));
	}
	else if(this->facingLeft){
		this->runAction(Animate::create(this->dashingUpLeftAnimation));
	}
}
void HeroSprite::dashDown(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(0, -this->DISTANCE_AIR_DASHING)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(0, -this->DISTANCE_AIR_DASHING_BRAKING)), nullptr));
	if (this->facingRight){
		this->runAction(Animate::create(this->dashingDownRightAnimation));
	}
	else if(this->facingLeft){
		this->runAction(Animate::create(this->dashingDownLeftAnimation));
	}
}
void HeroSprite::dashLeft(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(-this->DISTANCE_AIR_DASHING, 0)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(-this->DISTANCE_AIR_DASHING_BRAKING, 0)), nullptr));
	this->runAction(Animate::create(this->dashingLeftAnimation));
}
void HeroSprite::dashRight(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING, 0)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING, 0)), nullptr));
	this->runAction(Animate::create(this->dashingRightAnimation));
}
void HeroSprite::dashUpRight(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING / 1.414, this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING / 1.414, this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingUpRightAnimation));
}
void HeroSprite::dashUpLeft(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(-this->DISTANCE_AIR_DASHING / 1.414, this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(-this->DISTANCE_AIR_DASHING_BRAKING / 1.414, this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingUpLeftAnimation));
}
void HeroSprite::dashDownRight(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING / 1.414, -this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING / 1.414, -this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingDownRightAnimation));
}
void HeroSprite::dashDownLeft(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(-this->DISTANCE_AIR_DASHING / 1.414, -this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(-this->DISTANCE_AIR_DASHING_BRAKING / 1.414, -this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingDownLeftAnimation));
}


//moving in 8 directions
//仅仅将向右移动和播放移动动画一起run一下，没做是否可移动的验证。剩下的七个动画亦然。以后要加入扑打翅膀的声音
void HeroSprite::moveRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();

	//this->runAction(Spawn::create(RepeatForever::create(MoveBy::create(2.0f,Vec2(33,0))),RepeatForever::create(Animate::create(this->movingRightAnimation)),nullptr));//不知为何，这行用不了，提示[Action update] override me
	/*
	Sequence和Spawn就是不能和RepeatForever一起用的。理由见源码，RepeatForever的interval = 0，不能做除数，跳入另一流程。
	*/
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingRightAnimation)));
}
void HeroSprite::moveLeft(){
	this->facingRight = false;
	this->facingLeft = true;
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
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.4142, this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation)));
}
void HeroSprite::moveUpLeft(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.4142, this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpLeftAnimation)));
}
void HeroSprite::moveDownRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.4142, -this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation)));
}
void HeroSprite::moveDownLeft(){
	this->facingRight = false;
	this->facingLeft = true;
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